#include "File.hpp"
#include "ImageConverter01.hpp"
#include "Resize.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int main() {

  int size = 3;
  int *array = 0;
  int avg=0;

  File *f = new File();
  f->getPhoto("image\\oldTV.bmp");
  array = f->getArray();
  f->print();
  

  Resize *r = new Resize(size, array, f->getHeight(), f->getWidht());
  r->arrayResize();
  r->print();

  ImageConverter01 *ic01 =
      new ImageConverter01(f->getHeight(), f->getWidht(), size, avg);
  ic01->calculateAvg(array,f->getHeight(), f->getWidht());
  ic01->convert(array, f->getHeight(), f->getWidht());
  
  ic01->print();


}
