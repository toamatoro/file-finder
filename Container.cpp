//
//  Container.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#include <iostream>
#include "Container.h"

Container::Container(unsigned long capacity)
{
    this->capacity = capacity;
}

Container::~Container()
{
    this->objects.clear();
}

bool Container::dump()
{
    
}

bool Container::addItem(std::string item)
{
    
}
