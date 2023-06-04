#ifndef ImageConverter01_hpp
#define ImageConverter01_hpp

#include <iostream>

class ImageConverter01
{
public:
	ImageConverter01(int ImgHeight, int ImgWidth, int cursorSize, int avg);
	int calculateAvg(int *array, int ImgHeight, int ImgWidth);
	int convert(int *array, int ImgHeight, int ImgWidth);
	void print();
	~ImageConverter01();

private:
	int m_Arr01Height;
	int m_Arr01Widht;
	int m_cursorSize;
	int m_avg;
	int **m_Arr01;
};
#endif
