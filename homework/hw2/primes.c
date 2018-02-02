#include <stdio.h>
#include <stdlib.h>

int minFact(int a);

int main(int argc, char** argv) {

	if (argc < 2) {
		printf("Please invoke main with: %s <value>\n", argv[0]);
		return 1;
	}

	int value = atoi(argv[1]);
	if ( value <= 0 ) {
		printf("Value must be greater than 0\n");
		return 1;
	}

	int min = minFact(value);
	printf("%d\n", min);

	int num = value;
	int factor = minFact(num);
	printf("%d = ", value);

	while ((num / minFact(num)) != 1) {
		num = num / minFact(num);
		printf("%d x ", minFact(num));
	}

	printf("%d ", factor);


	return 0;
}

int minFact(int a) {

	int factor = 2;
	//if (a % factor == 0) return factor;
	while (a % factor != 0) {
		factor++;
	}

	return factor;

}
