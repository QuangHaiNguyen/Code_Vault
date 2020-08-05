typedef struct {
	int size;
	int *buff_ptr;
}Array;

void Array_Print(Array* array);
void Array_ShiftToLeft(Array* array, int index);
void Array_ShiftToRight(Array* array, int index);
void Array_InsertElement(int value, int index, Array* array);
void Array_DeleteElement(Array* array, int index);