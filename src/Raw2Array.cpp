#include "Raw2Array.hpp"
#include <iostream>
using namespace std;

Raw2Array::Raw2Array(std::string rawData)
{
    std::cout << rawData;

    std::string dataString = rawData;
    int arr14[14];
    int cutIndex = 0;

    for (int i = 0; i < 14; i++)
    {
        cutIndex = dataString.find(" ");
        std::string num = dataString.substr(0, cutIndex);
        arr14[i] = std::stoi(num);
        dataString = dataString.substr(cutIndex + 1, dataString.find("-1") + 2);
    }
    std::cout << "\n\toffset: \t" << arr14[10] + arr14[11] * 256 + arr14[12] * 256 * 256 + arr14[13] * 256 * 256 * 256
              << "\n\tfile size:\t" << arr14[2] + arr14[3] * 256 + arr14[4] * 256 * 256 + arr14[5] * 256 * 256 * 256;

    // int i=0;
    //  if(i==13){
    //         std::cout << endl;
    //        }
    //        if(i==53){
    //         std::cout << endl << endl;
    //        }
    //        i++;
    //        if(i>53 && ((i-54)%3)==0){
    //         std::cout << endl;
    //        }
}

Raw2Array::~Raw2Array()
{
}