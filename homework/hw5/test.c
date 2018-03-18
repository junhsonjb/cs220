#include <stdio.h>

int main() {

	union flint { 
		float xf;
		unsigned int xi;
	} fl;

	fl.xi=0x42c8000;
	printf("xf=%.3f\n",fl.xf);

}
