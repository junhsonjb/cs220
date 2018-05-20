# Sometimes its easier to create x86 assembler code in a file like this hack.s file
# The Makefile has a command to assemble this file and produce a hack.o file that has
# the binary instructions.
# 
# Use "objdump -d hack.o" to disassemble these instructions
# Use "objdump -h -j.text hack.o" to show exactly where these binary instruction are within the hack.o file
#
# Put your x86 assembler code below....
#Moving grades into each of my registers

push %rbp

movl $0x64, 0x202c58(%r12)

movl $0x64, 0x202de8(%r12)

movl $0x64, 0x202f78(%r12)

movl $0x64, 0x203108(%r12)

movl $0x9, 0x203298(%r12)
addl $0x1, 0x203298(%r12)

movl $0x9, 0x203428(%r12)
addl $0x1, 0x203428(%r12)

movl $0x9, 0x2035b8(%r12)
addl $0x1, 0x2035b8(%r12)

movl $0x9, 0x203748(%r12)
addl $0x1, 0x203748(%r12)

movl $0x64, 0x2038d8(%r12)

movl $0x64, 0x203a68(%r12)

movl $0x64, 0x203bf8(%r12)

retq
