//
//  Command.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#include <stdio.h>

#include "Command.h"
#include "Container.h"

Command::Command()
{
    int x = x+1;
    std::cout << x;
}

void Command::getInput(Container *)
{
    std::string input;
    
    while(input != "exit")
    {
        std::cout << "file-finder % ";
        std::cin >> input;
        
        if(input == dump)
        {
            C->dump();
        }
    }
    
    C->~Container();
    
    return 0;
}
