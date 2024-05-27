#ifndef CRGB_ARRAY_H
#define CRGB_ARRAY_H

#include "color.h"
#include "array.h"

void assoc_crgb_value(void *  array_entry, int newidx ,void *  init_value);
void assoc_crgb_ref(void *  array_entry, int newidx ,void *  init_value);

Array * crgb_array_new(int cnt_i);
Array * crgb_array2D_new(int cnt_i, int cnt_j);

void crgb_array_init(Array *  array, ColorRGB *  init_value);

ArrayError crgb_array_get(Array *  array, int index,ColorRGB *  result);
ArrayError crgb_array_get_ref(Array *  array, int index,ColorRGB **  result);

ArrayError crgb_array2D_get(Array *  array, int i, int j, ColorRGB *  result);
ArrayError crgb_array2D_get_ref(Array *  array, int i, int j, ColorRGB **  result);

ArrayError crgb_array_set(Array *  array, int index, ColorRGB *  value);
ArrayError crgb_array2D_set(Array *  array, int i, int j, ColorRGB *  value);

#if 0
	/**
		additional for Color
	*/
#endif

void assoc_color_value(void *  array_entry, int newidx ,void *  init_value);
void assoc_color_ref(void *  array_entry, int newidx ,void *  init_value);

Array * color_array_new(int cnt_i);
Array * color_array2D_new(int cnt_i, int cnt_j);

void color_array_init(Array *  array, Color *  init_value);

ArrayError color_array_get(Array *  array, int index,Color *  result);
ArrayError color_array_get_ref(Array *  array, int index,Color **  result);

ArrayError color_array2D_get(Array *  array, int i, int j, Color *  result);
ArrayError color_array2D_get_ref(Array *  array, int i, int j, Color **  result);

ArrayError color_array_set(Array *  array, int index, Color *  value);
ArrayError color_array2D_set(Array *  array, int i, int j, Color *  value);


#endif
