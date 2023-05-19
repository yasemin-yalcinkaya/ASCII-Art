#include <iostream>
#include <fstream>
#include <string>
#include "File.hpp"
#include "Resize.hpp"
using namespace std;
int main()
{
    cout << "hello world\n";

    int size=6;
    int* array=0;

    File *f = new File();
    f->getPhoto("image\\abcd.bmp");
    array = f->getArray();


    Resize *r = new Resize(size,array,f->getHeight(),f->getWidht());


    
}
