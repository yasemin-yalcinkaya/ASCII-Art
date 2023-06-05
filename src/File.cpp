#include "File.hpp"

File::File()
{
    m_width=0;
    m_height=0;
    m_array=0;
    m_fileSize=0;
}

void File::getPhoto(std::string path)
{
    std::ifstream file;
    file.open(path, std::ios::binary | std::ios::in);

    if (file.is_open())
    {
        std::cout << file.tellg();
        std::cout << "dosya acildi\n";

        int arr26[26];
        int cutIndex = 0, offset = 0;

        for (int i = 0; i < 26; i++)
        {
            arr26[i] = file.get();
        }
 
        // calculate
        m_fileSize = arr26[2] + arr26[3] * 256 + arr26[4] * 256 * 256 + arr26[5] * 256 * 256 * 256;
        offset = arr26[10] + arr26[11] * 256 + arr26[12] * 256 * 256 + arr26[13] * 256 * 256 * 256;
        m_width = arr26[18] + arr26[19] * 256 + arr26[20] * 256 * 256 + arr26[21] * 256 * 256 * 256;
        m_height = arr26[22] + arr26[23] * 256 + arr26[24] * 256 * 256 + arr26[25] * 256 * 256 * 256;

        // //read all
        // std::cout << file.tellg()<< std::endl;
        // file.seekg(54);
        // std::cout << file.tellg();
        // char *buffer = new char[m_fileSize];
        // file.read(buffer,m_fileSize);


        // print results
        std::cout << "\n\toffset: \t" << offset
                  << "\n\twidth:  \t" << m_width
                  << "\n\theight: \t" << m_height
                  << "\n\tFile size: \t" << m_fileSize
                  << "\n\theader size:\t" << arr26[14] + arr26[15] * 256 + arr26[16] * 256 * 256 + arr26[17] * 256 * 256 * 256 << std::endl;

        // move to offset
        std::cout << "\n\tunhandled:\t";
        for (int i = 0; i < offset - 26; i++)
        {
            std::cout << file.get();
        }

        // init 3D arr
        int *array = new int[(m_width * m_height * 3)];
        m_array=array;
        
        // set to arr
        for (int x_height = m_height - 1; x_height >= 0; x_height--) // ax
        {
            for (int x_width = 0; x_width < m_width; x_width++) // bx
            {
                for (int i = 2; i >= 0; i--) // cx
                {
                    m_array[(x_height * m_width * 3) + (x_width * 3) + i] = file.get();
                }
            }
            file.get();
        }


        file.close();
         // set to arr
    //    for (int i = 0; i < m_fileSize; i++)
    //    {
    //     int a =0;
    //     if((int)buffer[i]<0){
    //         a=256+(int)buffer[i];
    //     }
    //     else{
    //         a=(int)buffer[i];
    //     }
    //     std::cout <<  a << ' ';
    //    }
       

    }
    else
    {
        std::cout << "file cannot find";
    }
}

void File::print(){
    //print arr to console
    for (int a = 0; a < m_height; a++)
    {
        std::cout << "\n";
        for (int b = 0; b < m_width; b++)
        {
            std::cout << "(";
            for (int c = 0; c < 3; c++)
            {
                std::cout << m_array[(a * m_width * 3) + (b * 3) + c] << ' ';
            }
            std::cout << ")";
        }
    }
}

int File::getWidht(){
    return m_width;
}

int File::getHeight(){
    return m_height;
}

int* File::getArray(){
    return m_array;
}

File::~File()
{
    delete[] m_array;
}
