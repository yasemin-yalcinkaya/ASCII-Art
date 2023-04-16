#include "File.hpp"
#include <iostream>
#include <fstream>


using namespace std;

File::File()
{
}

void File::getPhoto(std::string path)
{
    std::ifstream file(path);
    

    if (file.is_open())
    {
        std::cout << "dosya acildi";
        while (!file.eof())
        {
           std::cout << file.get();
        }
    }
    else
    {
        std::cout << "file cannot find";
    }
}

File::~File()
{
}
