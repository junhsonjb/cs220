#include <stdio.h>
#include <string.h>

char * strcatm(char start[], char tail[]);
void strcatp(char start[], char tail[]);

int main(int argc, char **argv) {

	if (argc < 3) {
		printf("Please enter ./%s <start> <tail>\n", argv[0]);
		return 1;
	}
	
	char buffer[127];
	strcpy(buffer, argv[1]);
	strcatm(buffer, argv[2]);
	printf("strcat matrix yields: %s\n", buffer);

	strcpy(buffer, argv[1]);
	strcatp(buffer, argv[2]);
	printf("strcat pointer form yields: %s\n", buffer);


	return 0;
}

char * strcatm(char start[], char tail[]) {

	int count = 0;
	for (int i = strlen(start); i < (strlen(start) + strlen(tail)); i++) {
		start[i] = tail[count];
		count++;
	}

	return start;
}

void strcatp(char start[], char tail[]) {
	start = (start + strlen(start));
	for (int i = strlen(start); i < (strlen(start) + strlen(tail)); i++) {
		*start = *tail;
		//tail++; //KEEP THIS CODE OUT, IT CHANGES THE FIRST CHAR IN TAIL
	}
}
