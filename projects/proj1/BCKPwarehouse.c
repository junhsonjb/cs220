#include "order.h"
#include "bench.h"
#include <stdio.h>

void addSlot(int * used, int addition);

int main(int argc, char **argv) {
	if (argc<2) {
		printf("Please invoke as %s <order_file>\n",argv[0]);
		return 1;
	}
	if (!openOrder(argv[1])) {
		return 1;
	}

	//int used[5] = {0, 0, 0, 0, 0};

	do {
		int pn = nextPartNumber();
		int bin = pn / 10;

		/* ----------------------------------------------------------------------
		The following code does the job, but very inefficiently.
		Replace this code with your own code to handle the
		slots on the workbench more intelligently (and earn
		more profit.)
		-----------------------------------------------------------------------*/
		//if (binInSlot(0) != bin) { //if the desired bin isn't already in the slot
		//	fetchBin(bin, 0);
		//} // Always use slot 0
		
		/* My Code (Implementation) */

		for (int i = 0; i < NUMSLOTS; i++) {

			/* ==== If slot i is empty, definitely use it ==== */
			if (binInSlot(i) == -1) {
				fetchBin(bin, i);
				break;
			} else /* If binInSlot(i) != -1 */ {
				int currentdiff = greatestdiff(bin);
				if ( (bin - binInSlot(i)) >= currentdiff) {
					fetchBin(bin, i);
					break;
				}
			}

		}

		/* This is all the code I previously tried.
		 * I didn't want to just get rid of it, so 
		 * just commented it all out. Most of the
		 * relevant code is actually just above here,
		 * but below there is some good stuff like the
		 * end of the do while loop that this code is in
		 * and some function declarations */

		//int slotToUse = -1;
		//for (int i = 0; i < NUMSLOTS; i++) {
		//	if ( bin != binInSlot(i) ) {
		//		/* ===== Find biggest difference ===== */
		//		int biggestdiff = 0;
		//		for (int j = 0; j < NUMSLOTS; j++) {
		//			int diff = bin - binInSlot(j);
		//			if (diff > biggestdiff) {
		//				biggestdiff = diff;
		//			}
		//		}
		//		
		//		/* ===== Pick Slot to use based on biggest diff ====== */	
		//		//int slotToUse = 0; //declared outside of the loop
		//		for (int j = 0; j < NUMSLOTS; j++) {
		//			int diff = bin - binInSlot(j);
		//			if (diff == biggestdiff) {
		//				slotToUse = j;
		//				break;
		//			}
		//		}
//
		//		if (slotToUse != -1) {
		//			fetchBin(bin, slotToUse);
		//		}		
		//				
		//	}
		//}

		//int biggestdiff = 0;
		//for (int i = 0; i < NUMSLOTS; i++) {
		//	int diff = bin - binInSlot(i);
		//	if ( diff > biggestdiff ) {
		//		biggestdiff = diff;
		//	}
		//}

		//int slotToUse = 0;
		//for (int i = 0; i < NUMSLOTS; i++) {
		//	int diff = bin - binInSlot(i);
		//	if (diff == biggestdiff) {
		//		slotToUse = i;
		//		break;
		//	}
		//}
		//fetchBin(bin, slotToUse);

//		for (int i = 0; i < NUMSLOTS; i++) {
//			if (binInSlot(i) != bin) {
//				addSlot(used, i);
//			}
//			fetchBin(bin, used[5]);
//		}

		//save the 5 most recently used slots (as of this iteration) here
	//	for(int i = 0; i < NUMSLOTS; i++) {
	//		if (binInSlot(i) == bin) {
	//			break;
	//		}       

	//		if (binInSlot(i) == -1) {
	//			addSlot(used, i);
	//			fetchBin(bin, used[5]);
	//		} else {
	//			addSlot(used, i);
	//			fetchBin(bin, used[5]);
	//		}

	//		printf("BIN NUMBER:::::::%d", used[5]);

	//		/*we've coded the best way to handle the slot UNTIL
	//		 *the slots get filled up. Now we have to figure out
	//		 *a way to find the LEAST RECENTLY USED slot, and 
	//		 *fetch into that one*/

	//	}

} while(fetchNextPart());
	closeOrder();
	return 0;
}

void addSlot(int * used, int addition) {
	for (int i = 0; i < 4; i++) {
		*(used + i) = *(used + i + 1);
	}
	*(used + 5) = addition;
}

int greatestdiff(int bin) {
	int result = 0;
	for (int i = 0; i < NUMSLOTS; i++) {
		int diff = bin - binInSlot(i);
		if (diff > result) result = diff;
	}

	return result;

}
