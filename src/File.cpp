#include "File.hpp"


File::File()
{
}


void File::getPhoto(std::string path)
{
    std::ifstream file(path);

    std::string str="emre";
    Raw2Array r2a(str);
    

    if (file.is_open())
    {
        std::cout << "dosya acildi\n";

        while (!file.eof())
        {
           std::cout << file.get() << " ";
          
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
