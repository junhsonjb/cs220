marbles : marbles.c
	gcc -Wall -g -o marbles marbles.c
	
marbleAvg : marbleAvg.c
	gcc -Wall -g -o marbleAvg marbleAvg.c
	
test: marbles
	./marbles
	
testAvg : marbleAvg
	./marbleAvg 5
	
debug: marbles
	gdb ./marbles
	
clean: 
	rm marbles