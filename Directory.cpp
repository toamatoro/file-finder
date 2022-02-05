//
//  Directory.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#include <iostream>
#include <fstream>
#include <filesystem>
#include <thread>

#include "Directory.h"

Directory::Directory(std::string path, std::string target)
{
    this->path = path;
    this->target = target;
    this->complete = false;
}

/*void Directory::addSubStr(std::string substr)
{
    this->targets.push_back(substr);
}*/

void Directory::traverse(std::string target, Container * buffer)
{
    const std::filesystem::path dir{this->path};
    
    for(auto &a_entry : std::filesystem::recursive_directory_iterator{dir})
    {
        std::string s_entry = a_entry.path();
        
        if(s_entry.find(target, 0) != std::string::npos)
        {
            // to slow down access for testing
            int r = rand() % 100;
            std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::milliseconds(r));
            buffer->addItem(s_entry);
        }
    }
}

std::string Directory::getTarget()
{
    return this->target;
}
