#include "crgb_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void 
assoc_crgb_value(void *  array_entry, int newidx ,void *  init_value){
	crgb_crgb_copy(((cRGB_t*)array_entry+newidx), ((cRGB_t*)init_value));
}

void 
assoc_crgb_ref(void *  array_entry, int newidx ,void *  init_value){
	*((cRGB_t **)array_entry+newidx) = ((cRGB_t *)init_value);
}

array_t * 
crgb_array_new(int cnt_i){
	return array1D_new(cnt_i, sizeof(cRGB_t));
}

array_t * 
crgb_array2D_new(int cnt_i, int cnt_j){
	return array2D_new(cnt_i, cnt_j, sizeof(cRGB_t));
}

void 
crgb_array_init(array_t *  array, cRGB_t *  init_value){
	array_init(array, init_value, assoc_crgb_value);
}

array_error_t 
crgb_array_get(array_t *  array, int index, cRGB_t *  result){
	return array_get(array, index, assoc_crgb_value, result);
}

array_error_t 
crgb_array2D_get(array_t *  array, int i, int j, cRGB_t *  result){
	return array2D_get(array, i, j, assoc_crgb_value, result);
}

array_error_t 
crgb_array_get_ref(array_t *  array, int index, cRGB_t **  result){
	return array_get(array, index, assoc_crgb_ref, result);
}

array_error_t 
crgb_array2D_get_ref(array_t *  array, int i, int j, cRGB_t **  result){
	return array2D_get(array, i, j, assoc_crgb_ref, result);
}

array_error_t 
crgb_array_set(array_t *  array, int index, cRGB_t *  value){
	return array_set(array, index, value, assoc_crgb_value);
}

array_error_t 
crgb_array2D_set(array_t *  array, int i, int j, cRGB_t *  value){
	return array2D_set(array, i, j, value, assoc_crgb_value);
}

#if 0
	//implementation for color_t
#endif

void 
assoc_color_value(void *  array_entry, int newidx ,void *  init_value){
	*((color_t*)array_entry+newidx) = *((color_t*)init_value);
}

void 
assoc_color_ref(void *  array_entry, int newidx ,void *  init_value){
	*((color_t **)array_entry+newidx) = ((color_t *)init_value);
}

array_t * 
color_array_new(int cnt_i){
	return array1D_new(cnt_i, sizeof(color_t));
}

array_t * 
color_array2D_new(int cnt_i, int cnt_j){
	return array2D_new(cnt_i, cnt_j, sizeof(color_t));
}

void 
color_array_init(array_t *  array, color_t *  init_value){
	array_init(array, init_value, assoc_color_value);
}

array_error_t 
color_array_get(array_t *  array, int index, color_t *  result){
	return array_get(array, index, assoc_color_value, result);
}

array_error_t 
color_array2D_get(array_t *  array, int i, int j, color_t *  result){
	return array2D_get(array, i, j, assoc_color_value, result);
}

array_error_t 
color_array_get_ref(array_t *  array, int index, color_t **  result){
	return array_get(array, index, assoc_color_ref, result);
}

array_error_t 
color_array2D_get_ref(array_t *  array, int i, int j, color_t **  result){
	return array2D_get(array, i, j, assoc_color_ref, result);
}

array_error_t 
color_array_set(array_t *  array, int index, color_t *  value){
	return array_set(array, index, value, assoc_color_value);
}

array_error_t 
color_array2D_set(array_t *  array, int i, int j, color_t *  value){
	return array2D_set(array, i, j, value, assoc_color_value);
}
