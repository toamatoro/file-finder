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
    const std::lock_guard<std::mutex> lock(this->m);
    
    if(!this->objects.empty())
    {
        this->objects.clear();
        std::cout << "Container::~Container - Shared Container contents cleared.\n";
    }
    else
    {
        std::cout << "Container::~Container - Attempted to clear Shared Container, already empty.\n";
    }
    
    this->cond.notify_all();
}

/*
 
 Container::addItem
 
 Input: item to be added to container
 Purpose: add Items to Shared container in thread safe manner
 
 */
void Container::addItem(std::string item)
{
    std::unique_lock<std::mutex> lk(this->m);
    if(this->isFull())
    {
        std::cout << "Container::addItem - Container is full.\n";
        
        this->cond.wait(lk);
    
    }
    
    this->objects.push_back(item);
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
 
 */
void Container::dump()
{
    const std::lock_guard<std::mutex> lock(this->m);
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
    
    //NEW: Notify sleeping threads
    this->cond.notify_all();
}
