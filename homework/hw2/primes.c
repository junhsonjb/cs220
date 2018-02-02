#include <stdio.h>
#include <stdlib.h>

int minFact(int a);

int main(int argc, char** argv) {

	//make sure that the user entered more than just the name of the program
	if (argc < 2) {
		printf("Please invoke main with: %s <value>\n", argv[0]);
		return 1;
	}

	//convert the command line argument (other than program name) to an integer
	int value = atoi(argv[1]);
	//if the value isn't greater than 0, send this err msg and end program
	if ( value <= 0 ) {
		printf("Value must be greater than 0\n");
		return 1;
	}

	//while testing, I noticed that the program enters an infinite loop when the input
	//value is 1. So in order to combat this, I am using this safeguard. I'm not sure if
	//this is what you wanted us to do, but I wanted to make sure my code ran to
	//completion when it is being tested for grading, so I also wrote this little note
	//to accompany the bit of code:
	if (value == 1) {
		printf("1 = 1, and is the lowest positive prime number\n");
		return 0;
	}

	//int min = minFact(value); // this code was used before we implemented the loop
	//printf("%d\n", min);

	// I prefer not to change the value that the user entered, so I put
	// the same value into another variable and worked with that
	int num = value; 
	//int factor = minFact(num); // I ended up not using this code
	printf("%d = ", value); // start with the entered value and a '='

	//this is the loop that prints all the (lowest) factors of the value variable
	while ((num / minFact(num)) != 1) {
		int factor = minFact(num); // this is the factor to be printed this iteration
		num = num / minFact(num); //change the value of num for the next iteration
		printf("%d x ", factor); //lastly (for the iteration), print factor
	}

	//printf("%d ", factor);
	//the loop prints all of the factors except for the last one,
	//this is because of the condition that I specified to make the while loop stop
	//so this last print statment extracts that minFact value and prints it out for 
	//the last factor
	//Doing it this way also helps me with the way I formatted the end result 
	//with all of the '=' and 'x' signs -- this way I don't get an output like:
	// 12 = 2 x 2 x 3 x
	printf("%d \n", minFact(num));

	return 0;
}

int minFact(int a) {

	int factor = 2;
	//if (a % factor == 0) return factor;
	while (a % factor != 0) {
		factor++;
	}

	return factor;

}
