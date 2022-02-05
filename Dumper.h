//
//  Dumper.h
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#ifndef Dumper_h
#define Dumper_h

#include "Container.h"
#include "Directory.h"
#include <vector>

class Dumper
{
    bool isComplete(std::vector<Directory> *);
public:
    int interval;
    
    Dumper(int);
    void dump(Container *, std::vector<Directory> *);
};


#endif /* Dumper_h */
