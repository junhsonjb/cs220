#include "bench.h"
#include "benchOrder.h"
#include <assert.h>
#include <stdio.h>

#define foreachslot(X) for(X=0;X<NUMSLOTS;X++)

int slots[NUMSLOTS];
float cost=0.0;
int packed=0;

void clearBench() {
	int i;
	foreachslot(i) slots[i]=-1;
}

void fetchBin(int bin, int slot) {
	assert(slot<NUMSLOTS);
	if (slots[slot]!=-1) cost+=0.25; // It costs 25 cents to return a bin
	slots[slot]=bin;
	cost +=0.50; // It costs 50 cents to retrieve a new bin
	printf("bench: ");
	foreachslot(slot) printf("%2d ",slots[slot]);
	printf("\n");
}

void getWidget(int partNumber) {
	int bin=partNumber/10;
	int i;
	foreachslot(i) {
		if (slots[i]==bin) {
			packed++;
			return;
		}
	}
	printf("Bin %d for part number %d is not on the workbench.\n",
		bin,partNumber);
	assert(0);
}

int binInSlot(int slot) {
	assert(slot<NUMSLOTS);
	return slots[slot];
}

void printEarnings() {
	printf("You packed %d items at a cost of %.2f for a net earnings of %.2f\n",
		packed,cost,(packed/10.0) - cost);
}