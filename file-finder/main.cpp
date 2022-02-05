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
    std::vector<Directory *> Dirs;
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
            
            Dirs.push_back(new Directory(argv[1], argv[i]));
        }
        
    }
    
    Container C(23);
    
    Dumper * D = new Dumper(5000);
    
    Command * Cmd = new Command();
    
    std::vector<std::thread> t(argc); // argc -2 +1 +1
    
    //Thread 0 is thread to get commands
    t[t.size()-1] = std::thread(&Command::getInput, Cmd, &C, Dirs);
    
    //base off of https://stackoverflow.com/questions/6171132/non-blocking-console-input-c
    
    /*std::chrono::seconds timeout(5);
    std::cout << "Do you even lift?" << std::endl << std::flush;
    std::string answer = "exit"; //default to exit
    std::future<std::string> future = std::async(&this->getInput());
    if (future.wait_for(timeout) == std::future_status::ready)
        answer = future.get();
    */
    
    
    
    
    
    
    t[t.size()-2] = std::thread(&Dumper::dump, D, &C, Dirs); //send directory list as input
    
    for(int i = 0; i < t.size()-2; i++)
    {
        t[i] = std::thread(&Directory::traverse, Dirs[i], Dirs[i]->getTarget(), &C); //originall i-1
    }
    
    //NEED TO CHECK WHEN ALL ARE COMPLETE
    
    for(int i = 0; i < t.size(); i++)
    {
        if(i == t.size() - 1)
        {
            std::cout << "Traversal complete, press Enter to exit.\n";
        }
        t[i].join();
    }
    
    //C.dump();
    
    return 0;
}
