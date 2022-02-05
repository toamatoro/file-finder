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
#include "Dumper.h"

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
    
    Dumper * D = new Dumper(5000);
    
    Command * Cmd = new Command();


    /*if(Dir.getThreads() < 1) //SHOULD NOT HAPPEN
        return 1;*/
    
    std::vector<std::thread> t(argc); // argc -2 +1 +1
    
    //Thread 0 is thread to get commands
    t[t.size()-1] = std::thread(&Command::getInput, Cmd, &C);
    t[t.size()-2] = std::thread(&Dumper::dump, D, &C); //send directory list as input
    
    for(int i = 0; i < t.size()-2; i++)
    {
        t[i] = std::thread(&Directory::traverse, Dirs[i], Dirs[i].getTarget(), &C); //originall i-1
    }
    
    //NEED TO CHECK WHEN ALL ARE COMPLETE
    
    for(int i = 0; i < t.size(); i++)
    {
        t[i].join();
    }
    
    //C.dump();
    
    return 0;
}
