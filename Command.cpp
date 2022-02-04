//
//  Command.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#include <iostream>

#include "Command.h"
#include "Container.h"

/*Command::Command()
{
    int x = 1;
    std::cout << x;
}*/

void Command::getInput(Container * C)
{
    std::string input;
    
    while(input != "exit")
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
    
    //ensure everything is unlocked/freed here
    
}

void Command::dump(Container * C)
{
    C->mutex.lock();
    C->dump();
    C->mutex.unlock();
}

void Command::exit(Container * C)
{
    
}
