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

Dumper::Dumper(int interval)
{
    this->interval = interval;
}

void Dumper::dump(Container * C)
{
    std::cout << "Dumper::dump - Starting Dump Thread.\n";
    while(1 < 2)
    {
        std::cout << "hello\n";
        C->mutex.lock();
        if(!C->objects.empty())
        {
            for(int i = 0; i < C->objects.size(); i++)
            {
                std::cout << C->objects[i] << std::endl;
            }
    
            std::cout << "\nContainer::dump - Shared Container contents cleared.\n\n";
            C->objects.clear();
        }
        C->mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }
}
