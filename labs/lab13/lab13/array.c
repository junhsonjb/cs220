
#include <array.h>

int ** allocateArray() {
	int **array=NULL;
	int r;
	array=(int **)malloc(sizeof(int*) * ROWS);
	for(r=0; r<ROWS; r++) {
		array[r]=(int *)malloc(sizeof(int) * COLS);
	}
	return array;
}

void freeArray(int **array) {
	int r;
	for(r=0; r<ROWS; r++) {
		free(array[r]);
	}
	free(array);
}