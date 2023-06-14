#include "ImageConverter01.hpp"

ImageConverter01::ImageConverter01(int ImgHeight, int ImgWidth, int cursorSize, int avg)
{
    m_avg = avg;
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

int ImageConverter01::convert(int **part_array, int ImgHeight, int ImgWidth)
{
    int pxSum = 0;
    for (int i = 0; i < m_Arr01Height; i++) //  m_Arr01Height
    {
        for (int j = 0; j < m_Arr01Widht; j++) // m_Arr01Widht
        {
            m_Arr01[i * m_Arr01Widht + j] = new int[m_cursorSize * m_cursorSize * 2];

            for (int k = 0; k < m_cursorSize * 2; k++)
            {
                for (int l = 0; l < m_cursorSize; l++)
                {
                    pxSum = 0;

                    for (int m = 0; m < 3; m++)
                        pxSum += part_array[j + m_Arr01Widht * i][m + (l * 3) + (3 * m_cursorSize * k)];

                    if (pxSum > (m_avg * 3))
                        m_Arr01[i * m_Arr01Widht + j][k * m_cursorSize + l] = 1;

                    else
                        m_Arr01[i * m_Arr01Widht + j][k * m_cursorSize + l] = 0;
                }
            }
        }
    }
    return 0;
}

void ImageConverter01::print()
{
    std::cout << "\nImgConvert01:";
    for (int i = 0; i < m_Arr01Height; i++) // partArray yükseklik
    {
        for (int j = 0; j < m_Arr01Widht; j++) // partArray genişlik
        {
            for (int k = 0; k < (m_cursorSize * 2); k++) // imlecin yüksekliği
            {
                std::cout << "\n";
                for (int l = 0; l < m_cursorSize; l++) // imlecin genişliği
                {
                    std::cout << ' ' << m_Arr01[j + (i * m_Arr01Widht)][l + (k * m_cursorSize)];
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
