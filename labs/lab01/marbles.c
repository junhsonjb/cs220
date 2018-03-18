/* ------------------------------------------------------------------
Pick marbles from a jar that contains a mixture of:
	100 red marbles,
	100 blue marbles, and
	100 green marbles.


How many marbles did you need to pick to get 10 red?

-------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int redMarbles=100;
int greenMarbles=100;
int blueMarbles=100;

char pickMarble() {
	char picked='?';
	int tot = redMarbles + greenMarbles + blueMarbles;
	assert(tot>0);
	int choice = rand()%tot; // Choice is a random number 0 <= choice < tot
	if (choice<redMarbles) {
		redMarbles = redMarbles - 1;
		printf("Picked a red marble\n");
		picked='r';
	}
	else if (choice<redMarbles+greenMarbles) {
		greenMarbles = greenMarbles - 1;
		printf("Picked a green marble\n");
		picked='g';
	}
	else {
		blueMarbles = blueMarbles - 1;
		printf("Picked a blue marble\n");
		picked='b';
	}
	return picked;
}

int main(int argc, char ** argv) {
	if (argc>1) { srand(atoi(argv[1])); } // Seed random number
	int numPicked=0;
	int turns = 0;
	while(redMarbles > 50) {

		

		char p = pickMarble();
		//printf("picked %d reds, %d greens, and %d blues\n", pred, pgreen, pblue);
		char prev = 'a';

		

		if ( p == 'r') {

			while (redMarbles > 50 && p != 'b') {
				prev = p;
				p = pickMarble();
			}

		}

		else if ( p == 'g' ) {

			while (redMarbles > 50 && p != prev) {
				prev = p;
				p = pickMarble();
			}
			
		}

		else {
			

			redMarbles = 100;
			
		}

		numPicked=numPicked+1;
		printf("picked %d reds, %d greens, and %d blues\n", 100 - redMarbles, 100 - greenMarbles, 100 - blueMarbles);

		turns = turns + 1;
		printf("%d turns\n", turns);


	}
	printf("Got 10 red marbles after picking %d marbles.\n",numPicked);
	return 0;
}
