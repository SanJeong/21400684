#include <iostream>
#include "tinybmp_def.h"
#include "tinybmp.h"
#include "tinybmp_maker.h"

int main(int argc, char** argv)
{
	std::cout << "Hello, world!!" << std::endl;
	std::cout << sizeof(BITMAP_HEADER) << std::endl;
	std::cout << sizeof(BITMAP_INFO_HEADER) << std::endl;
	TinyBitmap tb = TinyBitmap("image/image.bmp");
	TinyBMPMaker tbm(tb);
	//tbm.darken(0.3);
	//tbm.up_side_down();
	tbm.left_right_filp();
	//tbm.sharpen();
	//tbm.grayscale();
	tbm.export_image("image/image3.bmp");
	
    tb.export_image("image/image2.bmp");

	return 0;
}
