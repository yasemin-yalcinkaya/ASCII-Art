#ifndef File_hpp
#define File_hpp
#include <string>
#include "Raw2Array.hpp"
#include <iostream>
#include <fstream>

class File
{
public:
    File();
    ~File();
    void getPhoto(std::string path);
};

#endif
