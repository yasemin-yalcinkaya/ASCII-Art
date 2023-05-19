#include "Resize.hpp"
#include <iostream>
using namespace std;

Resize::Resize(int size, int* array, int height, int widht)
{

    //print arr to console
        for (int a = 0; a < height; a++)
        {
            std::cout << "\n";
            for (int b = 0; b < widht; b++)
            {
                std::cout << "(";
                for (int c = 0; c < 3; c++)
                {
                    std::cout << array[(a * widht * 3) + (b * 3) + c] << ' ';
                }
                std::cout << ")";
            }
        }

        int partArrWidht=(widht/size);  //11
        int partArrHeight=(height/(size*2));    //2
        int** partArray = new int*[(partArrHeight*partArrWidht)];  //22

        
        
        
        for (int i = 0; i < partArrHeight; i++)      //partArray yükseklik 
        {
            for (int j = 0; j < partArrWidht; j++)   //partArray genişlik
            {
                int* a = new int[size*(size*2)];
                partArray[(partArrWidht*i)+j]=a;

                for (int k = 0; k < (size*2); k++)    //imlecin yüksekliği
                {
                    for (int e = 0; e < size; e++)    //imlecin genişliği
                    {
                        
                    }
                    
                }
                
                
            }
            
        }
        

}


Resize::~Resize()
{
}