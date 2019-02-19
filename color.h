#if 0
/**
	This is a simple color class. 
*/
#endif

#ifndef COLOR_H
#define COLOR_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define COL_MAX 255
#define COL_BIT_R 24
#define COL_BIT_G 16
#define COL_BIT_B 8
#define COL_BIT_A 0
#define COL_MASK_R (COL_MAX << COL_BIT_R)
#define COL_MASK_G (COL_MAX << COL_BIT_G)
#define COL_MASK_B (COL_MAX << COL_BIT_B)
#define COL_MASK_A 255
#define COL_MASK_R_NOT (~(COL_MAX << COL_BIT_R))
#define COL_MASK_G_NOT (~(COL_MAX << COL_BIT_G))
#define COL_MASK_B_NOT (~(COL_MAX << COL_BIT_B))
#define COL_MASK_A_NOT (~(COL_MAX))
#define COL_MASK 255
#define COL_MASK_NOT ~255

#define COL_MOVE_R(r) ((r&COL_MASK) << COL_BIT_R)
#define COL_MOVE_G(g) ((g&COL_MASK) << COL_BIT_G)
#define COL_MOVE_B(b) ((b&COL_MASK) << COL_BIT_B)
#define COL_MOVE_A(a) ((a&COL_MASK) << COL_BIT_A)

#define COL_MOVE_ALL(r,g,b,a) (COL_MOVE_R(r) | COL_MOVE_G(g) | COL_MOVE_B(b) | COL_MOVE_A(a))

#define COL_TRUNC_R(color) (color & COL_MASK_R_NOT)
#define COL_TRUNC_G(color) (color & COL_MASK_G_NOT)
#define COL_TRUNC_B(color) (color & COL_MASK_B_NOT)
#define COL_TRUNC_A(color) (color & COL_MASK_A_NOT)

#define COL_GET_R(color) ((color >> COL_BIT_R) & COL_MASK)
#define COL_GET_G(color) ((color >> COL_BIT_G) & COL_MASK)
#define COL_GET_B(color) ((color >> COL_BIT_B) & COL_MASK)
#define COL_GET_A(color) ((color >> COL_BIT_A) & COL_MASK)

#define COL_SET_R(color, r) (color = (COL_TRUNC_R(color) | COL_MOVE_R(r)))
#define COL_SET_G(color, g) (color = (COL_TRUNC_G(color) | COL_MOVE_G(g)))
#define COL_SET_B(color, b) (color = (COL_TRUNC_B(color) | COL_MOVE_B(b)))
#define COL_SET_A(color, a) (color = (COL_TRUNC_A(color) | COL_MOVE_A(a)))

#define COL_CREATE_RGBA(r,g,b,a) ((color_t) COL_MOVE_ALL(r,g,b,a))

typedef unsigned long int color_t;

typedef struct {
	float r, g, b;
} cRGB_t;

#if 0
	/**
		Creates new color object
	*/
#endif
cRGB_t * create_crgb( const float r, const float g, const float b);
#if 0
	/**
		copy values from color2 into color.
	*/
#endif
void crgb_crgb_copy(cRGB_t *  color, const cRGB_t *  color2);
//no need for color_t its only  color2 = color1

#if 0
	/**
		Add two colors and store result in color.
	*/
#endif
void crgb_crgb_add(cRGB_t *  color, const cRGB_t *  color2);
//no need for color_t its only color1 += color2

#if 0
	/**
		Add color value to each value of rgba. If you want to sub then add negative number
	*/
#endif
void crgb_add(cRGB_t *  color, const float add);
void color_add(color_t *  color, const int add);
void color_add_dest(color_t *  dest, const color_t *  color, const int add);
#if 0
	/**
		Multiplies color value to each value of rgba. If you want to divife then multiply antivalent number
	*/
#endif
void crgb_mul(cRGB_t *  color, const float mul);
void color_mul(color_t *  color, const int mul);
void color_mul_dest(color_t *  dest, const color_t *  color, const int mul);
void color_mulf(color_t *  color, const float mul);
void color_mulf_dest(color_t *  dest, const color_t *  color, const float mul);
#if 0
	/**
		prints color value
	*/
#endif
void crgb_print(const cRGB_t *  color);
void color_print(const color_t *  color);

#if 0
	/**
		calculates color with new brightness for color range 0 to 255. Result is stored in dest.
	*/
#endif
void crgb_brightness_255_dest(cRGB_t *  dest, const cRGB_t *  color, const float brightness);
void color_brightness_255_dest(/** cRGB_t*/color_t *  dest, /** cRGB_t*/const color_t *  color, const int brightness);

#if 0
	/**
		calculates color with new contrast_factor for wanted contrast for color range 0 to 255. Result is stored in dest.
	*/
#endif
float crgb_contrast_factor_255(const float contrast);
float color_contrast_factor_255(const int contrast);

#if 0
	/**
		calculates color with new contrast for color range 0 to 255. Result is stored in dest.
	*/
#endif
void crgb_contrast_255_dest(cRGB_t *  dest, const cRGB_t *  color, const float contrast_factor);
void color_contrast_255_dest(/** cRGB_t*/color_t * dest, /** cRGB_t*/const color_t * color, const float contrast_factor);

#endif
