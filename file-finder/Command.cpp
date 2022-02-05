//
//  Command.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#include <iostream>

#include "Command.h"

/*
 
 Command::getInput
 
 Inputs: Shared container, list of Directory objects
 Outputs: none
 
 Purpose: Receive user input during directory traversals
 
 */
void Command::getInput(Container * C, const std::vector<Directory *> & D)
{
    std::string input;
    
    while((input != "exit") && !(this->isComplete(D)))
    {
        getline(std::cin, input);
        
        if(input.length() == 0)
        {
            continue;
        }
        else if(input == "dump")
        {
            C->mutex.lock();
            C->dump();
            C->mutex.unlock();
        }
        else if(input != "exit")
        {
            std::cout << "Valid commands are 'dump' or 'exit'." << '\n';
        }
    }
    
    this->exit(C, D);
}

/*
 
 Command::exit
 
 Inputs: Shared Container, List of Directory Objects
 Outputs: None
 
 Purpose: When traversals are complete, or exit command called, this method will
 initiate the cleanup process.
 
 */
void Command::exit(Container * C, const std::vector<Directory *> & D)
{
    C->mutex.lock();
    
    //stop directory traversals
    for(int i = 0; i < D.size(); i++)
    {
        D[i]->interrupt();
    }
    
    //dump buffer / free everything
    C->dump();
    C->mutex.unlock();
}

/*
 
 Command::isComplete
 
 Inputs: List of Directory Objects
 Outputs: true if all traversals are complete
 
 Purpose: Check all concurrent traversal processes for completion status.
 
 */
bool Command::isComplete(const std::vector<Directory *> & D)
{
    for(int i = 0; i < D.size(); i++)
    {
        if(!D[i]->complete)
            return false;
    }
    
    return true;
}
