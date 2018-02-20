#include "order.h"
#include "bench.h"
#include <stdio.h>

int main(int argc, char **argv) {
	if (argc<2) {
		printf("Please invoke as %s <order_file>\n",argv[0]);
		return 1;
	}
	if (!openOrder(argv[1])) {
		return 1;
	}


	do {
		int pn = nextPartNumber();
		int bin = pn / 10;

		/* ----------------------------------------------------------------------
		The following code does the job, but very inefficiently.
		Replace this code with your own code to handle the
		slots on the workbench more intelligently (and earn
		more profit.)
		-----------------------------------------------------------------------*/
		if (binInSlot(0) != bin) { //if the desired bin isn't already in the slot
			fetchBin(bin, 0);
		} // Always use slot 0

	} while(fetchNextPart());
	closeOrder();
	return 0;
}
