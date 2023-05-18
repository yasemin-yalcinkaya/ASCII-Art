#include "File.hpp"

File::File()
{
}

void File::getPhoto(std::string path)
{
    std::ifstream file(path);

    if (file.is_open())
    {
        std::cout << "dosya acildi\n";

        int arr26[26];
        int cutIndex = 0, offset = 0, width = 0, height = 0;

        for (int i = 0; i < 26; i++)
        {
            arr26[i] = file.get();
        }

        // calculate
        offset = arr26[10] + arr26[11] * 256 + arr26[12] * 256 * 256 + arr26[13] * 256 * 256 * 256;
        width = arr26[18] + arr26[19] * 256 + arr26[20] * 256 * 256 + arr26[21] * 256 * 256 * 256;
        height = arr26[22] + arr26[23] * 256 + arr26[24] * 256 * 256 + arr26[25] * 256 * 256 * 256;

        // print results
        std::cout << "\n\toffset: \t" << offset
                  << "\n\twidth:  \t" << width
                  << "\n\theight: \t" << height
                  << "\n\tfile size:\t" << arr26[2] + arr26[3] * 256 + arr26[4] * 256 * 256 + arr26[5] * 256 * 256 * 256
                  << "\n\theader size:\t" << arr26[14] + arr26[15] * 256 + arr26[16] * 256 * 256 + arr26[17] * 256 * 256 * 256 << std::endl;

        // move to offset
        std::cout << "\n\tunhandled:\t";
        for (int i = 0; i < offset - 26; i++)
        {
            std::cout << file.get();
        }

        // init 3D arr
        int *array = new int[(width * height * 3)];
        // set to arr
        for (int x_height = height - 1; x_height >= 0; x_height--) // ax
        {
            std::cout << std::endl;
            for (int x_width = 0; x_width < width; x_width++) // bx
            {
                for (int i = 2; i >= 0; i--) // cx
                {
                    array[(x_height * width * 3) + (x_width * 3) + i] = file.get();
                }
            }
            file.get();
            file.get();
        }

        // print arr to console
        for (int a = 0; a < height; a++)
        {
            std::cout << "\n";
            for (int b = 0; b < width; b++)
            {
                std::cout << "(";
                for (int c = 0; c < 3; c++)
                {
                    std::cout << array[(a * width * 3) + (b * 3) + c] << ' ';
                }
                std::cout << ")";
            }
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
