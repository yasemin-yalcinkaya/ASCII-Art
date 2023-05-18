#include "Raw2Array.hpp"
#include <iostream>
using namespace std;

Raw2Array::Raw2Array(std::string rawData)
{

    std::string dataString = rawData;
    int arr26[26];
    int cutIndex = 0, offset = 0, width = 0, height = 0;

    // get first 26 of rawData
    for (int i = 0; i < 26; i++)
    {
        cutIndex = dataString.find(" ");
        std::string num = dataString.substr(0, cutIndex);
        arr26[i] = std::stoi(num);
        dataString = dataString.substr(cutIndex + 1, dataString.find("-1") + 2);
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

    // get after offset
    std::string temp = rawData;
    for (int i = 0; i < offset; i++)
    {
        cutIndex = temp.find(" ");
        temp = temp.substr(cutIndex + 1, temp.find("-1") + 2);
    }
    int *array = new int[(width * height * 3)];

    std::cout << temp;
    for (int x_height = height; x_height > 0; x_height--) // ax
    {
        for (int x_width = width; x_width > 0; x_width--) // bx
        {
            for (int i = 3; i > 0; i--) // cx
            {
                std::cout << "a";
                cutIndex = temp.find(" ");
                std::string num = temp.substr(0, cutIndex);
                array[(x_height * width * 3) + (x_width * 3) + i] = std::stoi(num);
                temp = temp.substr(cutIndex + 1, temp.find("-1") + 2);
                std::cout << "h ";
            }
        }
         
        std::cout << std::endl;
    }
}

Raw2Array::~Raw2Array()
{
}