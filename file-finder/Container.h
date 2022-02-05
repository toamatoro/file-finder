//
//  Container.h
//  file-finder
//
//  Created by Jonathan Lausch on 2/3/22.
//

#ifndef Container_h
#define Container_h

#include <vector>
#include <mutex>

class Container
{
    unsigned long capacity;
    bool isFull();
public:
    std::vector<std::string> objects;
    
    Container(unsigned long);
    ~Container();
    
    void dump();
    void addItem(std::string);
    
    std::mutex m;
};

#endif /* Container_h */