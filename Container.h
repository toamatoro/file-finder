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
    unsigned long capacity;
    bool isFull();
public:
    std::vector<std::string> objects;
    
    Container(unsigned long);
    ~Container();
    
    void dumper(int);
    void addItem(std::string);
    
    std::mutex mutex; //why is public
};

#endif /* Container_h */
