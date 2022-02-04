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
    if(!this->objects.empty())
        this->objects.clear();
}

void Container::dump()
{
    std::cout << "DUMP" << std::endl;
    
    //this->mutex.lock();
    //TRY LOCK HERE
    
    for(int i = 0; i < this->objects.size(); i++)
    {
        std::cout << objects[i] << std::endl;
    }
    
    if(!this->objects.empty())
        this->objects.clear();
    
    //this->mutex.unlock();
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
