#include <stdio.h>
#include <string.h>

/* ----------------------------------------------------------------------
 * I just want to make it clear that I am not using the above 
 * #include statements. I am not using any of the standard
 * library functions in my strcatm, strcatp, or mystrlen functions
 * (explanation about the 'mystrlen' method is below. Prof Bartenstein
 * said in class that we could use the standard library functions in our
 * main methods but not in the other methods we had to wirte. Also, the 
 * instructions make it necessary with things like using strcpy in the main.
 * I just wanted to make note of that. Thanks! 
 * ---------------------------------------------------------------------- */

char * strcatm(char start[], char tail[]);
void strcatp(char start[], char tail[]);
/* ----------------------------------------------------------
 * Initially, I was using the strlen method because I thought
 * it was allowed. I then found out that it wasn't allowed,
 * so I wrote my own strlen method, called 'mystrlen'. This
 * way, I could still have that functionality without breaking
 * any of the given rules. strlen was the only unallowed method
 * that I was using.
 *  --------------------------------------------------------- */
int mystrlen(char source[]); /* I'm writing my own strlen (explained above) */

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
	for (int i = mystrlen(start); i < (mystrlen(start) + mystrlen(tail)); i++) {
		start[i] = tail[count];
		count++;
	}

	return start;
}

void strcatp(char start[], char tail[]) {
	start = (start + mystrlen(start));
	for (int i = mystrlen(start); i < (mystrlen(start) + mystrlen(tail)); i++) {
		*start = *tail;
		//tail++; //KEEP THIS CODE OUT, IT CHANGES THE FIRST CHAR IN TAIL
	}
}

int mystrlen(char source[]) {
	
	int ret = 0;
	while(0x00 != source[ret]) {
		ret++;
	}

	return ret;
}
