test : limits
	./limits
	
gdb : limits
	gdb -ex "break main" -ex run limits

limits : limits.c
	gcc -g -Wall -o limits limits.c
	
clean : 
	-rm limits