#include <iostream>
#include <fstream>
#include <string>
#include "File.hpp"
using namespace std;
int main()
{
    cout << "hello world\n";

    File* f = new File();

    f->getPhoto("C:\\Users\\EmreKara\\Desktop\\fart.java");

}
