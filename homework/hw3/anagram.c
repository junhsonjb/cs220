#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

	//check that user has entered 3 command line args, as desired
	if (argc < 3) {
		printf("please enter %s <string1> <string2>\n", argv[0]);
		return 1;
	}

	//just for testing
	//printf("%s\n", argv[1]);
	//printf("%s\n", argv[2]);

	char a [100];
	char b [100];

	strcpy(a, argv[1]);
	strcpy(b, argv[2]);

	/* THIS STUFF WAS JUST FOR TESTING */
	// printf("%s\n", a);
	// printf("%s\n", b);
    //
	// return 0;

	int acount = 0;
	int bcount = 0;

	/* compare the lengths of each str, if no match, we know theres no anagram */
 	for (int i = 0; i < strlen(a); i++) {
 		if ( (a[i] >= 65 && a[i] <=90) || (a[i] >= 97 && a[i] <=122) ) {
 			acount++;
 		}
 	}


 	for (int i = 0; i < strlen(b); i++) {
 		if ( (b[i] >= 65 && b[i] <=90) || (b[i] >= 97 && b[i] <=122) ) {
 			bcount++;
 		}
 	}

	/* if acount is the same as bcount, then both strings are the same
	length, if not, we can stop right there */
	if (acount != bcount) {
		printf("%s is not an anagram of %s\n", a, b);
		return 1;
	}

	//for all chars in a, get a count of those instances in
	//a and in b, then compare, if same then a is an anagram
	//of b


	int ainstances = 0;
	int binstances = 0;

	for (int i = 0; i < strlen(a); i++) {

		for (int j = 0; j < strlen(b); j++) {

			if (a[i] == b[j]) {
				a[i] = '-';
				b[j] = '-';
				break;
			}

		}

	}

	acount = 0;
	bcount = 0;

	/* compare the lengths of each str, if no match, we know theres no anagram */
 	for (int i = 0; i < strlen(a); i++) {
 		if ( (a[i] >= 65 && a[i] <=90) || (a[i] >= 97 && a[i] <=122) ) {
 			acount++;
 		}
 	}


 	for (int i = 0; i < strlen(b); i++) {
 		if ( (b[i] >= 65 && b[i] <=90) || (b[i] >= 97 && b[i] <=122) ) {
 			bcount++;
 		}
 	}

	if (acount == 0 && bcount == 0) {
		printf("%s is an anagram of %s\n", argv[1], argv[2]);
		return 0;
	}


	/* This was for testing */
//	printf("ainstances - %d\nbinstances - %d\n", ainstances, binstances);

	//if we've made it to this point without calling any of the
	//return statements, then the 2 strings are anagrams!
	//printf("%s is an anagram of %s\n", a, b);

	printf("%s is not an anagram of %s\n", argv[1], argv[2]);
	return 1;
}
