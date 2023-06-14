#include "File.hpp"
#include "ImageConverter01.hpp"
#include "Resize.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int main()
{

  int size = 49;
  int *array = 0;
  int avg = 0;
  int **part_array;

  File *f = new File();
  std::string fileName = "e";
  std::cout << fileName << "\n";
  f->getPhoto("image\\" + fileName + ".bmp");
  array = f->getArray();
  //f->print();

  Resize *r = new Resize(size, array, f->getHeight(), f->getWidht());
  part_array = r->arrayResize();
  //r->print();

  ImageConverter01 *ic01 =
      new ImageConverter01(f->getHeight(), f->getWidht(), size, avg);
  ic01->calculateAvg(array, f->getHeight(), f->getWidht());
  ic01->convert(part_array, f->getHeight(), f->getWidht());
  ic01->print();
}
