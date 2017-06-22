#include "tinybmp_maker.h"

TinyBMPMaker::TinyBMPMaker()
:m_image(NULL)
{
    
}

bool TinyBMPMaker::add_image(std::string file_path)
{
    
}

TinyBMPMaker::TinyBMPMaker(const TinyBitmap& image)
{
    m_image = new TinyBitmap(image);
}

bool TinyBMPMaker::darken(float ratio)
{
    BITMAP_INFO_HEADER bih = m_image->get_info_header();
    unsigned char*** image_buf = m_image->get_buf();
    
    for(int i = 0; i < bih.height; i++)
    {
        for(int j = 0; j < bih.width; j++)
        {
            
            image_buf[i][j][0] = normalize((int)image_buf[i][j][0] *ratio);
            image_buf[i][j][1] = normalize((int)image_buf[i][j][1] *ratio);
            image_buf[i][j][2] = normalize((int)image_buf[i][j][2] *ratio);
        }
    }
 
    return true;   
}

bool TinyBMPMaker::grayscale()
{
    BITMAP_INFO_HEADER bih = m_image->get_info_header();
    unsigned char*** image_buf = m_image->get_buf();
    
    float value = 0;
    for(int i = 0; i < bih.height; i++)
    {
        for(int j = 0; j < bih.width; j++)
        {
            value = (image_buf[i][j][0] + image_buf[i][j][0] + image_buf[i][j][0])/3.0;
            image_buf[i][j][0] = normalize(value);
            image_buf[i][j][1] = normalize(value);
            image_buf[i][j][2] = normalize(value);
        }
    }
 
    return true;   
}

void TinyBMPMaker::blur()
{
    float filter[3][3] = {{1/9.0, 1/9.0, 1/9.0},{1/9.0, 1/9.0, 1/9.0},{1/9.0, 1/9.0, 1/9.0}};
    BITMAP_INFO_HEADER bih = m_image->get_info_header();
    unsigned char*** image_buf = m_image->get_buf();
    
    float value;
    
    for(int i = 1; i < bih.height-1; i++)
    {
        for(int j = 1; j < bih.width-1; j++)
        {
         
            value = image_buf[i-1][j-1][0]*filter[0][0] +
                    image_buf[i-1][j  ][0]*filter[0][1] + 
                    image_buf[i-1][j+1][0]*filter[0][2] + 
            
                    image_buf[i  ][j-1][0]*filter[1][0] + 
                    image_buf[i  ][j  ][0]*filter[1][1] + 
                    image_buf[i  ][j+1][0]*filter[1][2] + 
            
                    image_buf[i+1][j-1][0]*filter[2][0] + 
                    image_buf[i+1][j  ][0]*filter[2][1] + 
                    image_buf[i+1][j+1][0]*filter[2][2];
            
            image_buf[i][j][0] = normalize(value);
            
            value = image_buf[i-1][j-1][1]*filter[0][0] +
                    image_buf[i-1][j  ][1]*filter[0][1] + 
                    image_buf[i-1][j+1][1]*filter[0][2] + 
            
                    image_buf[i  ][j-1][1]*filter[1][0] + 
                    image_buf[i  ][j  ][1]*filter[1][1] + 
                    image_buf[i  ][j+1][1]*filter[1][2] + 
            
                    image_buf[i+1][j-1][1]*filter[2][0] + 
                    image_buf[i+1][j  ][1]*filter[2][1] + 
                    image_buf[i+1][j+1][1]*filter[2][2];
            image_buf[i][j][1] = normalize(value);
            
            value = image_buf[i-1][j-1][2]*filter[0][0] +
                    image_buf[i-1][j  ][2]*filter[0][1] + 
                    image_buf[i-1][j+1][2]*filter[0][2] + 
            
                    image_buf[i  ][j-1][2]*filter[1][0] + 
                    image_buf[i  ][j  ][2]*filter[1][1] + 
                    image_buf[i  ][j+1][2]*filter[1][2] + 
            
                    image_buf[i+1][j-1][2]*filter[2][0] + 
                    image_buf[i+1][j  ][2]*filter[2][1] + 
                    image_buf[i+1][j+1][2]*filter[2][2];
            image_buf[i][j][2] = normalize(value);
        }
    }
}


void TinyBMPMaker::sharpen()
{
    float filter[3][3] = {{0, -1, 0},{-1, 5.0, -1},{0, -1, 0}};
    BITMAP_INFO_HEADER bih = m_image->get_info_header();
    unsigned char*** image_buf = m_image->get_buf();
    
    float value;

    for(int i = 1; i < bih.height-1; i++)
    {
        for(int j = 1; j < bih.width-1; j++)
        {
         
            value = image_buf[i-1][j-1][0]*filter[0][0] +
                    image_buf[i-1][j  ][0]*filter[0][1] + 
                    image_buf[i-1][j+1][0]*filter[0][2] + 
            
                    image_buf[i  ][j-1][0]*filter[1][0] + 
                    image_buf[i  ][j  ][0]*filter[1][1] + 
                    image_buf[i  ][j+1][0]*filter[1][2] + 
            
                    image_buf[i+1][j-1][0]*filter[2][0] + 
                    image_buf[i+1][j  ][0]*filter[2][1] + 
                    image_buf[i+1][j+1][0]*filter[2][2];
            
            image_buf[i][j][0] = normalize(value);
            
            value = image_buf[i-1][j-1][1]*filter[0][0] +
                    image_buf[i-1][j  ][1]*filter[0][1] + 
                    image_buf[i-1][j+1][1]*filter[0][2] + 
            
                    image_buf[i  ][j-1][1]*filter[1][0] + 
                    image_buf[i  ][j  ][1]*filter[1][1] + 
                    image_buf[i  ][j+1][1]*filter[1][2] + 
            
                    image_buf[i+1][j-1][1]*filter[2][0] + 
                    image_buf[i+1][j  ][1]*filter[2][1] + 
                    image_buf[i+1][j+1][1]*filter[2][2];
            image_buf[i][j][1] = normalize(value);
            
            value = image_buf[i-1][j-1][2]*filter[0][0] +
                    image_buf[i-1][j  ][2]*filter[0][1] + 
                    image_buf[i-1][j+1][2]*filter[0][2] + 
            
                    image_buf[i  ][j-1][2]*filter[1][0] + 
                    image_buf[i  ][j  ][2]*filter[1][1] + 
                    image_buf[i  ][j+1][2]*filter[1][2] + 
            
                    image_buf[i+1][j-1][2]*filter[2][0] + 
                    image_buf[i+1][j  ][2]*filter[2][1] + 
                    image_buf[i+1][j+1][2]*filter[2][2];
            image_buf[i][j][2] = normalize(value);
        }
    }
}

void TinyBMPMaker::up_side_down()
{
    BITMAP_INFO_HEADER bih = m_image->get_info_header();
    unsigned char*** image_buf = m_image->get_buf();
    
    int value1;
    int value2;
    for(int i = 0; i < bih.height/2; i++)
    {
        for(int j = 0; j < bih.width; j++)
        {
            value1 = image_buf[i][j][0];
            value2 = image_buf[bih.height-1-i][j][0];
            image_buf[i][j][0] = value2;
            image_buf[bih.height-1-i][j][0] = value1;
            

            value1 = image_buf[i][j][1];
            value2 = image_buf[bih.height-1-i][j][1];
            image_buf[i][j][1] = value2;
            image_buf[bih.height-1-i][j][1] = value1;
            
            value1 = image_buf[i][j][2];
            value2 = image_buf[bih.height-1-i][j][2];
            image_buf[i][j][2] = value2;
            image_buf[bih.height-1-i][j][2] = value1;
            
        }
    }
}

void TinyBMPMaker::left_right_filp()
{
    BITMAP_INFO_HEADER bih = m_image->get_info_header();
    unsigned char*** image_buf = m_image->get_buf();
    int value1;
    int value2;
    for(int i = 0; i < bih.height; i++)
    {
        for(int j = 0; j < bih.width/2; j++)
        {
            value1 = image_buf[i][j][0];
            value2 = image_buf[i][bih.width-1-j][0];
            image_buf[i][j][0] = value2;
            image_buf[i][bih.width-1-j][0] = value1;
            
            value1 = image_buf[i][j][1];
            value2 = image_buf[i][bih.width-1-j][1];
            image_buf[i][j][1] = value2;
            image_buf[i][bih.width-1-j][1] = value1;
            
            value1 = image_buf[i][j][2];
            value2 = image_buf[i][bih.width-1-j][2];
            image_buf[i][j][2] = value2;
            image_buf[i][bih.width-1-j][2] = value1;
        }
    }
}

void TinyBMPMaker::export_image(char* _path)
{
    m_image->export_image(_path);
}
