   1              		.file	"x86Math.c"
   2              	# GNU C11 (Debian 6.3.0-18+deb9u1) version 6.3.0 20170516 (x86_64-linux-gnu)
   3              	#	compiled by GNU C version 6.3.0 20170516, GMP version 6.1.2, MPFR version 3.1.5, MPC version 1.0.
   4              	# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
   5              	# options passed:  -imultiarch x86_64-linux-gnu -D SIMPLE x86Math.c
   6              	# -mtune=generic -march=x86-64 -g -O0 -Wall -fverbose-asm
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
  39 0000 496E766F 		.string	"Invoke as %s <number>\n"
  39      6B652061 
  39      73202573 
  39      203C6E75 
  39      6D626572 
  40 0017 00       		.align 8
  41              	.LC1:
  42 0018 783D2564 		.string	"x=%d, x squared - 4x + 4 =%d divided by x-2=%d\n"
  42      2C207820 
  42      73717561 
  42      72656420 
  42      2D203478 
  43              		.text
  44              		.globl	main
  46              	main:
  47              	.LFB2:
  48              		.file 1 "x86Math.c"
   1:x86Math.c     **** #include <stdio.h>
   2:x86Math.c     **** #include <stdlib.h>
   3:x86Math.c     **** 
   4:x86Math.c     **** int add(int x, int y);
   5:x86Math.c     **** int mult(int x, int y);
   6:x86Math.c     **** int subtract(int x, int y);
   7:x86Math.c     **** int divide(int x, int y);
   8:x86Math.c     **** 
   9:x86Math.c     **** int main(int argc, char **argv) {
  49              		.loc 1 9 0
  50              		.cfi_startproc
  51 0000 55       		pushq	%rbp	#
  52              		.cfi_def_cfa_offset 16
  53              		.cfi_offset 6, -16
  54 0001 4889E5   		movq	%rsp, %rbp	#,
  55              		.cfi_def_cfa_register 6
  56 0004 4883EC20 		subq	$32, %rsp	#,
  57 0008 897DEC   		movl	%edi, -20(%rbp)	# argc, argc
  58 000b 488975E0 		movq	%rsi, -32(%rbp)	# argv, argv
  10:x86Math.c     **** 	if (argc < 2) {
  59              		.loc 1 10 0
  60 000f 837DEC01 		cmpl	$1, -20(%rbp)	#, argc
  61 0013 7F25     		jg	.L2	#,
  11:x86Math.c     **** 		printf("Invoke as %s <number>\n",argv[0]);
  62              		.loc 1 11 0
  63 0015 488B45E0 		movq	-32(%rbp), %rax	# argv, tmp92
  64 0019 488B00   		movq	(%rax), %rax	# *argv_5(D), _6
  65 001c 4889C6   		movq	%rax, %rsi	# _6,
  66 001f 488D3D00 		leaq	.LC0(%rip), %rdi	#,
  66      000000
  67 0026 B8000000 		movl	$0, %eax	#,
  67      00
  68 002b E8000000 		call	printf@PLT	#
  68      00
  12:x86Math.c     **** 		return 1;
  69              		.loc 1 12 0
  70 0030 B8010000 		movl	$1, %eax	#, _1
  70      00
  71 0035 E9A30000 		jmp	.L3	#
  71      00
  72              	.L2:
  13:x86Math.c     **** 	}
  14:x86Math.c     **** 	int x=atoi(argv[1]);
  73              		.loc 1 14 0
  74 003a 488B45E0 		movq	-32(%rbp), %rax	# argv, tmp93
  75 003e 4883C008 		addq	$8, %rax	#, _9
  76 0042 488B00   		movq	(%rax), %rax	# *_9, _10
  77 0045 4889C7   		movq	%rax, %rdi	# _10,
  78 0048 E8000000 		call	atoi@PLT	#
  78      00
  79 004d 8945FC   		movl	%eax, -4(%rbp)	# tmp94, x
  15:x86Math.c     **** 	int ans=mult(x,x);
  80              		.loc 1 15 0
  81 0050 8B55FC   		movl	-4(%rbp), %edx	# x, tmp95
  82 0053 8B45FC   		movl	-4(%rbp), %eax	# x, tmp96
  83 0056 89D6     		movl	%edx, %esi	# tmp95,
  84 0058 89C7     		movl	%eax, %edi	# tmp96,
  85 005a E8000000 		call	mult	#
  85      00
  86 005f 8945F8   		movl	%eax, -8(%rbp)	# tmp97, ans
  16:x86Math.c     **** 	int term=mult(4,x);
  87              		.loc 1 16 0
  88 0062 8B45FC   		movl	-4(%rbp), %eax	# x, tmp98
  89 0065 89C6     		movl	%eax, %esi	# tmp98,
  90 0067 BF040000 		movl	$4, %edi	#,
  90      00
  91 006c E8000000 		call	mult	#
  91      00
  92 0071 8945F4   		movl	%eax, -12(%rbp)	# tmp99, term
  17:x86Math.c     **** 	ans=subtract(ans,term);
  93              		.loc 1 17 0
  94 0074 8B55F4   		movl	-12(%rbp), %edx	# term, tmp100
  95 0077 8B45F8   		movl	-8(%rbp), %eax	# ans, tmp101
  96 007a 89D6     		movl	%edx, %esi	# tmp100,
  97 007c 89C7     		movl	%eax, %edi	# tmp101,
  98 007e E8000000 		call	subtract	#
  98      00
  99 0083 8945F8   		movl	%eax, -8(%rbp)	# tmp102, ans
  18:x86Math.c     **** 	ans=add(ans,4);
 100              		.loc 1 18 0
 101 0086 8B45F8   		movl	-8(%rbp), %eax	# ans, tmp103
 102 0089 BE040000 		movl	$4, %esi	#,
 102      00
 103 008e 89C7     		movl	%eax, %edi	# tmp103,
 104 0090 E8000000 		call	add	#
 104      00
 105 0095 8945F8   		movl	%eax, -8(%rbp)	# tmp104, ans
  19:x86Math.c     **** 	term=subtract(x,2);
 106              		.loc 1 19 0
 107 0098 8B45FC   		movl	-4(%rbp), %eax	# x, tmp105
 108 009b BE020000 		movl	$2, %esi	#,
 108      00
 109 00a0 89C7     		movl	%eax, %edi	# tmp105,
 110 00a2 E8000000 		call	subtract	#
 110      00
 111 00a7 8945F4   		movl	%eax, -12(%rbp)	# tmp106, term
  20:x86Math.c     **** 	int check=divide(ans,term);
 112              		.loc 1 20 0
 113 00aa 8B55F4   		movl	-12(%rbp), %edx	# term, tmp107
 114 00ad 8B45F8   		movl	-8(%rbp), %eax	# ans, tmp108
 115 00b0 89D6     		movl	%edx, %esi	# tmp107,
 116 00b2 89C7     		movl	%eax, %edi	# tmp108,
 117 00b4 E8000000 		call	divide	#
 117      00
 118 00b9 8945F0   		movl	%eax, -16(%rbp)	# tmp109, check
  21:x86Math.c     **** 	printf("x=%d, x squared - 4x + 4 =%d divided by x-2=%d\n",x,ans,check);
 119              		.loc 1 21 0
 120 00bc 8B4DF0   		movl	-16(%rbp), %ecx	# check, tmp110
 121 00bf 8B55F8   		movl	-8(%rbp), %edx	# ans, tmp111
 122 00c2 8B45FC   		movl	-4(%rbp), %eax	# x, tmp112
 123 00c5 89C6     		movl	%eax, %esi	# tmp112,
 124 00c7 488D3D00 		leaq	.LC1(%rip), %rdi	#,
 124      000000
 125 00ce B8000000 		movl	$0, %eax	#,
 125      00
 126 00d3 E8000000 		call	printf@PLT	#
 126      00
  22:x86Math.c     **** 	return 0;
 127              		.loc 1 22 0
 128 00d8 B8000000 		movl	$0, %eax	#, _1
 128      00
 129              	.L3:
  23:x86Math.c     **** }
 130              		.loc 1 23 0
 131 00dd C9       		leave
 132              		.cfi_def_cfa 7, 8
 133 00de C3       		ret
 134              		.cfi_endproc
 135              	.LFE2:
 137              		.globl	add
 139              	add:
 140              	.LFB3:
  24:x86Math.c     **** 
  25:x86Math.c     **** #ifdef SIMPLE
  26:x86Math.c     **** 	int add(int x, int y) { return x+y; }
 141              		.loc 1 26 0
 142              		.cfi_startproc
 143 00df 55       		pushq	%rbp	#
 144              		.cfi_def_cfa_offset 16
 145              		.cfi_offset 6, -16
 146 00e0 4889E5   		movq	%rsp, %rbp	#,
 147              		.cfi_def_cfa_register 6
 148 00e3 897DFC   		movl	%edi, -4(%rbp)	# x, x
 149 00e6 8975F8   		movl	%esi, -8(%rbp)	# y, y
 150              		.loc 1 26 0
 151 00e9 8B55FC   		movl	-4(%rbp), %edx	# x, tmp89
 152 00ec 8B45F8   		movl	-8(%rbp), %eax	# y, tmp90
 153 00ef 01D0     		addl	%edx, %eax	# tmp89, _3
 154 00f1 5D       		popq	%rbp	#
 155              		.cfi_def_cfa 7, 8
 156 00f2 C3       		ret
 157              		.cfi_endproc
 158              	.LFE3:
 160              		.globl	subtract
 162              	subtract:
 163              	.LFB4:
  27:x86Math.c     **** 	int subtract(int x, int y) { return x-y; }
 164              		.loc 1 27 0
 165              		.cfi_startproc
 166 00f3 55       		pushq	%rbp	#
 167              		.cfi_def_cfa_offset 16
 168              		.cfi_offset 6, -16
 169 00f4 4889E5   		movq	%rsp, %rbp	#,
 170              		.cfi_def_cfa_register 6
 171 00f7 897DFC   		movl	%edi, -4(%rbp)	# x, x
 172 00fa 8975F8   		movl	%esi, -8(%rbp)	# y, y
 173              		.loc 1 27 0
 174 00fd 8B45FC   		movl	-4(%rbp), %eax	# x, tmp89
 175 0100 2B45F8   		subl	-8(%rbp), %eax	# y, _3
 176 0103 5D       		popq	%rbp	#
 177              		.cfi_def_cfa 7, 8
 178 0104 C3       		ret
 179              		.cfi_endproc
 180              	.LFE4:
 182              		.globl	mult
 184              	mult:
 185              	.LFB5:
  28:x86Math.c     **** 	int mult(int x, int y) { return x*y; }
 186              		.loc 1 28 0
 187              		.cfi_startproc
 188 0105 55       		pushq	%rbp	#
 189              		.cfi_def_cfa_offset 16
 190              		.cfi_offset 6, -16
 191 0106 4889E5   		movq	%rsp, %rbp	#,
 192              		.cfi_def_cfa_register 6
 193 0109 897DFC   		movl	%edi, -4(%rbp)	# x, x
 194 010c 8975F8   		movl	%esi, -8(%rbp)	# y, y
 195              		.loc 1 28 0
 196 010f 8B45FC   		movl	-4(%rbp), %eax	# x, tmp89
 197 0112 0FAF45F8 		imull	-8(%rbp), %eax	# y, _3
 198 0116 5D       		popq	%rbp	#
 199              		.cfi_def_cfa 7, 8
 200 0117 C3       		ret
 201              		.cfi_endproc
 202              	.LFE5:
 204              		.globl	divide
 206              	divide:
 207              	.LFB6:
  29:x86Math.c     **** 	int divide(int x, int y) { return x/y; }
 208              		.loc 1 29 0
 209              		.cfi_startproc
 210 0118 55       		pushq	%rbp	#
 211              		.cfi_def_cfa_offset 16
 212              		.cfi_offset 6, -16
 213 0119 4889E5   		movq	%rsp, %rbp	#,
 214              		.cfi_def_cfa_register 6
 215 011c 897DFC   		movl	%edi, -4(%rbp)	# x, x
 216 011f 8975F8   		movl	%esi, -8(%rbp)	# y, y
 217              		.loc 1 29 0
 218 0122 8B45FC   		movl	-4(%rbp), %eax	# x, tmp91
 219 0125 99       		cltd
 220 0126 F77DF8   		idivl	-8(%rbp)	# y
 221 0129 5D       		popq	%rbp	#
 222              		.cfi_def_cfa 7, 8
 223 012a C3       		ret
 224              		.cfi_endproc
 225              	.LFE6:
 227              	.Letext0:
 228              		.file 2 "/usr/lib/gcc/x86_64-linux-gnu/6/include/stddef.h"
 229              		.file 3 "/usr/include/x86_64-linux-gnu/bits/types.h"
 230              		.file 4 "/usr/include/libio.h"
 231              		.file 5 "/usr/include/stdio.h"
 232              		.file 6 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h"
