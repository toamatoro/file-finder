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

public:
    bool complete;
    
    Directory(std::string, std::string);
    
    void interrupt();
    bool isComplete();
    std::string getTarget();
    void traverse(std::string, Container *);
};

#endif /* Directory_h */
