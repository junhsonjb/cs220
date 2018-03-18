#include <stdio.h>
#include "format.h"

int main(int argc, char **argv) {



	// Example scalars - jumbled so addresses wont be sequential
	float f0=0.0;	float f4=4.0; 		float f1=1.0;		 	float f7=7.0;
	float f2=2.0;	float f10=10.0;	float f3=3.0;			float f5=5.0;
	float f9=9.0;	float f6=6.0;			float f11=11.0;	float f8=8.0;

	// Example vectors - See code below for initializations
	float vec1[4];
	float vec2[4];
	float vec3[4];
	float * vecPtr1[4];
	float * vecPtr2[4];
	float * vecPtr3[4];

	// Example arrays - three different flavors!
	float arr2d[3][4];
	float *arrPtrs1d[3];
	float **arrPtrsPtrs1d[3];

	// Initialize vectors
	vec1[0]=f0; vec1[1]=f1; vec1[2]=f2; vec1[3]=f3;
	vec2[0]=f4; vec2[1]=f5; vec2[2]=f6; vec2[3]=f7;
	vec3[0]=f8; vec3[1]=f9; vec3[2]=f10; vec3[3]=f11;

	vecPtr1[0]=&f0; vecPtr1[1]=&f1; vecPtr1[2]=&f2; vecPtr1[3]=&f3;
	vecPtr2[0]=&f4; vecPtr2[1]=&f5; vecPtr2[2]=&f6; vecPtr2[3]=&f7;
	vecPtr3[0]=&f8; vecPtr3[1]=&f9; vecPtr3[2]=&f10; vecPtr3[3]=&f11;

	// Initialize arrays
	arr2d[0][0]=f0; arr2d[0][1]=f1; arr2d[0][2]=f2; arr2d[0][3]=f3;
	arr2d[1][0]=f4; arr2d[1][1]=f5; arr2d[1][2]=f6; arr2d[1][3]=f7;
	arr2d[2][0]=f8; arr2d[2][1]=f9; arr2d[2][2]=f10; arr2d[2][3]=f11;

	arrPtrs1d[0]=(float *)&vec1;
	arrPtrs1d[1]=(float *)&vec2;
	arrPtrs1d[2]=(float *)&vec3;

	arrPtrsPtrs1d[0]=(float **)&vecPtr1;
	arrPtrsPtrs1d[1]=(float **)&vecPtr2;
	arrPtrsPtrs1d[2]=(float **)&vecPtr3;

	/*------------------------------------------------------------------------
		Insert code to print the structure of some of the
		above variables...
	--------------------------------------------------------------------------*/
	printFormat( "f0:",formatScalar(&f0));
	printFormat( "vec1", formatVector(vec1, 4));
	printFormat( "arr2d", formatMatrix(arr2d, 3, 4)  );
	printFormat( "arrPtrs1d", formatPointerList(arrPtrs1d, 3) );
	printFormat( "arrPtrsPtrs1d:", formatPointerPointerList(arrPtrsPtrs1d, 3, 3) );

	int row; int col;
	for(row=0;row<3;row++) {
		for(col=0;col<4;col++) {
			printf("Working on row %d, column %d\n",row,col);
	/*------------------------------------------------------------------------
		Insert code to analyze the arrays declared above
		so you can answer the questions in Lab05_report.txt
	--------------------------------------------------------------------------*/
			printf("%f\n", (float)arr2d[row][col]);
			printf("%d\n", arrPtrs1d[row][col]);
			printf("%d\n", arrPtrsPtrs1d[row][col]);
		}
	}
	return 0;
}
