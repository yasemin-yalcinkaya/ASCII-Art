#include "Resize.hpp"
#include <iostream>
using namespace std;

Resize::Resize(int size, int *array, int height, int widht) {
  m_size=size;
  m_width=widht;
  m_height=height;
  m_array=array;
  m_partArrWidht = (m_width / m_size);         // 11
  m_partArrHeight = (height / (m_size * 2)); // 2
  m_partArray = new int *[(m_partArrHeight * m_partArrWidht)]; 
}

void Resize::arrayResize()
{
    std::cout << "\n";
  for (int i = 0; i < m_partArrHeight; i++) // partArray yükseklik
  {
    for (int j = 0; j < m_partArrWidht; j++) // partArray genişlik
    {
      int *cursor = new int[m_size * (m_size * 2) * 3];

      m_partArray[(m_partArrWidht * i) + j] = cursor;

      for (int k = 0; k < (m_size * 2); k++) // imlecin yüksekliği
      {
        // std::cout << "\n";
        for (int l = 0; l < m_size; l++) // imlecin genişliği
        {
          // std::cout << "(";
          for (int m = 0; m < 3; m++) {
            cursor[(k * m_size * 3) + (l * 3) + m] =
                m_array[(k * m_size * 3) + (l * 3) + m];
            if (k > 0) {
              cursor[(k * m_size * 3) + (l * 3) + m] =
                  m_array[m + (l + (k * (m_width - m_size)) +
                             (k + i * m_width * 2 + j) * m_size) *
                                3];
            } else {
              cursor[(k * m_size * 3) + (l * 3) + m] =
                  m_array[m + (l + (k + i * m_width * 2 + j) * m_size) * 3];
            }
          }
          // std::cout << ")";
        }
      }
    }
  }
}

void Resize::print()
{
    for (int i = 0; i < m_partArrHeight; i++) // partArray yükseklik
  {
    for (int j = 0; j < m_partArrWidht; j++) // partArray genişlik
    {
      for (int k = 0; k < (m_size * 2); k++) // imlecin yüksekliği
      {
        std::cout << "\n";
        for (int l = 0; l < m_size; l++) // imlecin genişliği
        {
          std::cout << "(";
          for (int m = 0; m < 3; m++) {
            std::cout
                << m_partArray[j + i * m_partArrWidht][m + 3 * l + 3 * m_size * k] << ' ';
          }
          std::cout << ")";
        }
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  }
}

Resize::~Resize() {}