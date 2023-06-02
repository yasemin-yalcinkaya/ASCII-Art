#include "Resize.hpp"
#include <iostream>
using namespace std;

Resize::Resize(int size, int *array, int height, int widht)
{

    // print arr to console
    // for (int a = 0; a < height; a++)
    // {
    //     std::cout << "\n";
    //     for (int b = 0; b < widht; b++)
    //     {
    //         std::cout << "(";
    //         for (int c = 0; c < 3; c++)
    //         {
    //             std::cout << array[(a * widht * 3) + (b * 3) + c] << ' ';
    //         }
    //         std::cout << ")";
    //     }
    // }

    int partArrWidht = (widht / size);                               // 11
    int partArrHeight = (height / (size * 2));                       // 2
    int **partArray = new int *[(partArrHeight * partArrWidht) ]; // 22*3(rgb değerleri)

    std::cout << "\n";
    for (int i = 0; i < partArrHeight; i++) // partArray yükseklik
    {
        for (int j = 0; j < partArrWidht; j++) // partArray genişlik
        {
            int *cursor = new int[size * (size * 2) * 3];
            partArray[(partArrWidht * i) + j] = cursor;

            for (int k = 0; k < (size * 2); k++) // imlecin yüksekliği
            {
                // std::cout << "\n";
                for (int l = 0; l < size; l++) // imlecin genişliği
                {
                    // std::cout << "(";
                    for (int m = 0; m < 3; m++)
                    {
                        cursor[(k * size * 3) + (l * 3) + m] = array[(k * size * 3) + (l * 3) + m];
                        if (k > 0)
                        {
                            cursor[(k * size * 3) + (l * 3) + m] = array[m + (l + (k * (widht - size)) + (k + i * widht * 2 + j) * size) * 3];
                        }
                        else
                        {
                            cursor[(k * size * 3) + (l * 3) + m] = array[m + (l + (k + i * widht * 2 + j) * size) * 3];
                        }
                    }
                    // std::cout << ")";
                }
            }
        }
    }

    for (int i = 0; i < partArrHeight; i++) // partArray yükseklik
    {
        for (int j = 0; j < partArrWidht; j++) // partArray genişlik
        {
            for (int k = 0; k < (size * 2); k++) // imlecin yüksekliği
            {
                std::cout << "\n";
                for (int l = 0; l < size; l++) // imlecin genişliği
                {
                    std::cout << "(";
                    for (int m = 0; m < 3; m++)
                    {
                        std::cout << partArray[j + i * partArrWidht][m + 3 * l + 3 * size * k] << ' ';
                    }
                    std::cout << ")";
                }
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}

Resize::~Resize()
{
}