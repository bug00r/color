#if 0
/**
	This is a Test programm for the color lib
*/
#endif

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "color.h"

int 
main() {
	#ifdef debug
		printf("Start testing color lib:\n");
		
		cRGB_t color = {255.f,255.f,255.f};
		crgb_print(&color);
		
		color = (cRGB_t){0.f,0.f,0.f};
		color.r = 12.f;
		color.g = 12.f;
		color.b = 12.f;
		printf("col1 with 12: ");
		crgb_print(&color);
		
		crgb_add(&color, 8.f);
		printf("col1 + 8: ");
		crgb_print(&color);
		
		cRGB_t color2 = {0.f,0.f,0.f};
		crgb_crgb_copy(&color2,&color);
		crgb_add(&color2, 10.f);
		printf("col2: col1 + 10: ");
		crgb_print(&color2);
		
		crgb_mul(&color, 2.f);
		printf("col1 * 2: ");
		crgb_print(&color);
		
		crgb_crgb_copy(&color2,&color);
		crgb_mul(&color2, 3.f);
		printf("col2 = col1 * 3: ");
		crgb_print(&color2);
		
		crgb_crgb_copy(&color2,&color);
		crgb_mul(&color2, .5f);
		printf("col2 = col1 / 2: ");
		crgb_print(&color2);
		
		crgb_crgb_copy(&color2,&color);
		crgb_mul(&color2, .5f);
		printf("col2 / 2: ");
		crgb_print(&color2);
		
		cRGB_t color3 = {0.f,0.f,0.f};
		cRGB_t color4 = {0.f,0.f,0.f};
		float twof = 2.f;
		float half = .5f;
		for(unsigned int r = 0; r < 255; r++){
			color3.r = 0.f;
			for(unsigned int g = 0; g < 255; g++){
				color3.g = 0.f;
				for(unsigned int b = 0; b < 255; b++){
					color3.r = (float)r * 1.f;
					color3.g = (float)g * 1.f;
					color3.b = (float)b * 1.f;
					crgb_add(&color3,2.f);
					crgb_crgb_copy(&color2,&color);
					crgb_crgb_copy(&color4,&color2);
					crgb_mul(&color2,twof);
					crgb_mul(&color4,half);
				}
			}
		}
		
		printf("End testing color lib:\n");
	#endif
	return 0;
}