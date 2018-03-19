#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned long floatx;

//the declaration for our main function in this program
floatx doubleToFloatx(double in, int totalBits, int exponentBits);

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
			//int value = *(int *)&in;//The binary rep. of the in float
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
	 * test */

}

floatx doubleToFloatx(double in, int totalBits, int exponentBits) {

	floatx ret = 0;
	//long sbit;
	//long ebits;
	//long fbits;
	unsigned long val = 0;

	//copy the bits of in into the result variable
	memcpy(&val, &in, sizeof(in));
	//printf("result - %X\n", result);

	//the value for us to return
	//floatx ret;

	//the binary representation of in stored as an integer
	//int value = *(int *)&in;//this didn't work

	//union udouble {
	//	double d;
	//	unsigned long u;
	//};
	//union udouble value;
	//value.d = in;
	//int val = value.u;
	//printf("%x\n", val);

	/*let's start simple, by assigning the lengths of the S, EXP,
	 * and FRAC values based off of this function's input */
	int s = 1; //the lenght of the S valeu -- as always
	int e = exponentBits; //the length of the EXP value
	int f = totalBits - (e + s); //the length of the FRAC value

	//the ACTUAL VALUES of the S, EXP, and FRAC fields (to be set)
	int sbit, ebits, fbits;
 
	/* store the very first relevant bit into sbit (since it is the 
	 * S value) */
	sbit = val >> (f + e);
	/* Now, if the in value is negative, sbit will be 1. If it's
	 * positive, sbit will be 0 */

	
	/*okay, now the S bit is taken care of, let's look at the EXP
	 * field, since it is next */

	//setting the ebits VALUE
	/* We can do this by shifting in to the right (>>) by f
	 * and from there we get ...0000SEEEE. 
	 * and then if s = 0 we can OR that resulting value with 0
	 * to get the value of EXP in decimal*/

	/*if sbit is 0, then the number in question is potive. 
	 * Thus, we can shift in to the right by f bits and OR 
	 * it with 0 to get the EXP value */
	if (sbit == 0) { //here we go

		/* Here, we're shifting in to the right by f bits, 
		 * then we're taking the resulting value and ORing
		 * it with 0000... to get the value into ebits. This
		 * way, ebits will hold the value that represents the
		 * EXP field */
		ebits = (val >> f) | 0;

	} else if (sbit == 1) { //the only other option

		/* To get that first bit (sbit) to become go from
		 * a 1 to a 0 (so that we can simply do like we did
		 * if sbit was equal to 0), all we need to do is shift
		 * in to the left, then shift it back to the right.
		 * This way, we lose the leftmost value, so with the
		 * second shift we bring back a zero */
		ebits = (val >> f) | 0;
		ebits = ebits << (totalBits - e);
		ebits = ebits << 1; //this is where we lose that 1 that we don't want
		ebits = ebits >> 1; //now all we have to do is move things back
		ebits = ebits >> (totalBits - e);
		ebits = ebits | 0;
		/* ebits is now equal to the EXP value without the S or FRAC values */

	}

	/* Now, we've assigned the sbit and ebits variables, it's time
	 * to get the fbits variable (FRAC bit field) */

	/* To do this, we can shift all the bits to the left, so that we
	 * lose the S and EXP bits. We can do this by shifting to the right
	 * by (totalBits - f) bits. Then we shift back by the same amount 
	 * and all we'll have is the bits for FRAC. */

	//here we go
	fbits = val << (totalBits - f); //we've now lost all irrelevant bits
	fbits = fbits >> (totalBits - f); //shift back by the same am't to have correct value
	fbits = fbits | 0; //just to be safe!

	/* We now have the correct values of S, EXP, and FRAC! Hooray! */
	//let's just do some testing
	//printf("%x\n", val);

	/* What we need to do here:
	 * We have the S, EXP, and FRAC components, we just need to do some
	 * bit twiddling to get them into the floatx ret in the format:
	 * ...000SEEEEFFFFFFFF (adjusted to match the specified number of
	 * E - ~EXP~ and F - ~FRAC~ bits) */
	ret = val; //fix this value (explained directly above)
	return ret;

}
