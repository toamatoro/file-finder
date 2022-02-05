//
//  Dumper.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#include <iostream>
#include <thread>
#include <chrono>

#include "Dumper.h"

/*
 
 Dumper::Dumper
 
 Inputs: Interval to dump contents of Shared Container (in milliseconds)
 Purpose: Dumper Object Constructor
 
 */
Dumper::Dumper(int interval)
{
    this->interval = interval;
}

void Dumper::dump(Container * C, const std::vector<Directory *> & D)
{
    std::cout << "Dumper::dump - Starting Dump Thread.\n";
    while(1 < 2)
    {
        if(this->isComplete(D))
        {
            break;
        }
        
        std::cout << "hello\n";
        C->mutex.lock();
        C->dump();
        C->mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }
    
    //dump remaining Container contents
    C->mutex.lock();
    C->dump();
    C->mutex.unlock();
}

/*
 
 Dumper::isComplete
 
 Inputs: List of Directory Objects
 Outputs: true if all traversals are complete
 
 Purpose: Check all concurrent traversal processes for completion status.
 
 */
bool Dumper::isComplete(const std::vector<Directory *> & D)
{
    for(int i = 0; i < D.size(); i++)
    {
        if(!D[i]->complete) //how to access
            return false;
    }
    
    return true;
}
