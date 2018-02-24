test : showArray
	./showArray
	
showArray : showArray.c format.c format.h
	gcc -g -Wall -o showArray showArray.c format.c
	
clean :
	-rm showArray