//
//  main.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/3/22.
//

#include <iostream>
#include <fstream>
#include <pthread.h>
#include <vector>

int main(int argc, const char * argv[])
{
    std::filesystem::path dir;
    std::vector<std::string> substrs;
    unsigned long threads;
    
    if(argc <= 2)
    {
        printf("Usage: ./file-finder <dir> <substring1>[<substring2> [<substring3>]...]\n");
    }
    else
    {
        dir = argv[1];
        
        for(int i = 2; i < argc; i++)
        {
            substrs.push_back(argv[i]);
        }
        
        threads = substrs.size();
    }
    
    
    //one thread to get input commands
    
    //traverse dir
    
    //n search threads for n args
    
    
    
    return 0;
}
