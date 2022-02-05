//
//  Container.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#include <iostream>
#include "Container.h"

#include <chrono>
#include <thread>

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
 
 Container::addItem - return status if failing, but space guaranteed
 
 */
void Container::addItem(std::string item)
{
    while(this->isFull())
    {
        std::cout << "full\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //change for speedup
    }
    
    this->mutex.lock();
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

void Container::dump()
{
    if(!this->objects.empty())
    {
        for(int i = 0; i < this->objects.size(); i++)
        {
            std::cout << this->objects[i] << std::endl;
        }

        std::cout << "\nContainer::dump - Shared Container contents cleared.\n\n";
        this->objects.clear();
    }
    else
    {
        std::cout << "\nContainer::dump - Container empty.\n\n";
    }
}
