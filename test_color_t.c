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
		printf("Start testing color_t lib:\n");
	
		color_t color = COL_CREATE_RGBA(255,255,255,255);
		color_print(&color);
		
		color = COL_CREATE_RGBA(0,0,0,0);
		COL_SET_R(color, 12);
		COL_SET_G(color, 12);
		COL_SET_B(color, 12);
		COL_SET_A(color, 12);
		printf("col1 with 12: ");
		color_print(&color);
		
		color_add(&color, 8);
		printf("col1 + 8: ");
		color_print(&color);
		
		color_t color2 = COL_CREATE_RGBA(0,0,0,0);
		color_add_dest(&color2,&color, 10);
		printf("col2: col1 + 10: ");
		color_print(&color2);
		
		color_mul(&color, 2);
		printf("col1 * 2: ");
		color_print(&color);
		
		color_mul_dest(&color2,&color, 3);
		printf("col2 = col1 * 3: ");
		COL_SET_A(color2, 66);
		color_print(&color2);
		
		color_mulf_dest(&color2,&color, 0.5f);
		printf("col2 = col1 / 2: ");
		color_print(&color2);
		
		color_mulf(&color2, 0.5f);
		printf("col2 / 2: ");
		color_print(&color2);
		
		color_t color3 = COL_CREATE_RGBA(0,0,0,0);
		color_t color4 = COL_CREATE_RGBA(0,0,0,0);
		int twof = 2.f;
		float half = .5f;
		for(unsigned int r = 0; r < 255; r++){
			COL_SET_R(color3,0);
			for(unsigned int g = 0; g < 255; g++){
				COL_SET_G(color3,0);
				for(unsigned int b = 0; b < 255; b++){
					COL_SET_R(color3,(int)((float)r * 1.f));
					COL_SET_G(color3,(int)((float)g * 1.f));
					COL_SET_B(color3,(int)((float)b * 1.f));
					color_add(&color3, 2);
					color2 = color;
					color4 = color2;
					color_mul(&color2,twof);
					color_mulf(&color4,half);
				}
			}
		}
		
		printf("End testing color_t lib:\n");
	#endif
	return 0;
}