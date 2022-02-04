//
//  Command.h
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#ifndef Command_h
#define Command_h

#include "Container.h"

class Command
{
    std::string cmd;
    void dump(Container *);
    void exit(Container *);
public:
    //Command();
    //~Command();
    
    void getInput(Container *);
};

#endif /* Command_h */

