#include <stdio.h>

long minVal(char type,int isSigned);
long maxVal(char type,int isSigned);

int main(int argc, char **argv) {
	//chars
	printf("chars\n");
	printf("%12ld <= %15s <= %12ld\n",minVal('c',1),"Signed Char",maxVal('c',1));
	printf("%12lu <= %15s <= %12lu\n",minVal('c',0),"Unsigned Char",maxVal('c',0));

	//integers
	printf("integers\n");
	printf("%12ld <= %15s <= %12ld\n",minVal('i',1),"Signed Integer",maxVal('i',1));
	printf("%12lu <= %15s <= %12lu\n",minVal('i',0),"Unsigned Integer",maxVal('i',0));

	//shorts
	printf("shorts\n");
	printf("%12ld <= %15s <= %12ld\n",minVal('s',1),"Signed Short",maxVal('s',1));
	printf("%12lu <= %15s <= %12lu\n",minVal('s',0),"Unsigned Short",maxVal('s',0));

	//shorts
	printf("longs\n");
	printf("%12ld <= %15s <= %12ld\n",minVal('l',1),"Signed Long",maxVal('l',1));
	printf("%12lu <= %15s <= %12lu\n",minVal('l',0),"Unsigned Long",maxVal('l',0));

	return 0;
}

long minVal(char type, int isSigned) {

	if (isSigned) {
		char ics=0;
		int iics = 0;
		short scs = 0;
		long lcs = 0;
		long pow = 2;

		switch(type) {
			case 'c':
				while((char)(ics-1) < ics) {
					ics=ics-1;
				}
				return ics;

			case 'i':
				while((int)(iics - 1) < iics) {
					iics = iics - 1;
				}
				return iics;

			case 's':
				while((short)(scs - 1) < scs) {
					scs = scs - 1;
				}
				return scs;

			case 'l':
				while ((long)(lcs - pow) < lcs) {
					lcs = lcs - pow;
					pow = pow * 2;
					
				}
				return lcs;

			default:
				printf("Signed type of %c not supported\n",type);
		}
	} else {
		unsigned char icu=0;
		unsigned int iicu = 0;
		unsigned short scu = 0;
		unsigned long lcu = 0;
		unsigned long pow = 2;
		switch(type) {

			case 'c':
				while((unsigned char)(icu-1) < icu) {
					icu=icu-1;
				}
				return icu;

			case 'i':
				while((unsigned int)(iicu - 1) < iicu) {
					iicu = iicu - 1;
				}
				return iicu;

			case 's':
				while((unsigned short)(scu - 1) < scu) {
					scu = scu - 1;
				}
				return scu;

			case 'l':
				while ((long)(lcu - pow) < lcu) {
					lcu = lcu - pow;
					pow = pow * 2;
				}
				return lcu;

			default:
				printf("Unsigned type of %c not supported\n",type);
		}
	}
	return 0;
}

long maxVal(char type, int isSigned) {
	if (isSigned) {
		char ics=0;
		int iics = 0;
		short scs = 0;
		long lcs = 0;
		long pow = 2;

		switch(type) {
			case 'c':
				while((char)(ics+1) > ics) {
					ics=ics+1;
				}
				return ics;

			case 'i':
				while((int)(iics + 1) > iics) {
					iics = iics + 1;
				}
				return iics;

			case 's':
				while((short)(scs + 1) > scs) {
					scs = scs + 1;
				}
				return scs;

			case 'l':
				while ((long)(lcs + pow) > lcs) {
					lcs = lcs + pow;
					pow = pow * 2;
				}
				return lcs;

			default:
				printf("Signed type of %c not supported\n",type);
		}
	} else {
		unsigned char icu=0;
		unsigned int iicu = 0;
		unsigned short scu = 0;
		unsigned long lcu = 0;
		unsigned long pow = 2;

		switch(type) {
			case 'c':
				while((unsigned char)(icu+1) > icu) {
					icu=icu+1;
				}
				return icu;

			case 'i':
				while((unsigned int)(iicu+1) > iicu) {
					iicu = iicu + 1;
				}
				return iicu;

			case 's':
				while((unsigned short)(scu+1) > scu) {
					scu = scu + 1;
				}
				return scu;

			case 'l':
				while ((long)(lcu + pow) > lcu) {
					lcu = lcu + pow;
					pow = pow * 2;
				}
				return lcu;

			default:
				printf("Unsigned type of %c not supported\n",type);
		}
	}
	return 0;
}
