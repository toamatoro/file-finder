//
//  Command.h
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#ifndef Command_h
#define Command_h

#include "Container.h"
#include "Directory.h"

class Command
{
    std::string cmd;
    void dump(Container *);
    void exit(Container *, const std::vector<Directory *> &);
    bool isComplete(const std::vector<Directory *> &);
public:
    std::string input;
    
    void getInput(Container *, const std::vector<Directory *> &);
};

#endif /* Command_h */

