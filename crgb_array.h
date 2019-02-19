#ifndef CRGB_ARRAY_H
#define CRGB_ARRAY_H

#include "color.h"
#include "array.h"

void assoc_crgb_value(void *  array_entry, int newidx ,void *  init_value);
void assoc_crgb_ref(void *  array_entry, int newidx ,void *  init_value);

array_t * crgb_array_new(int cnt_i);
array_t * crgb_array2D_new(int cnt_i, int cnt_j);

void crgb_array_init(array_t *  array, cRGB_t *  init_value);

array_error_t crgb_array_get(array_t *  array, int index,cRGB_t *  result);
array_error_t crgb_array_get_ref(array_t *  array, int index,cRGB_t **  result);

array_error_t crgb_array2D_get(array_t *  array, int i, int j, cRGB_t *  result);
array_error_t crgb_array2D_get_ref(array_t *  array, int i, int j, cRGB_t **  result);

array_error_t crgb_array_set(array_t *  array, int index, cRGB_t *  value);
array_error_t crgb_array2D_set(array_t *  array, int i, int j, cRGB_t *  value);

#if 0
	/**
		additional for color_t
	*/
#endif

void assoc_color_value(void *  array_entry, int newidx ,void *  init_value);
void assoc_color_ref(void *  array_entry, int newidx ,void *  init_value);

array_t * color_array_new(int cnt_i);
array_t * color_array2D_new(int cnt_i, int cnt_j);

void color_array_init(array_t *  array, color_t *  init_value);

array_error_t color_array_get(array_t *  array, int index,color_t *  result);
array_error_t color_array_get_ref(array_t *  array, int index,color_t **  result);

array_error_t color_array2D_get(array_t *  array, int i, int j, color_t *  result);
array_error_t color_array2D_get_ref(array_t *  array, int i, int j, color_t **  result);

array_error_t color_array_set(array_t *  array, int index, color_t *  value);
array_error_t color_array2D_set(array_t *  array, int i, int j, color_t *  value);


#endif
