#if 0
/**
	This is a Test programm for the color lib
*/
#endif

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "color.h"

#define TEST_COLOR_COLOR(_color, _color2) \
	do {\
		assert(_color.r == _color2.r);\
		assert(_color.g == _color2.g);\
		assert(_color.b == _color2.b);\
	} while(0)

#define TEST_COLOR_RGB(_color, _r, _g, _b) \
	do {\
		assert(_color.r == _r);\
		assert(_color.g == _g);\
		assert(_color.b == _b);\
	} while(0)

int 
main() {

	ColorRGB color = {255.f,255.f,255.f};
	TEST_COLOR_RGB(color, 255.f,255.f,255.f);		

	color.r = 12.f;
	color.g = 12.f;
	color.b = 12.f;
	crgb_add(&color, 8.f);
	TEST_COLOR_RGB(color, 20.f, 20.f, 20.f);
	
	ColorRGB color2 = {0.f,0.f,0.f};
	crgb_crgb_copy(&color2,&color);
	TEST_COLOR_COLOR(color2, color);

	crgb_add(&color2, 10.f);
	TEST_COLOR_RGB(color2, 30.f, 30.f, 30.f);

	crgb_mul(&color, 2.f);
	TEST_COLOR_RGB(color, 40.f, 40.f, 40.f);

	crgb_crgb_copy(&color2,&color);
	crgb_mul(&color2, 3.f);
	TEST_COLOR_RGB(color2, 120.f, 120.f, 120.f);

	
	crgb_crgb_copy(&color2,&color);
	crgb_mul(&color2, .5f);
	TEST_COLOR_RGB(color2, 20.f, 20.f, 20.f);
	
	crgb_crgb_copy(&color2,&color);
	crgb_mul(&color2, .5f);
	TEST_COLOR_RGB(color2, 20.f, 20.f, 20.f);
	
	crgb_crgb_set(&color2, 1.f, 2.f, 3.f);
	TEST_COLOR_RGB(color2, 1.f, 2.f, 3.f);

	crgb_crgb_set_ptr(&color2, &color.r , &color.g, &color.b);
	TEST_COLOR_RGB(color2, 40.f, 40.f, 40.f);

	return 0;
}