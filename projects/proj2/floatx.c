#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long floatx;

int main(int argc, char **argv) {

	//check the input, end program and give error msg if wrong
	if (argc < 3) {
		printf("please use format: %s <totBits> <expBits>\n", argv[0]);
		return 1;
	}

	//Assign the neccessary command line arguments to variables
	int totalBits = atoi(argv[1]);
	int exponentBits = atoi(argv[2]);

	//Now we read doubles from stdin (as directed in instructions)
	while(!feof(stdin)) {

		double in = NAN; //NAN defined in math.h
		if (1 == scanf("%lf", &in)) {
			floatx fx = doubleToFloatx(in, totalBits, exponentBits);
			printf("%14.8g = float(%d, %d) : %016lx\n", in, totalBits, exponentBits, fx);
		} else {
			char buf[100];
			scanf("%s", buf);
			printf("Input : %s not recognized as a double\n", buf);
		}

	}
	/* TODO
	 * Implement the doubleToFloat() function
	 * also declare doubleToFloat() function at top of code too
	 * test */

}
