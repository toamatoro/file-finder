//
//  main.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/3/22.
//

#include <iostream>
#include <thread>

#include "Directory.h"
#include "Container.h"
#include "Command.h"

int main(int argc, const char * argv[])
{
    Directory * Dir;
    //std::vector<std::string> substrs;
    
    if(argc <= 2)
    {
        printf("Usage: ./file-finder <dir> <substring1>[<substring2> [<substring3>]...]\n");
        
        return 1;
    }
    else
    {
        Dir = new Directory(argv[1]);
        
        for(int i = 2; i < argc; i++)
        {
            Dir->addSubStr(argv[i]);
        }
        
    }
    
    Container C(23);
    
    Command * Cmd = new Command();
    /*
    //one thread to get input commands //"CMD Object"
    Cmd.getInput(&C);
    
    //traverse dir
    
    Dir->traverse(argv[2], &C);
    
    */
    //std::vector<std::thread> t(Dir);
    
    
    
    std::thread th1(&Command::getInput, Cmd, &C);
    
    //n search threads for n args
    
    th1.join();
    
    return 0;
}
