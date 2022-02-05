//
//  main.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/3/22.
//

#include <iostream>
#include <thread>
#include <vector>

#include "Dumper.h"
#include "Command.h"
#include "Directory.h"
#include "Container.h"


int main(int argc, const char * argv[])
{
    std::vector<Directory *> Dirs;
    
    if(argc <= 2)
    {
        printf("Usage: ./file-finder <dir> <substring1>[<substring2> [<substring3>]...]\n");
        return 1;
    }
    else
    {
        //CHECK THAT THE PATH EXISTS
        
        for(int i = 2; i < argc; i++)
        {
            Dirs.push_back(new Directory(argv[1], argv[i]));
        }
        
    }
    
    Container C(23);
    
    Dumper * D = new Dumper(5000);
    
    Command * Cmd = new Command();
    
    std::vector<std::thread> t(argc); // argc -2, +1 for cmd input, +1 for dumper
    
    //Create Command input thread
    t[t.size()-1] = std::thread(&Command::getInput, Cmd, &C, Dirs);
    //Create Dumper thread
    t[t.size()-2] = std::thread(&Dumper::dump, D, &C, Dirs);
    
    //Create traversal threads
    for(int i = 0; i < t.size()-2; i++)
    {
        t[i] = std::thread(&Directory::traverse, Dirs[i], &C);
    }
    
    for(int i = 0; i < t.size(); i++)
    {
        if(i == t.size() - 1)
        {
            //If this point is reached, all threads except command input have completed
            std::cout << "Traversal complete, press Enter to exit.\n";
        }
        t[i].join();
    }
    
    return 0;
}
