// #include <iostream>
// #include <fstream>
// #include <string>
// #include <ctime>
// using namespace std;
// int main() {
// 	srand(time(0));
// 	int sayi[10];
//     int random,temp;
//     for (int i = 0; i<10; i++) sayi[i] = i;
//     for (int i = 0; i<10; i++){
//         random = rand() % 10;
//         temp = sayi[i];
//         sayi[i] = sayi[random];
//         sayi[random] = temp;
//     }
//     for (int i = 0; i < 10; i++) cout << sayi[i] << endl;
// }

#include <unistd.h>
///#include <iostream>
int main(void)
{
    // Define array
    int array[] = { 69, 76, 76, 79, 32, 87, 79, 82, 76, 68, 10};
    // print array
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        write(1, (void *)(&array[i]), 1);
    }

    // return 0;
    //std::cout<<"HELLO WORLD";
}