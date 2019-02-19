#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "crgb_array.h"

int 
main() {
	#ifdef debug
		printf("test collections color array:\n");
	#endif

	array_t * oneD = crgb_array_new(10);
	array_t * twoD = crgb_array2D_new(5,5);
	
	cRGB_t blue = { 0.f , 0.f, 1.f};
	cRGB_t red = { 1.f , 0.f, 0.f};
	
	crgb_array_init(oneD, &blue);
	crgb_array_init(twoD, &red);
	
	array_error_t farray_res;
	
	cRGB_t black = { 0.f , 0.f, 0.f};
	cRGB_t white = { 1.f , 1.f, 1.f};
	
	farray_res = crgb_array_set(oneD, 8, &black);
	assert(farray_res == ARRAY_ERR_OK);
	
	farray_res = crgb_array2D_set(twoD, 3, 3, &white);
	assert(farray_res == ARRAY_ERR_OK);

	cRGB_t result_value;
	cRGB_t * result_ref;
	
	farray_res = crgb_array_get(oneD, 2, &result_value);
	assert(farray_res == ARRAY_ERR_OK);
	assert(&result_value != &blue);
	assert(result_value.r == 0.f);
	assert(result_value.g == 0.f);
	assert(result_value.b == 1.f);
	
	farray_res = crgb_array2D_get(twoD, 1, 3, &result_value);
	assert(farray_res == ARRAY_ERR_OK);
	assert(&result_value != &red);
	assert(result_value.r == 1.f);
	assert(result_value.g == 0.f);
	assert(result_value.b == 0.f);
	
	farray_res = crgb_array_get(oneD, 8, &result_value);
	assert(farray_res == ARRAY_ERR_OK);
	assert(&result_value != &black);
	assert(result_value.r == 0.f);
	assert(result_value.g == 0.f);
	assert(result_value.b == 0.f);
	
	farray_res = crgb_array2D_get(twoD, 3, 3, &result_value);
	assert(farray_res == ARRAY_ERR_OK);
	assert(&result_value != &white);
	assert(result_value.r == 1.f);
	assert(result_value.g == 1.f);
	assert(result_value.b == 1.f);

	cRGB_t * carray = (cRGB_t *)oneD->entries;

	carray[4].r = 47.f;
	carray[4].g = 1.f;
	carray[4].b = 1.f;
	
	farray_res = crgb_array_get_ref(oneD, 4, &result_ref);
	assert(farray_res == ARRAY_ERR_OK);
	assert(result_ref == &carray[4]);
	assert(result_ref->r == 47.f);
	assert(result_ref->g == 1.f);
	assert(result_ref->b == 1.f);
	
	carray = (cRGB_t *)twoD->entries;
	farray_res = crgb_array2D_get_ref(twoD, 2, 3, &result_ref);
	assert(farray_res == ARRAY_ERR_OK);
	assert(result_ref == &carray[17]);
	assert(result_ref->r == 1.f);
	assert(result_ref->g == 0.f);
	assert(result_ref->b == 0.f);
	
	farray_res = crgb_array_get(oneD, 44, &result_value);
	assert(farray_res == ARRAY_ERR_OVERFLOW);
	
	farray_res = crgb_array2D_get(twoD, 34, 3, &result_value);
	assert(farray_res == ARRAY_ERR_OVERFLOW);
	
	farray_res = crgb_array_get_ref(oneD, 44, &result_ref);
	assert(farray_res == ARRAY_ERR_OVERFLOW);
	
	farray_res = crgb_array2D_get_ref(twoD, 34, 3, &result_ref);
	assert(farray_res == ARRAY_ERR_OVERFLOW);
	
	farray_res = crgb_array_get(oneD, -44, &result_value);
	assert(farray_res == ARRAY_ERR_UNDERFLOW);
	
	farray_res = crgb_array2D_get(twoD, -34, 3, &result_value);
	assert(farray_res == ARRAY_ERR_UNDERFLOW);
	
	farray_res = crgb_array_get_ref(oneD, -44, &result_ref);
	assert(farray_res == ARRAY_ERR_UNDERFLOW);
	
	farray_res = crgb_array2D_get_ref(twoD, -34, 3, &result_ref);
	assert(farray_res == ARRAY_ERR_UNDERFLOW);
	
	array_free(oneD);
	array_free(twoD);
	
	#ifdef debug
		printf("EO test collections color array:\n");
	#endif
	
	return 0;
}
