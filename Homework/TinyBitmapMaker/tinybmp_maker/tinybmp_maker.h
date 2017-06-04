#pragma once

#include "tinybmp.h"

class TinyBMPMaker
{
public:
    TinyBMPMaker();
    TinyBMPMaker(const TinyBitmap& bmp);
public:
    //unsigned char convert_value(float val);
    unsigned char normalize(int val)
    {
        if(val > 255)
            return 255;
        else if(val < 0)
            return 0;
        else
            return val;
    }
    
    bool darken(float ratio);
    bool smooth();
    bool sharpen();
    bool grayscale();
    void export_image(char* _path);
private:
    TinyBitmap* m_image;
};