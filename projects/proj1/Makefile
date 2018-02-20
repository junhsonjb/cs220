test : warehouse 
	./warehouse order1.txt
	./warehouse order2.txt

warehouse : warehouse.c bench.h bench.c order.c order.h benchOrder.h
	gcc -Wall -g -o warehouse warehouse.c order.c bench.c
	
clean :
	-rm warehouse