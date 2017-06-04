#include "tinybmp_maker.h"

TinyBMPMaker::TinyBMPMaker()
:m_image(NULL)
{
    
}

TinyBMPMaker::TinyBMPMaker(const TinyBitmap& image)
{
    m_image = new TinyBitmap(image);
}

bool TinyBMPMaker::darken()
{
    BITMAP_INFO_HEADER bih = m_image->get_info_header();
    unsigned char*** image_buf = m_image->get_buf();
    
    for(int i = 0; i < bih.height; i++)
    {
        for(int j = 0; j < bih.width; j++)
        {
            
            image_buf[i][j][0] = 0;
            image_buf[i][j][1] = 0;
        }
    }
 
    return true;   
}

void TinyBMPMaker::export_image(char* _path)
{
    m_image->export_image(_path);
}