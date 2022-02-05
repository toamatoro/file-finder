//
//  Container.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#include <iostream>
#include <chrono>
#include <thread>

#include "Container.h"

/*
 
 Container::Container
 
 Inputs: capacity - number of path items the container can hold
 Purpose: Container Constructor
 
 */
Container::Container(unsigned long capacity)
{
    this->capacity = capacity;
}

/*
 
 Container::~Container
 
 Purpose: Clean up Container Objects when descoped (Destructor)
 
 */
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
 
 Container::addItem
 
 Input: item to be added to container
 Purpose: add Items to Shared container in thread safe manner
 
 */
void Container::addItem(std::string item)
{
    while(this->isFull())
    {
        std::cout << "Container::addItem - Container is full, waiting for space.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //change for speedup
    }
    
    this->mutex.lock();
    this->objects.push_back(item);
    this->mutex.unlock();
}

/*
 
 Container::isFull
 
 Outputs: true if Shared Container is full, false if not full
 Purpose: determine if space is available in the Shared Container
 
 */
bool Container::isFull()
{
    if(this->objects.size() == this->capacity)
        return true;
    else
        return false;
}

/*
 
 Container::dump
 
 Purpose: print all contents of Shared Container to console
 
 NOTE: THIS METHOD IS NOT THREAD SAFE, CALLER MUST CHECK CONTAINER AVAILABILITY
 
 */
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
