#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {


	if (argc != 2) {
		printf("please invoke as: %s <inputString>\n", argv[0]);
		return 1;
	}

	char buff[100];
	strcpy(buff, argv[1]);

	return 0;

}

int badfunction() {

	printf("Hahahah, you found me!");
	return 0;

}
