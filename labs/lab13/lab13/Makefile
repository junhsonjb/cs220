testF : cache x86Math_trace.txt
	./cache F 8 6 <x86Math_trace.txt
	
testD : cache x86Math_trace.txt
	./cache D 8 6 <x86Math_trace.txt
	
testS : cache x86Math_trace.txt
	./cache S 8 6 4 <x86Math_trace.txt	
	
cache : cache.c cam.c cam.h lines.h lines.c
	gcc -g -Wall -o cache cache.c lines.c cam.c

testl8 : x86Math 
	./x86Math 4
	
x86Math : x86Math.c Makefile
	gcc -O0 -g -Wall -o x86Math x86Math.c
	
xmpr: xmpr.c array.c array.h
	gcc -g -I. -o xmpr xmpr.c array.c
	
xmpc:xmpc.c array.c array.h
	gcc -g -I. -o xmpc xmpc.c array.c
	
testxmpc: xmpr xmpc
	time ./xmpr; time ./xmpc;	
	
clean:
	-rm  x86Math xmpc xmpr
