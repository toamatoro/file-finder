//
//  main.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/3/22.
//

#include <iostream>
#include <thread>
#include <vector>

#include "Directory.h"
#include "Container.h"
#include "Command.h"

int main(int argc, const char * argv[])
{
    std::vector<Directory> Dirs;
    //std::vector<std::string> substrs;
    
    if(argc <= 2)
    {
        printf("Usage: ./file-finder <dir> <substring1>[<substring2> [<substring3>]...]\n");
        
        return 1;
    }
    else
    {
        //Dir = new Directory(argv[1], argc - 2);
        
        for(int i = 2; i < argc; i++)
        {
            //Dir->addSubStr(argv[i]);
            Dirs.push_back(Directory(argv[1], argv[i]));
        }
        
    }
    
    Container C(23);
    
    Command * Cmd = new Command();

    /*if(Dir.getThreads() < 1) //SHOULD NOT HAPPEN
        return 1;*/
    
    std::vector<std::thread> t(argc - 1); // argc -2 +1
    
    //Thread 0 is thread to get commands
    t[0] = std::thread(&Command::getInput, Cmd, &C);
    
    for(int i = 1; i < t.size(); i++)
    {
        t[i] = std::thread(&Directory::traverse, Dirs[i-1], Dirs[i-1].getTarget(), &C); //originall i-1
    }
    
    //NEED TO CHECK WHEN ALL ARE COMPLETE
    
    for(int i = 0; i < t.size(); i++)
    {
        t[i].join();
    }
    
    C.dump();
    
    return 0;
}
