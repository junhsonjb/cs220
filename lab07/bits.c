#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int isOdd(int x);
long power2(int x);
long n1bits(int x);
char nthbit(long x,int n);
long bitRange(long x,int fb,int nbits);
long negate(long x);

char * longBits(char *buf,long x);

int main(int argc, char **argv) {
	if (argc<3) {
		printf("Please invoke as %s <n> <m>\n",argv[0]);
		printf("  where 0<=n<60\n");
		return 1;
	}

	int n=atoi(argv[1]);
	if (n<0 || n>59) {
		printf("Please invoke as %s <n> <m>\n",argv[0]);
		printf("  where 0<=n<60\n");
		return 1;
	}

	long m=atol(argv[2]);
	char buf[1024];

	printf("n=%d is %s\n",n,isOdd(n)?"odd":"even");
	printf("2 to the n power is %ld\n",power2(n));
	printf("n one bits =%ld or in bits = %s\n",n1bits(n),longBits(buf,n1bits(n)));
	printf("m=%s\n",longBits(buf,m));
	printf("The %dth bit of %ld is %d\n",n,m,nthbit(m,n));
	printf("Bits %d to %d of %ld are 0x%lX\n",n,n+5,m,bitRange(m,n,6));
	printf("The negation of %ld is %ld\n",m,negate(m));
	return 0;
}

//DONE
int isOdd(int x) {
	// Return a true value if x is odd, a fallse value if x is even
	return x & 1;
}

//DONE
long power2(int x) {
	assert(x>=0);
	assert(x<64);
	// Return 2 to the power of x
	int num = 0;
	num = (1 << x);
	return num;
}

long n1bits(int x) {
	assert(x>=0);
	assert(x<64);
	// Return a value that has x 1 bits, right justified in a long value
	int num = 0;
	num = (1 << x);
	num--;
	return num; // Template placeholder
}

char nthbit(long x,int n) {
	assert(n>=0);
	assert(n<64);
	// Return the numeric value (1 or 0) of the nth bit (from the right) of x
	long num = (x >> n);
	return num & 1; // Template placeholder
}

long bitRange(long x,int fb,int nbits) {
	assert(fb>=0);
	assert(nbits>=0);
	assert(fb<64);
	assert((fb+nbits)<64);
	// Return a long value that has nbits bits from the fb position from x
	//   (positions go from right to left)
	//   Right justify your answer
	long num = n1bits(nbits); //right justified
	num = (num << fb);
	num = (num & x);
	num = (num >> fb);
	return num; // Template placeholder
}

//DONE
long negate(long x) {
	// Return a value that represents -1 * x
	// You may use the increment operator (++) once
	x = ~x;
	x++;
	return x; // Template placeholder
}

char * longBits(char *buf,long x)  {
	// A helper function to put the ASCII representation of the bit value of x into
	//   the character array starting at buf.
	// Assumes buf has enough space to hold 72 characters
	//    (64 ones or zeroes, 7 blanks for readability, and one null terminator)
	const char bit_rep[16][5] = { "0000", "0001", "0010", "0011",
																	 "0100", "0101", "0110", "0111",
																	 "1000", "1001", "1010", "1011",
																	 "1100", "1101", "1110", "1111"};

	sprintf(buf,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
		bit_rep[x>>60 & 0x0F], bit_rep[x>>56 & 0x0F], bit_rep[x>>52 & 0x0F], bit_rep[x>>48 & 0x0F],
		bit_rep[x>>44 & 0x0F], bit_rep[x>>40 & 0x0F], bit_rep[x>>36 & 0x0F], bit_rep[x>>32 & 0x0F],
		bit_rep[x>>28 & 0x0F], bit_rep[x>>24 & 0x0F], bit_rep[x>>20 & 0x0F], bit_rep[x>>16 & 0x0F],
		bit_rep[x>>12 & 0x0F], bit_rep[x>>8 & 0x0F], bit_rep[x>>4 & 0x0F], bit_rep[x & 0x0F]);
   return buf;
}
