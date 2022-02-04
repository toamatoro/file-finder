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
    this->mutex.lock();
    
    if(!this->objects.empty())
    {
        this->objects.clear();
        std::cout << "Container::~Container - Shared Container contents cleared.\n";
    }
    else
    {
        std::cout << "Container::~Container - Attempted to clear Shared Container, already empty.\n";
    }
    
    this->mutex.unlock();
}

/*
 
 Container::dump - not thread safe, caller must ensure container is available
 
 */
void Container::dump()
{
    for(int i = 0; i < this->objects.size(); i++)
    {
        std::cout << objects[i] << std::endl;
    }
    
    if(!this->objects.empty())
    {
        std::cout << "\nContainer::dump - Shared Container contents cleared.\n\n";
        this->objects.clear();
    }
}

/*
 
 Container::addItem - return status if failing, but space guaranteed
 
 */
void Container::addItem(std::string item)
{
    this->mutex.lock(); //blocks if unavailable
    
    if(this->isFull())
    {
        this->dump();
    }
    
    this->objects.push_back(item);
    
    this->mutex.unlock();
}

bool Container::isFull()
{
    if(this->objects.size() == this->capacity)
        return true;
    else
        return false;
}
