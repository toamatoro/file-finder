//
//  Container.h
//  file-finder
//
//  Created by Jonathan Lausch on 2/3/22.
//

#ifndef Container_h
#define Container_h

class Container
{
    std::mutex lock;
    std::vector<std::string> objects;
public:
    unsigned long capacity;
    
    Container(unsigned long);
    ~Container();
    
    bool dump();
    bool addItem(std::string);
};

#endif /* Container_h */
