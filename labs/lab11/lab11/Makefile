test: target mix_out.bin
	setarch linux64 -R ./target <mix_out.bin
	
target.objdump.txt : target
	objdump -dSl target > target.objdump.txt	
	
target : target.c
	gcc -g -Wall -O0  -o target target.c	
	
showhex : mix_out.bin
	od -Ax -c -tx1 mix_out.bin
	
mix_out.bin : mix mix_in.txt
	./mix <mix_in.txt >mix_out.bin
	
mix : mix.c
	gcc -g -Wall -o mix mix.c	
	
gdb: target mix_out.bin
	gdb -x dbg.txt target		
		
clean:
	-rm target target.objdump.txt mix_out.bin mix
