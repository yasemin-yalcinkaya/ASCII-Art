#ifndef File_hpp
#define File_hpp
#include <string>
#include "Resize.hpp"
#include <iostream>
#include <fstream>

class File
{
public:
    File();
    ~File();
    void getPhoto(std::string path);
    int getWidht();
    int getHeight();
    int* getArray();
    void print();
private:    
    int* m_array;
    int m_width;
    int m_height;
};

#endif
