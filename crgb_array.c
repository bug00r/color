#include "crgb_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void 
assoc_crgb_value(void *  array_entry, int newidx ,void *  init_value){
	crgb_crgb_copy(((ColorRGB*)array_entry+newidx), ((ColorRGB*)init_value));
}

void 
assoc_crgb_ref(void *  array_entry, int newidx ,void *  init_value){
	*((ColorRGB **)array_entry+newidx) = ((ColorRGB *)init_value);
}

Array * 
crgb_array_new(int cnt_i){
	return array1D_new(cnt_i, sizeof(ColorRGB));
}

Array * 
crgb_array2D_new(int cnt_i, int cnt_j){
	return array2D_new(cnt_i, cnt_j, sizeof(ColorRGB));
}

void 
crgb_array_init(Array *  array, ColorRGB *  init_value){
	array_init(array, init_value, assoc_crgb_value);
}

ArrayError 
crgb_array_get(Array *  array, int index, ColorRGB *  result){
	return array_get(array, index, assoc_crgb_value, result);
}

ArrayError 
crgb_array2D_get(Array *  array, int i, int j, ColorRGB *  result){
	return array2D_get(array, i, j, assoc_crgb_value, result);
}

ArrayError 
crgb_array_get_ref(Array *  array, int index, ColorRGB **  result){
	return array_get(array, index, assoc_crgb_ref, result);
}

ArrayError 
crgb_array2D_get_ref(Array *  array, int i, int j, ColorRGB **  result){
	return array2D_get(array, i, j, assoc_crgb_ref, result);
}

ArrayError 
crgb_array_set(Array *  array, int index, ColorRGB *  value){
	return array_set(array, index, value, assoc_crgb_value);
}

ArrayError 
crgb_array2D_set(Array *  array, int i, int j, ColorRGB *  value){
	return array2D_set(array, i, j, value, assoc_crgb_value);
}

#if 0
	//implementation for Color
#endif

void 
assoc_color_value(void *  array_entry, int newidx ,void *  init_value){
	*((Color*)array_entry+newidx) = *((Color*)init_value);
}

void 
assoc_color_ref(void *  array_entry, int newidx ,void *  init_value){
	*((Color **)array_entry+newidx) = ((Color *)init_value);
}

Array * 
color_array_new(int cnt_i){
	return array1D_new(cnt_i, sizeof(Color));
}

Array * 
color_array2D_new(int cnt_i, int cnt_j){
	return array2D_new(cnt_i, cnt_j, sizeof(Color));
}

void 
color_array_init(Array *  array, Color *  init_value){
	array_init(array, init_value, assoc_color_value);
}

ArrayError 
color_array_get(Array *  array, int index, Color *  result){
	return array_get(array, index, assoc_color_value, result);
}

ArrayError 
color_array2D_get(Array *  array, int i, int j, Color *  result){
	return array2D_get(array, i, j, assoc_color_value, result);
}

ArrayError 
color_array_get_ref(Array *  array, int index, Color **  result){
	return array_get(array, index, assoc_color_ref, result);
}

ArrayError 
color_array2D_get_ref(Array *  array, int i, int j, Color **  result){
	return array2D_get(array, i, j, assoc_color_ref, result);
}

ArrayError 
color_array_set(Array *  array, int index, Color *  value){
	return array_set(array, index, value, assoc_color_value);
}

ArrayError 
color_array2D_set(Array *  array, int i, int j, Color *  value){
	return array2D_set(array, i, j, value, assoc_color_value);
}
