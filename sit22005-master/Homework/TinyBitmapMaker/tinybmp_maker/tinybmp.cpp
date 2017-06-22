#include "tinybmp.h"
#include "tinybmp_def.h"
#include <fstream>

TinyBitmap::TinyBitmap()
{

}

TinyBitmap::TinyBitmap(const char* _path)
{
    this-> ex = import_image(_path);
}

TinyBitmap::TinyBitmap(const TinyBitmap& rhs)
{
    m_header = rhs.m_header;
    m_info_header = rhs.m_info_header;
    
     // Memory Allocation
    m_image_buf = new unsigned char**[m_info_header.height];
    for(int i = 0; i < m_info_header.height; i++)
    {
        m_image_buf[i] = new unsigned char*[m_info_header.width];
        for(int j = 0; j < m_info_header.width; j++)
        {
            m_image_buf[i][j] = new unsigned char[3];
        }
    }

    // for int i = 0; i < m_info_header.height; i++)
    //{
    //      for(int j = 0; j < (m_info_header.width*3); j++)
    //      m_image_buf[i* (m_info_header.width*3) + j]
    //}
    // Data import
    for(int i = 0; i < m_info_header.height; i++)
    {
        for(int j = 0; j < m_info_header.width; j++)
        {
            //fin.read((char*)m_image_buf[i][j], 3);
            for(int k = 0; k < 3; k++)
                m_image_buf[i][j][k] = rhs.m_image_buf[i][j][k];
        }
    }
}

TinyBitmap::~TinyBitmap()
{
    for(int i = 0; i < m_info_header.height; i++)
    {
        for(int j = 0; j < m_info_header.width; j++)
        {
            delete [] m_image_buf[i][j];
        }
        delete [] m_image_buf[i];
    }
    delete [] m_image_buf;
}

void TinyBitmap::print_header(std::ostream& strm)
{
    strm << "Print BITMAP Header" << std::endl;
    strm << "Type: " << m_header.type << std::endl;
    strm << "Size: " << m_header.size << std::endl;
    strm << "Reserved1: " << m_header.reserved1 << std::endl;
    strm << "Reserved2: " << m_header.reserved2 << std::endl;
    strm << "Offset: " << m_header.offset << std::endl;
}

void TinyBitmap::print_info_header(std::ostream& strm)
{
    strm << "Print BITMAPINFO Header" << std::endl;
    strm << "Size: " << m_info_header.size << std::endl;
    strm << "Width: " << m_info_header.width << std::endl;
    strm << "Height:" << m_info_header.height << std::endl;
    strm << "Planes: " << m_info_header.planes << std::endl;
    strm << "Bits: " << m_info_header.bits << std::endl;
    strm << "Compression " << m_info_header.compression << std::endl;
    strm << "Image Size: " << m_info_header.image_size << std::endl;
    strm << "X Resolution: " << m_info_header.x_resolution << std::endl;
    strm << "Y Resolution: " << m_info_header.y_resolution << std::endl;
    strm << "Colors: " << m_info_header.colors << std::endl;
    strm << "Important Colors: " << m_info_header.important_colors << std::endl;
}

bool TinyBitmap::import_image(const char* _path)
{
    std::ifstream fin;
	fin.open(_path, std::ifstream::binary);

    fin.read((char*)&m_header, sizeof(BITMAP_HEADER));
	fin.read((char*)&m_info_header, sizeof(BITMAP_INFO_HEADER));

	// File Type Checking
    if((((m_header.type & 0xFF00) >> 8) != 0x4d) ||
            ((m_header.type & 0x00FF) != 0x42))
    {
        std::cerr << "The given file " << _path << " is not a bmp file. " << std::endl;
        std::cerr << "Please re-check the given file." << std::endl;
        return false;
    }

    // Memory Allocation
    m_image_buf = new unsigned char**[m_info_header.height];
    for(int i = 0; i < m_info_header.height; i++)
    {
        m_image_buf[i] = new unsigned char*[m_info_header.width];
        for(int j = 0; j < m_info_header.width; j++)
        {
            m_image_buf[i][j] = new unsigned char[3];
        }
    }

    // File import
    for(int i = 0; i < m_info_header.height; i++)
    {
        for(int j = 0; j < m_info_header.width; j++)
        {
            fin.read((char*)m_image_buf[i][j], 3);
        }
    }
	fin.close();

    return true;
}

bool TinyBitmap::export_image(const char *_path)
{
    std::ofstream fout;
    fout.open(_path, std::ios_base::binary);

    // Update Bitmap Header
    fout.write((char*)&m_header, sizeof(BITMAP_HEADER));

    // Update Bitmap InfoHeader
    fout.write((char*)&m_info_header, sizeof(BITMAP_INFO_HEADER));

    // File import
    for(int i = 0; i < m_info_header.height; i++)
    {
        for(int j = 0; j < m_info_header.width; j++)
        {
            fout.write((char*)m_image_buf[i][j], 3);
        }
    }

    fout.close();
    return true;
}