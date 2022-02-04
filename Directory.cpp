//
//  Directory.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#include <iostream>
#include <fstream>
#include <filesystem>

#include "Directory.h"

Directory::Directory(std::string path)
{
    this->path = path;
}

void Directory::addSubStr(std::string substr)
{
    this->substrs.push_back(substr);
}

void Directory::traverse(std::string target, Container * buffer)
{
    const std::filesystem::path dir{this->path};
    
    for(auto &a_entry :  std::filesystem::recursive_directory_iterator{dir})
    {
        std::string s_entry = a_entry.path();
        
        if(s_entry.find(target, 0) != std::string::npos)
        {
            buffer->addItem(s_entry);
        }
    }
}

void Directory::setThreads(int n)
{
    this->n_threads = n;
}

int Directory::getThreads()
{
    return this->n_threads;
}
