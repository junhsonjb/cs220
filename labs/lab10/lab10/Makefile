assembler : x86 x86.objdump.txt

test : x86 Makefile
	./x86
	
x86 : x86.c Makefile
	gcc $(OPT) -g -Wall -o x86 -fverbose-asm -Wa,-adhln=x86.s x86.c

x86.objdump.txt : x86 Makefile
	objdump -d x86 -S -l > x86.objdump.txt
	
clean:
	-rm  x86 x86.s x86.objdump.txt 		