#include "order.h"
#include "bench.h"
#include <stdio.h>

void addSlot(int * used, int addition);
int greatestdiff(int bin);
int slotToUse(int bin);
int inThere(int bin);

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

		/* Before we start, let's find out the greatest difference */
		int greatest = greatestdiff(bin);

		/* If the bin we need IS NOT ACTUALLY IN ONE OF THE SLOTS */
	if (inThere(bin) != 1) {

		/* ==== For every slot ==== */
		for (int i = 0; i < NUMSLOTS; i++) {

			/* ==== If slot i is empty, definitely use it ==== */
			if (binInSlot(i) == -1) {
				fetchBin(bin, i);
				break;
			} else /* If binInSlot(i) != -1 */ {
				/* if the slot isn't empty check if it already has the needed bin */
				if (binInSlot(i) == bin) {
					/* the bin we need is already here, so we can break here */
					break;
				} else /* if the bin we need isn't here, check the greatest diff */{
					int currentdiff = bin - binInSlot(i);
					if (currentdiff < 0) currentdiff *= -1; //make sure diff is (+)
					/* If the current diff is the biggest, fetch into that slot */
					if ( currentdiff  >= greatest ) {
						fetchBin(bin, /*slotToUse(bin)*/ i);
						break;
					}
				}
			}

		}

	} /* If the bin we need is already in there, do nothing! */

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

/* Add a slot onto the list of most recently used slots
 * (NOT USED ANYMORE) */
void addSlot(int * used, int addition) {
	for (int i = 0; i < 4; i++) {
		*(used + i) = *(used + i + 1);
	}
	*(used + 5) = addition;
}

/* Find the greatest difference between bin numbers
 * (between the needed bin and the ones on the bench  */
int greatestdiff(int bin) {
	int result = 0;
	for (int i = 0; i < NUMSLOTS; i++) {
		int diff = bin - binInSlot(i);
		if (diff > result) result = diff;
	}

	/* make sure result is positive */
	if (result < 0) result *= -1;

	return result;

}

/* Find out which slot is the one to fetch into */
/* I don't think I ended up needing this one */
int slotToUse(int bin) {
	int result = 0;
	int slot = 0;
	for (int i = 0; i < NUMSLOTS; i++) {
		int diff = bin - binInSlot(i);
		if (diff > result) {
			result = diff;
			slot = i;
		}
	}

	return slot;

}

/* Check if the bin number is already on the bench  */
int inThere(int bin) {
	int result = -1;
	for (int i = 0; i < NUMSLOTS; i++) {
		/* If the specified bin is already in one of the slots */
		if (binInSlot(i) == bin) {
			result = 1;
		}
	}	

	return result;

}
