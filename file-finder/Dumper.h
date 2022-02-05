//
//  Dumper.h
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#ifndef Dumper_h
#define Dumper_h

#include <vector>

#include "Container.h"
#include "Directory.h"

class Dumper
{
    bool isComplete(const std::vector<Directory *> &);
public:
    int interval;
    
    Dumper(int);
    void dump(Container *, const std::vector<Directory *> &);
};


#endif /* Dumper_h */
