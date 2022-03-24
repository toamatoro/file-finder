//
//  Directory.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#include <iostream>
#include <filesystem>
#include <thread>

#include "Directory.h"

/*
 
 Directory::Directory
 
 Inputs: path to traverse, target substring to search for
 Purpose: Create a Directory object to search for a target substring within the given path.
 
 */
Directory::Directory(std::string path, std::string target)
{
    this->path = path;
    this->target = target;
    this->complete = false;
}

/*
 
 Directory::traverse
 
 Inputs: Shared Container
 Purpose: traverse the directory and find entries with target substring
 
 */
void Directory::traverse(Container * buffer)
{
    const std::filesystem::path dir{this->path};
    
    for(auto &a_entry : std::filesystem::recursive_directory_iterator{dir})
    {
        if(this->complete) //case when interrupted by external cmd
        {
            break;
        }
        else
        {
            std::string s_entry = a_entry.path();
        
            if(s_entry.find(this->target, 0) != std::string::npos)
            {
                // to slow down access for testing
                int r = rand() % 100;
                std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::milliseconds(r));
                buffer->addItem(s_entry);
            }
        }
    }
    
    this->complete = true;
}

/*
 
 Directory::isComplete
 Purpose: return status of Directory Object's traversal
 
 */
bool Directory::isComplete()
{
    return this->complete;
}

/*
 
 Directory::interrupt
 
 Purpose: when exit command is called, set Traversal process to "complete" so it does not continue
 
 */
void Directory::interrupt()
{
    this->complete = true;
}
