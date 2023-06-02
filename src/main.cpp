#include <iostream>
#include <fstream>
#include <string>
#include "File.hpp"
#include "Resize.hpp"
#include "ImageConverter01.hpp"

using namespace std;
int main()
{

    int size=45;
    int* array=0;

    File *f = new File();
    f->getPhoto("image\\minus.bmp");
    array = f->getArray();


    Resize *r = new Resize(size,array,f->getHeight(),f->getWidht());

    ImageConverter01* ic01 = new ImageConverter01(f->getHeight(),f->getWidht(), size);
    ic01->convert(array,f->getHeight(),f->getWidht());
    ic01->print();

    
}
