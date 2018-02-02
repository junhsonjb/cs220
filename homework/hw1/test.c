#include <stdio.h>
	#include <stdlib.h>

	int main(int argc, char **argv) {

		int x; int y; int s_sum;
		unsigned int v; unsigned int w; unsigned int u_sum;

		if (argc<3) {
			printf("Please invoke as %s num1 num2\n",argv[0]);
			return 1;
		}

		x=atoi(argv[1]);
		y=atoi(argv[2]);
		v=x;
		w=y;
		s_sum=x+y;
		u_sum=v+w;
		printf("Signed: %d + %d = %d\n",x,y,s_sum);
		printf("Unsigned: %u + %u = %u\n",v,w,u_sum);
		if (s_sum==u_sum) { printf("The result matches\n"); }
		else { printf("The result is different\n"); }
		return 0;
	}
