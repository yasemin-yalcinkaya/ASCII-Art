#include "ImageConverter01.hpp"

ImageConverter01::ImageConverter01(int ImgHeight, int ImgWidth, int cursorSize, int avg)
{
    m_avg=avg;
    m_cursorSize = cursorSize;
    m_Arr01Widht = (ImgWidth / cursorSize);
    m_Arr01Height = (ImgHeight / (cursorSize * 2));
    m_Arr01 = new int *[m_Arr01Height * m_Arr01Widht];
}

int ImageConverter01::calculateAvg(int *array, int ImgHeight, int ImgWidth)
{
    int sum = 0;
    for (int a = 0; a < ImgHeight; a++)
    {
        for (int b = 0; b < ImgWidth; b++)
        {
            for (int c = 0; c < 3; c++)
            {
                sum += array[(a * ImgWidth * 3) + (b * 3) + c];
            }
        }
    }
    m_avg = sum / (ImgHeight * ImgWidth * 3);
    std::cout << "AVG :" << m_avg << std::endl;

    return m_avg;
}



int ImageConverter01::convert(int *array, int ImgHeight, int ImgWidth)
{
    for (int i = 0; i < m_Arr01Height; i++)    //  m_Arr01Height
    {
        for (int j = 0; j < m_Arr01Widht; j++)    //m_Arr01Widht
        {
            int *cursor01 = new int[m_cursorSize * m_cursorSize * 2];

            for (int k = 0; k < m_cursorSize * 2; k++)
            {
                for (int l = 0; l < m_cursorSize; l++)
                {
                    m_Arr01[i * m_Arr01Widht + j] = cursor01;
                    int pxSum = 0;
                    for (int m = 0; m < 3; m++)
                    {

                        if (k > 0)
                        {
                            pxSum += array[m + (l + (k * (m_Arr01Widht - m_cursorSize)) + (k + i * m_Arr01Widht * 2 + j) * m_cursorSize) * 3];
                        }
                        else
                        {
                            pxSum += array[m + (l + (k + i * m_Arr01Widht * 2 + j) * m_cursorSize) * 3];
                        }
                    }
                    std::cout<<"|| pxSum: "<<pxSum<<"  mavg: "<< ( m_avg * 3);
                    if (pxSum <( m_avg * 3)) //
                    {
                        cursor01[k * m_cursorSize + l] = 1;
                    }
                    else
                    {
                        
                        
                        cursor01[k * m_cursorSize + l] = 0;
                    }
                }
            }
        }
    }
        std::cout << " height: " << m_Arr01Height << std::endl;
        std::cout << " width: " << m_Arr01Widht << std::endl;
        std::cout << " cursor size: " << m_cursorSize << std::endl;
    return 0;
}

void ImageConverter01::print()
{
    for (int i = 0; i < m_Arr01Height; i++) // partArray yükseklik
    {
        for (int j = 0; j < m_Arr01Widht; j++) // partArray genişlik
        {
            for (int k = 0; k < (m_cursorSize * 2); k++) // imlecin yüksekliği
            {
                std::cout << "\n";
                for (int l = 0; l < m_cursorSize; l++) // imlecin genişliği
                {
                    std::cout << ' ' << m_Arr01[j + i * m_Arr01Widht][l + k * m_cursorSize];
                }
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    // for (int i = 0; i < 256; i++)
    // {
    //     std::cout << i << ' ' << (char)i << "\n";
    // }
}

ImageConverter01::~ImageConverter01()
{
}
