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
    void send();
public:
    //Command();
    //~Command();
    
    int start(Container *);
};

#endif /* Command_h */
