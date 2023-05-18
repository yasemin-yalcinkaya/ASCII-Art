#include "File.hpp"

File::File()
{
}

void File::getPhoto(std::string path)
{
    std::ifstream file(path);

    std::string str = "";

    if (file.is_open())
    {
        std::cout << "dosya acildi\n";

        while (!file.eof())
        {
            str = str + std::to_string(file.get()) + " ";
        }
        Raw2Array r2a(str);
    }
    else
    {
        std::cout << "file cannot find";
    }
}

File::~File()
{
}
