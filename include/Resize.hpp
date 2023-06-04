#ifndef Resize_hpp
#define Resize_hpp
#include <string>
class Resize
{
public:
	Resize(int size, int* array,int height, int width);
	void print();
	void arrayResize();
	~Resize();
private:
	int m_partArrHeight;
	int m_partArrWidht;
	int m_size;
	int **m_partArray;
	int *m_array;
	int m_width;
	int m_height;

};
#endif