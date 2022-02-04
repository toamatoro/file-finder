//
//  Directory.cpp
//  file-finder
//
//  Created by Jonathan Lausch on 2/4/22.
//

#include <iostream>
#include "Directory.h"

Directory::Directory(std::string path)
{
    this->path = path;
}

void Directory::addSubStr(std::string substr)
{
    this->substrs.push_back(substr);
}

void Directory::traverse(std::string path, std::string target, Container buffer)
{
    
}
