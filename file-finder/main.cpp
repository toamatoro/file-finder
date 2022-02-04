//
//  main.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/3/22.
//

#include <iostream>
#include <pthread.h>

#include "Directory.h"
#include "Container.h"

int main(int argc, const char * argv[])
{
    Directory * Dir;
    //std::vector<std::string> substrs;
    
    if(argc <= 2)
    {
        printf("Usage: ./file-finder <dir> <substring1>[<substring2> [<substring3>]...]\n");
    }
    else
    {
        Dir = new Directory(argv[1]);
        
        for(int i = 2; i < argc; i++)
        {
            Dir->addSubStr(argv[i]);
        }
        
    }
    
    
    //one thread to get input commands
    
    //traverse dir
    
    //n search threads for n args
    
    
    
    return 0;
}
