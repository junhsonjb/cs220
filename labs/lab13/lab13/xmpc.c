
#include <stdio.h>
#include <array.h>


int main(int argc,char **argv) {

	int r,c;
	int **matrix=allocateArray();

	foreachcol(c) {
		foreachrow(r) {
			matrix[r][c] = 3;
		}
	}

	freeArray(matrix);
	printf("\nMatrix filled column by column\n");
	return(0);
}