//
//  Directory.h
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#ifndef Directory_h
#define Directory_h

#include <vector>
#include "Container.h"

class Directory
{
    std::string path;
    std::string target;
    
    //int n_threads;
public:
    Directory(std::string, std::string);
    //~Directory();
    
    void traverse(std::string, Container *); //make sure these methods pass
    //void addSubStr(std::string);
    std::string getTarget();
};

#endif /* Directory_h */
