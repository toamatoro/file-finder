//
//  Dumper.h
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#ifndef Dumper_h
#define Dumper_h

#include "Container.h"

class Dumper
{
public:
    int interval;
    
    Dumper(int);
    void dump(Container *);
};


#endif /* Dumper_h */
