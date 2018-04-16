   1              		.file	"x86.c"
   2              	# GNU C11 (Debian 6.3.0-18+deb9u1) version 6.3.0 20170516 (x86_64-linux-gnu)
   3              	#	compiled by GNU C version 6.3.0 20170516, GMP version 6.1.2, MPFR version 3.1.5, MPC version 1.0.
   4              	# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
   5              	# options passed:  -imultiarch x86_64-linux-gnu x86.c -mtune=generic
   6              	# -march=x86-64 -g -Wall -fverbose-asm
   7              	# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
   8              	# -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
   9              	# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
  10              	# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
  11              	# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
  12              	# -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
  13              	# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
  14              	# -ffunction-cse -fgcse-lm -fgnu-runtime -fgnu-unique -fident
  15              	# -finline-atomics -fira-hoist-pressure -fira-share-save-slots
  16              	# -fira-share-spill-slots -fivopts -fkeep-static-consts
  17              	# -fleading-underscore -flifetime-dse -flto-odr-type-merging -fmath-errno
  18              	# -fmerge-debug-strings -fpeephole -fplt -fprefetch-loop-arrays
  19              	# -freg-struct-return -fsched-critical-path-heuristic
  20              	# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
  21              	# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
  22              	# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
  23              	# -fsemantic-interposition -fshow-column -fsigned-zeros
  24              	# -fsplit-ivs-in-unroller -fssa-backprop -fstdarg-opt
  25              	# -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math -ftree-cselim
  26              	# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
  27              	# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
  28              	# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
  29              	# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
  30              	# -malign-stringops -mavx256-split-unaligned-load
  31              	# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
  32              	# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
  33              	# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper
  34              	
  35              		.text
  36              	.Ltext0:
  37              		.section	.rodata
  38              	.LC0:
  39 0000 52657375 		.string	"Result=%d\n"
  39      6C743D25 
  39      640A00
  40              		.text
  41              		.globl	main
  43              	main:
  44              	.LFB0:
  45              		.file 1 "x86.c"
   1:x86.c         **** #include <stdio.h>
   2:x86.c         **** 
   3:x86.c         **** int func1(int a, int b);
   4:x86.c         **** int func2(int a);
   5:x86.c         **** 
   6:x86.c         **** enum flavors {
   7:x86.c         **** 	vanilla,
   8:x86.c         **** 	chocolate,
   9:x86.c         **** 	strawberry,
  10:x86.c         **** 	coffee,
  11:x86.c         **** 	tuttifrutti
  12:x86.c         **** };
  13:x86.c         **** 
  14:x86.c         **** int func3(enum flavors t);
  15:x86.c         **** 
  16:x86.c         **** int main() {
  46              		.loc 1 16 0
  47              		.cfi_startproc
  48 0000 55       		pushq	%rbp	#
  49              		.cfi_def_cfa_offset 16
  50              		.cfi_offset 6, -16
  51 0001 4889E5   		movq	%rsp, %rbp	#,
  52              		.cfi_def_cfa_register 6
  53 0004 4883EC10 		subq	$16, %rsp	#,
  17:x86.c         **** 	int a1=func2(5);
  54              		.loc 1 17 0
  55 0008 BF050000 		movl	$5, %edi	#,
  55      00
  56 000d E8000000 		call	func2	#
  56      00
  57 0012 8945FC   		movl	%eax, -4(%rbp)	# tmp89, a1
  18:x86.c         **** 	int b1=func3(chocolate);
  58              		.loc 1 18 0
  59 0015 BF010000 		movl	$1, %edi	#,
  59      00
  60 001a E8000000 		call	func3	#
  60      00
  61 001f 8945F8   		movl	%eax, -8(%rbp)	# tmp90, b1
  19:x86.c         **** 	int result=func1(a1,b1);
  62              		.loc 1 19 0
  63 0022 8B55F8   		movl	-8(%rbp), %edx	# b1, tmp91
  64 0025 8B45FC   		movl	-4(%rbp), %eax	# a1, tmp92
  65 0028 89D6     		movl	%edx, %esi	# tmp91,
  66 002a 89C7     		movl	%eax, %edi	# tmp92,
  67 002c E8000000 		call	func1	#
  67      00
  68 0031 8945F4   		movl	%eax, -12(%rbp)	# tmp93, result
  20:x86.c         **** 	printf("Result=%d\n",result);
  69              		.loc 1 20 0
  70 0034 8B45F4   		movl	-12(%rbp), %eax	# result, tmp94
  71 0037 89C6     		movl	%eax, %esi	# tmp94,
  72 0039 488D3D00 		leaq	.LC0(%rip), %rdi	#,
  72      000000
  73 0040 B8000000 		movl	$0, %eax	#,
  73      00
  74 0045 E8000000 		call	printf@PLT	#
  74      00
  21:x86.c         **** 	return 0;
  75              		.loc 1 21 0
  76 004a B8000000 		movl	$0, %eax	#, _9
  76      00
  22:x86.c         **** }
  77              		.loc 1 22 0
  78 004f C9       		leave
  79              		.cfi_def_cfa 7, 8
  80 0050 C3       		ret
  81              		.cfi_endproc
  82              	.LFE0:
  84              		.globl	func1
  86              	func1:
  87              	.LFB1:
  23:x86.c         **** 
  24:x86.c         **** int func1(int a, int b) {
  88              		.loc 1 24 0
  89              		.cfi_startproc
  90 0051 55       		pushq	%rbp	#
  91              		.cfi_def_cfa_offset 16
  92              		.cfi_offset 6, -16
  93 0052 4889E5   		movq	%rsp, %rbp	#,
  94              		.cfi_def_cfa_register 6
  95 0055 897DEC   		movl	%edi, -20(%rbp)	# a, a
  96 0058 8975E8   		movl	%esi, -24(%rbp)	# b, b
  25:x86.c         **** 	int c=0;
  97              		.loc 1 25 0
  98 005b C745FC00 		movl	$0, -4(%rbp)	#, c
  98      000000
  26:x86.c         ****    /* Insert code here */
  27:x86.c         **** 
  28:x86.c         **** 	if (a > b) {
  99              		.loc 1 28 0
 100 0062 8B45EC   		movl	-20(%rbp), %eax	# a, tmp89
 101 0065 3B45E8   		cmpl	-24(%rbp), %eax	# b, tmp89
 102 0068 7E09     		jle	.L4	#,
  29:x86.c         **** 		c = 1;
 103              		.loc 1 29 0
 104 006a C745FC01 		movl	$1, -4(%rbp)	#, c
 104      000000
 105 0071 EB18     		jmp	.L5	#
 106              	.L4:
  30:x86.c         **** 	} else {
  31:x86.c         **** 
  32:x86.c         **** 		if (b < a) {
 107              		.loc 1 32 0
 108 0073 8B45E8   		movl	-24(%rbp), %eax	# b, tmp90
 109 0076 3B45EC   		cmpl	-20(%rbp), %eax	# a, tmp90
 110 0079 7D09     		jge	.L6	#,
  33:x86.c         **** 			c = -1;
 111              		.loc 1 33 0
 112 007b C745FCFF 		movl	$-1, -4(%rbp)	#, c
 112      FFFFFF
 113 0082 EB07     		jmp	.L5	#
 114              	.L6:
  34:x86.c         **** 		} 
  35:x86.c         **** 	
  36:x86.c         **** 		else {
  37:x86.c         **** 			c = 0;
 115              		.loc 1 37 0
 116 0084 C745FC00 		movl	$0, -4(%rbp)	#, c
 116      000000
 117              	.L5:
  38:x86.c         **** 		}
  39:x86.c         **** 	}
  40:x86.c         **** 
  41:x86.c         **** 	return c;
 118              		.loc 1 41 0
 119 008b 8B45FC   		movl	-4(%rbp), %eax	# c, _8
  42:x86.c         **** }
 120              		.loc 1 42 0
 121 008e 5D       		popq	%rbp	#
 122              		.cfi_def_cfa 7, 8
 123 008f C3       		ret
 124              		.cfi_endproc
 125              	.LFE1:
 127              		.globl	func2
 129              	func2:
 130              	.LFB2:
  43:x86.c         **** 
  44:x86.c         **** int func2(int a) {
 131              		.loc 1 44 0
 132              		.cfi_startproc
 133 0090 55       		pushq	%rbp	#
 134              		.cfi_def_cfa_offset 16
 135              		.cfi_offset 6, -16
 136 0091 4889E5   		movq	%rsp, %rbp	#,
 137              		.cfi_def_cfa_register 6
 138 0094 897DEC   		movl	%edi, -20(%rbp)	# a, a
  45:x86.c         **** 	int x=0;
 139              		.loc 1 45 0
 140 0097 C745FC00 		movl	$0, -4(%rbp)	#, x
 140      000000
  46:x86.c         **** 	int y=3;
 141              		.loc 1 46 0
 142 009e C745F803 		movl	$3, -8(%rbp)	#, y
 142      000000
  47:x86.c         **** 	/* Insert code here */
  48:x86.c         **** 	
  49:x86.c         **** 	while (x < a) {
 143              		.loc 1 49 0
 144 00a5 EB0A     		jmp	.L9	#
 145              	.L10:
  50:x86.c         **** 		y += a;
 146              		.loc 1 50 0
 147 00a7 8B45EC   		movl	-20(%rbp), %eax	# a, tmp89
 148 00aa 0145F8   		addl	%eax, -8(%rbp)	# tmp89, y
  51:x86.c         **** 		x += 1;
 149              		.loc 1 51 0
 150 00ad 8345FC01 		addl	$1, -4(%rbp)	#, x
 151              	.L9:
  49:x86.c         **** 		y += a;
 152              		.loc 1 49 0
 153 00b1 8B45FC   		movl	-4(%rbp), %eax	# x, tmp90
 154 00b4 3B45EC   		cmpl	-20(%rbp), %eax	# a, tmp90
 155 00b7 7CEE     		jl	.L10	#,
  52:x86.c         **** 	}
  53:x86.c         **** 	
  54:x86.c         **** 	return y;
 156              		.loc 1 54 0
 157 00b9 8B45F8   		movl	-8(%rbp), %eax	# y, _8
  55:x86.c         **** }
 158              		.loc 1 55 0
 159 00bc 5D       		popq	%rbp	#
 160              		.cfi_def_cfa 7, 8
 161 00bd C3       		ret
 162              		.cfi_endproc
 163              	.LFE2:
 165              		.globl	func3
 167              	func3:
 168              	.LFB3:
  56:x86.c         **** 
  57:x86.c         **** int func3(enum flavors t) {
 169              		.loc 1 57 0
 170              		.cfi_startproc
 171 00be 55       		pushq	%rbp	#
 172              		.cfi_def_cfa_offset 16
 173              		.cfi_offset 6, -16
 174 00bf 4889E5   		movq	%rsp, %rbp	#,
 175              		.cfi_def_cfa_register 6
 176 00c2 897DEC   		movl	%edi, -20(%rbp)	# t, t
  58:x86.c         **** 	int like=0;
 177              		.loc 1 58 0
 178 00c5 C745FC00 		movl	$0, -4(%rbp)	#, like
 178      000000
  59:x86.c         **** 	/* Insert code here */
  60:x86.c         **** 	
  61:x86.c         **** 	switch (t) {
 179              		.loc 1 61 0
 180 00cc 8B45EC   		movl	-20(%rbp), %eax	# t, t_3(D)
 181 00cf 83F801   		cmpl	$1, %eax	#, t_3(D)
 182 00d2 741A     		je	.L14	#,
 183 00d4 83F801   		cmpl	$1, %eax	#, t_3(D)
 184 00d7 720C     		jb	.L15	#,
 185 00d9 83F802   		cmpl	$2, %eax	#, t_3(D)
 186 00dc 7419     		je	.L16	#,
 187 00de 83F804   		cmpl	$4, %eax	#, t_3(D)
 188 00e1 741D     		je	.L17	#,
 189 00e3 EB24     		jmp	.L20	#
 190              	.L15:
  62:x86.c         **** 		case vanilla: like = 10; break;
 191              		.loc 1 62 0
 192 00e5 C745FC0A 		movl	$10, -4(%rbp)	#, like
 192      000000
 193 00ec EB22     		jmp	.L18	#
 194              	.L14:
  63:x86.c         **** 		case chocolate: like = 7; break;
 195              		.loc 1 63 0
 196 00ee C745FC07 		movl	$7, -4(%rbp)	#, like
 196      000000
 197 00f5 EB19     		jmp	.L18	#
 198              	.L16:
  64:x86.c         **** 		case strawberry: like = -6; break;
 199              		.loc 1 64 0
 200 00f7 C745FCFA 		movl	$-6, -4(%rbp)	#, like
 200      FFFFFF
 201 00fe EB10     		jmp	.L18	#
 202              	.L17:
  65:x86.c         **** 		case tuttifrutti: like = 6; break;
 203              		.loc 1 65 0
 204 0100 C745FC06 		movl	$6, -4(%rbp)	#, like
 204      000000
 205 0107 EB07     		jmp	.L18	#
 206              	.L20:
  66:x86.c         **** 		default: like =  -2;
 207              		.loc 1 66 0
 208 0109 C745FCFE 		movl	$-2, -4(%rbp)	#, like
 208      FFFFFF
 209              	.L18:
  67:x86.c         **** 	}
  68:x86.c         ****  
  69:x86.c         **** 	return like;
 210              		.loc 1 69 0
 211 0110 8B45FC   		movl	-4(%rbp), %eax	# like, _9
  70:x86.c         **** }
 212              		.loc 1 70 0
 213 0113 5D       		popq	%rbp	#
 214              		.cfi_def_cfa 7, 8
 215 0114 C3       		ret
 216              		.cfi_endproc
 217              	.LFE3:
 219              	.Letext0:
 220              		.file 2 "/usr/lib/gcc/x86_64-linux-gnu/6/include/stddef.h"
 221              		.file 3 "/usr/include/x86_64-linux-gnu/bits/types.h"
 222              		.file 4 "/usr/include/libio.h"
 223              		.file 5 "/usr/include/stdio.h"
 224              		.file 6 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h"
