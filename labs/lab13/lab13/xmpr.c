
#include <stdio.h>
#include <array.h>


int main(int argc,char **argv) {

	int r,c;
	int **matrix=allocateArray();

	foreachrow(r) {
		foreachcol(c) {
			matrix[r][c] = 3;
		}
	}

	freeArray(matrix);
	printf("\nMatrix filled row by row\n");
	return(0);
}

