test : grades mix_out.bin
	setarch linux64 -R ./grades <mix_out.bin
	
showhex : mix_out.bin
	od -Ax -tx1z mix_out.bin
	
hack.o : hack.s
	gcc -c -o hack.o hack.s
	
hack.objdump.txt : hack.o
	objdump -dSl hack.o >hack.objdump.txt	
	
mix_out.bin : mix mix_in.txt
	./mix <jjeanba2.txt >mix_out.bin

grades: grades.c
	gcc -Wall -O0 -g -o grades grades.c
	
mix : mix.c
	gcc -Wall -g -o mix mix.c	
	
grades.objdump.txt : grades
	objdump -dSl grades >grades.objdump.txt
	
gdb : grades 
	gdb -x dbg_cmds.txt grades
	
clean:  
	-rm grades grades.objdump.txt mix mix_out.bin hack.o hack.objdump.txt
