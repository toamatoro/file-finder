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
#include "Directory.h"

class Directory
{
    std::string path;
    std::string target;

public:
    bool complete;
    Directory(std::string, std::string);
    //~Directory();
    
    void traverse(std::string, Container *); //make sure these methods pass
    std::string getTarget();
    bool isComplete();
    void interrupt();
};

#endif /* Directory_h */
