//
//  Command.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#include <iostream>

#include "Command.h"

void Command::getInput(Container * C, const std::vector<Directory *> & D)
{
    std::string input;
    
    while((input != "exit") && !(this->isComplete(D)))
    {
        std::cout << "file-finder % ";
        getline(std::cin, input);
        
        if(input.length() == 0)
        {
            continue;
        }
        else if(input == "dump")
        {
            this->dump(C);
        }
        else if(input != "exit")
        {
            std::cout << "Valid commands are 'dump' or 'exit'." << '\n';
        }
    }
    
    this->exit(C, D);
    
}

void Command::dump(Container * C)
{
    C->mutex.lock();
    //C->dump();
    C->mutex.unlock();
}

void Command::exit(Container * C, const std::vector<Directory *> & D)
{
    //lock buffer
    C->mutex.lock();
    //stop directory traversals
    for(int i = 0; i < D.size(); i++)
    {
        D[i]->interrupt();
    }
    
    //dump buffer / free everything
    C->dump();
    C->mutex.unlock();
    //quit
}

bool Command::isComplete(const std::vector<Directory *> & D)
{
    for(int i = 0; i < D.size(); i++)
    {
        if(!D[i]->complete)
            return false;
    }
    
    return true;
}
