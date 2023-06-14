#include "File.hpp"

File::File()
{
    m_offset = 0;
    m_width = 0;
    m_height = 0;
    m_array = 0;
    m_fileSize = 0;
}

void File::getPhoto(std::string path)
{
    std::ifstream fs;
    fs.open(path, std::ios::binary | std::ios::in);

    if (fs.is_open())
    {
        std::cout << "dosya acildi\n";

        // read all file
        fs.seekg(0, fs.end);
        int fileSize = fs.tellg();
        fs.seekg(0, fs.beg);
        char *buffer = new char[fileSize];
        fs.read(buffer, fileSize);
        fs.close();

        // calculate
        m_fileSize = buffer[2] + buffer[3] * 256 + buffer[4] * 256 * 256 + buffer[5] * 256 * 256 * 256;
        m_offset = buffer[10] + buffer[11] * 256 + buffer[12] * 256 * 256 + buffer[13] * 256 * 256 * 256;
        m_width = buffer[18] + buffer[19] * 256 + buffer[20] * 256 * 256 + buffer[21] * 256 * 256 * 256;
        m_height = buffer[22] + buffer[23] * 256 + buffer[24] * 256 * 256 + buffer[25] * 256 * 256 * 256;

        // print results
        std::cout << "\n\toffset: \t" << m_offset
                  << "\n\twidth:  \t" << m_width
                  << "\n\theight: \t" << m_height
                  << "\n\tFile size: \t" << m_fileSize
                  << "\n\theader size:\t" << buffer[14] + buffer[15] * 256 + buffer[16] * 256 * 256 + buffer[17] * 256 * 256 * 256 << std::endl;

        // init 3D arr
        int *array = new int[(m_width * m_height * 3)];
        // calculate extra bytes
        int extra_width = 0;
        if ((m_width * 3) % 4)
        {
            extra_width = (4 - (((m_width * 3)) % 4));
        }

        //******* prınt buffer
        // std::cout << "\nbytes:";
        // for (int i = 0; i < fileSize; i++)
        // {
        //     if (i == m_offset)
        //         std::cout << "\n";
        //     if ((0 == ((i - m_offset) % ((m_width * 3) + extra_width))) && (i > m_offset))
        //         std::cout << "\n";

        //     if ((int)buffer[i] < 0)
        //         std::cout << 256 + (int)buffer[i] << ' ';
        //     else
        //         std::cout << (int)buffer[i] << ' ';
        // }
        // std::cout << "\n";
        //*****

        int temp;
        for (int i = 0; i < m_height; i++)
        {
            for (int j = 0; j < m_width; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    temp = buffer[(i * m_width * 3) + (j * 3) + k + +m_offset + (i * extra_width)];

                    //
                    if ((int)temp >= 0)
                    {
                        array[(((m_height - 1) - i) * m_width * 3) + (j * 3) + 2 - k] = (int)temp;
                    }
                    else
                    {
                        array[(((m_height - 1) - i) * m_width * 3) + (j * 3) + 2 - k] = (int)temp + 256;
                    }
                }
            }
        }

        m_array = array;
    }
    else
    {
        std::cout << "file cannot find";
    }
}

void File::print()
{
    std::cout << "\nFile:";
    // print arr to console
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

int File::getWidht()
{
    return m_width;
}

int File::getHeight()
{
    return m_height;
}

int *File::getArray()
{
    return m_array;
}

File::~File()
{
    delete[] m_array;
}
