#include "File.hpp"

File::File()
{
    m_width=0;
    m_height=0;
    m_array=0;
}

void File::getPhoto(std::string path)
{
    std::ifstream file(path);

    if (file.is_open())
    {
        std::cout << "dosya acildi\n";

        int arr26[26];
        int cutIndex = 0, offset = 0;

        for (int i = 0; i < 26; i++)
        {
            arr26[i] = file.get();
        }

        // calculate
        offset = arr26[10] + arr26[11] * 256 + arr26[12] * 256 * 256 + arr26[13] * 256 * 256 * 256;
        m_width = arr26[18] + arr26[19] * 256 + arr26[20] * 256 * 256 + arr26[21] * 256 * 256 * 256;
        m_height = arr26[22] + arr26[23] * 256 + arr26[24] * 256 * 256 + arr26[25] * 256 * 256 * 256;

        // print results
        std::cout << "\n\toffset: \t" << offset
                  << "\n\twidth:  \t" << m_width
                  << "\n\theight: \t" << m_height
                  << "\n\tfile size:\t" << arr26[2] + arr26[3] * 256 + arr26[4] * 256 * 256 + arr26[5] * 256 * 256 * 256
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
                    array[(x_height * m_width * 3) + (x_width * 3) + i] = file.get();
                }
            }
            file.get();
            file.get();
        }
    }
    else
    {
        std::cout << "file cannot find";
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
