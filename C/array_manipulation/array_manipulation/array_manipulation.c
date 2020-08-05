#include "array_manipulation.h"
#include "assert.h"
#include <stdio.h>


void Array_Print(Array *array)
{
	printf("\n\n");
	for (int i = 0; i < array->size; i++) {
		printf("[%d]\t-\t%d: %d\n", i, (array->buff_ptr + i), array->buff_ptr[i]);
	}
	printf("\n\n");
}

void Array_ShiftToLeft(Array *array, int index)
{
	assert(index < array->size && index >= 0);
	for (int i = index; i < array->size - 1; i++) {
		array->buff_ptr[i] = array->buff_ptr[i + 1];
	}
}

void Array_ShiftToRight(Array *array, int index)
{
	assert(index < array->size && index >= 0);
	for (int i = array->size - 2; i >= index; i--) {
		array->buff_ptr[i + 1] = array->buff_ptr[i];
	}
}

void Array_DeleteElement(Array* array, int index)
{
	assert(array->size > 1);
	int* temp_ptr;
	Array_ShiftToLeft(array, index);
	array->size -= 1;
	temp_ptr = (int*)realloc(array->buff_ptr, array->size * sizeof(int));
	array->buff_ptr = temp_ptr;
}

void Array_InsertElement(int value, int index, Array *array)
{
	int* temp_ptr;
	array->size += 1;
	temp_ptr = (int*)realloc(array->buff_ptr, array->size * sizeof(int));
	array->buff_ptr = temp_ptr;
	Array_ShiftToRight(array, index);
	array->buff_ptr[index] = value;
}