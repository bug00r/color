#include "color.h"

static const size_t cRGB_size = sizeof(cRGB_t);

cRGB_t * 
create_crgb(const float r, const float g, const float b) {
	cRGB_t * newcolor = malloc(cRGB_size);
	newcolor->r = r;
	newcolor->g = g;
	newcolor->b = b;
	return newcolor;
}

void 
crgb_crgb_copy(cRGB_t *  color, const cRGB_t *  color2) {
	color->r = color2->r;
	color->g = color2->g;
	color->b = color2->b;
}

void 
crgb_crgb_add(cRGB_t *  color, const cRGB_t *  color2) {
	color->r += color2->r;
	color->g += color2->g;
	color->b += color2->b;
}

void 
crgb_add(cRGB_t *  color, const float add) {
	color->r += add;
	color->g += add;
	color->b += add;
}

void 
color_add(color_t *  color, const int add) {
	*color = COL_CREATE_RGBA( (COL_GET_R(*color) + add), 
						     (COL_GET_G(*color) + add), 
							 (COL_GET_B(*color) + add),
							 (COL_GET_A(*color) + add));
}

void 
color_add_dest(color_t *  dest, const color_t *  color, const int add) {
	*dest = COL_CREATE_RGBA( (COL_GET_R(*color) + add), 
							(COL_GET_G(*color) + add), 
							(COL_GET_B(*color) + add),
							(COL_GET_A(*color) + add));
}

void 
crgb_mul(cRGB_t *  color, const float mul) {
	color->r *= mul;
	color->g *= mul;
	color->b *= mul;
}

void 
color_mul(color_t *  color, const int mul) {
	*color = COL_CREATE_RGBA( (COL_GET_R(*color) * mul), 
						     (COL_GET_G(*color) * mul), 
						     (COL_GET_B(*color) * mul),
							 (COL_GET_A(*color) * mul));
}

void 
color_mul_dest(color_t *  dest, const color_t *  color, const int mul) {
	*dest = COL_CREATE_RGBA( (COL_GET_R(*color) * mul), 
						     (COL_GET_G(*color) * mul), 
						     (COL_GET_B(*color) * mul),
							 (COL_GET_A(*color) * mul));
}

void 
color_mulf(color_t *  color, const float mul) {
	*color = COL_CREATE_RGBA( (int)((float)COL_GET_R(*color) * mul), 
						      (int)((float)COL_GET_G(*color) * mul), 
						      (int)((float)COL_GET_B(*color) * mul),
							  (int)((float)COL_GET_A(*color) * mul));
}

void 
color_mulf_dest(color_t *  dest, const color_t *  color, const float mul) {
	*dest = COL_CREATE_RGBA( (int)((float)COL_GET_R(*color) * mul), 
						     (int)((float)COL_GET_G(*color) * mul), 
						     (int)((float)COL_GET_B(*color) * mul),
							 (int)((float)COL_GET_A(*color) * mul));
}

void 
crgb_print(const cRGB_t *  color) {
	printf("R,G,B=%f,%f,%f\n", color->r, color->g, color->b);
}

void color_print(const color_t *  color) {
	printf("R,G,B,A=%ld,%ld,%ld,%ld\n", COL_GET_R(*color), COL_GET_G(*color), COL_GET_B(*color), COL_GET_A(*color));
}

void color_truncate(int *  value) {
	int * val = value;
	int _val = *val;
	if ( _val > 255 ) *val = 255;
	else if (_val < 0) *val = 0;
}

void 
color_brightness_255_dest(color_t *  dest, const color_t *  color, const int brightness) {
	*dest = *color;
	int r = COL_GET_R(*dest) + brightness,
		g = COL_GET_G(*dest) + brightness,
		b = COL_GET_B(*dest) + brightness;
	color_truncate(&r);
	color_truncate(&g);
	color_truncate(&b);
	
	COL_SET_R(*dest,r);
	COL_SET_G(*dest,g); 
	COL_SET_B(*dest,b);
}

void crgb_truncate(float *  value) {
	float * val = value;
	float _val = *val;
	if ( _val > 255.f ) *val = 255.f;
	else if (_val < 0.f) *val = 0.f;
}

void 
crgb_brightness_255_dest(cRGB_t *  dest, const cRGB_t *  color, const float brightness) {
	crgb_crgb_copy(dest, color);
	crgb_add(dest, brightness);
	crgb_truncate(&dest->r);
	crgb_truncate(&dest->g);
	crgb_truncate(&dest->b);
}

float 
crgb_contrast_factor_255(const float contrast) {
	float usedcontrast = contrast;
	if(usedcontrast > 255.f) usedcontrast = 255.f;
	else if(usedcontrast < -255.f) usedcontrast = -255.f;
	return (259.f*(usedcontrast + 255.f)) / (255.f*(259.f - usedcontrast)) ; 
}  


float color_contrast_factor_255(const int contrast) {
	float usedcontrast = (float)contrast;
	if(usedcontrast > 255.f) usedcontrast = 255.f;
	else if(usedcontrast < -255.f) usedcontrast = -255.f;
	return (259.f*(usedcontrast + 255.f)) / (255.f*(259.f - usedcontrast)) ; 
}

void 
crgb_contrast_255_dest(cRGB_t *  dest, const cRGB_t *  color, const float contrast_factor) {
	crgb_crgb_copy(dest, color);
	dest->r = (contrast_factor * (dest->r - 128.f)) + 128.f;
	dest->g = (contrast_factor * (dest->g - 128.f)) + 128.f;
	dest->b = (contrast_factor * (dest->b - 128.f)) + 128.f;
	crgb_truncate(&dest->r);
	crgb_truncate(&dest->g);
	crgb_truncate(&dest->b);
}

void 
color_contrast_255_dest(color_t *  dest, const color_t *  color, const float contrast_factor) {
	*dest = *color;
	int r = (int)((contrast_factor * ((float)(COL_GET_R(*color)) - 128.f)) + 128.f),
		g = (int)((contrast_factor * ((float)(COL_GET_G(*color)) - 128.f)) + 128.f),
		b = (int)((contrast_factor * ((float)(COL_GET_B(*color)) - 128.f)) + 128.f);
	color_truncate(&r);
	color_truncate(&g);
	color_truncate(&b);
	
	COL_SET_R(*dest,r);
	COL_SET_G(*dest,g); 
	COL_SET_B(*dest,b);

}