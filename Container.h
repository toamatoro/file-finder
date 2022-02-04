//
//  Container.h
//  file-finder
//
//  Created by Jonathan Lausch on 2/3/22.
//

#ifndef Container_h
#define Container_h

#include <vector>

class Container
{
    std::vector<std::string> objects;
    
    unsigned long capacity;
    bool isFull();
public:
    Container(unsigned long);
    ~Container();
    
    void dump();
    void addItem(std::string);
    
    std::mutex mutex; //why is public
};

#endif /* Container_h */
