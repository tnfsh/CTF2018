# c語言程式編譯與組譯

【推薦好書】程式設計師的自我修養：連結、載入、程式庫

## 主程式

>vim/gedit/nano factorial.c

```
#include <stdio.h>

long factorial(int n);
void main(void){
    int i;
    
    printf("please insert n:"); 
    scanf("%d", &i); 
    printf("%d!=%ld", i, factorial(i)); 
    return; 
}

long factorial(int n)  { 
    if (n==1) return 1;
    else  return n*factorial(n-1);
}

```

## 預處理階段

>gcc -E factorial.c -o factorial.i

```
https://github.com/saho-yu/CTF2018/blob/master/Reverse/factorial.i
```
## 編譯階段==>產生組語

>gcc -S factorial.i -o factorial.s

```
	.file	"factorial.c"
	.section	.rodata
.LC0:
	.string	"please insert n:"
.LC1:
	.string	"%d"
.LC2:
	.string	"%d!=%ld"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leaq	-12(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-12(%rbp), %eax
	movl	%eax, %edi
	call	factorial
	movq	%rax, %rdx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	factorial
	.type	factorial, @function
factorial:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movl	%edi, -20(%rbp)
	cmpl	$1, -20(%rbp)
	jne	.L5
	movl	$1, %eax
	jmp	.L6
.L5:
	movl	-20(%rbp), %eax
	movslq	%eax, %rbx
	movl	-20(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	factorial
	imulq	%rbx, %rax
.L6:
	addq	$24, %rsp
```
## 組譯階段==>產生物件檔

>gcc -c factorial.s -o factorial.o

```
ELF\00\00\00\00\00\00\00\00\00\00>\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\A0\00\00\00\00\00\00\00\00\00\00@\00\00\00\00\00@\00
\00
\00UH\89\E5H\83\ECdH\8B%(\00\00\00H\89E\F81\C0\BF\00\00\00\00\B8\00\00\00\00\E8\00\00\00\00H\8DE\F4H\89ƿ\00\00\00\00\B8\00\00\00\00\E8\00\00\00\00\8BE\F4\89\C7\E8\00\00\00\00H\89E\F4\89ƿ\00\00\00\00\B8\00\00\00\00\E8\00\00\00\00\90H\8BE\F8dH3%(\00\00\00t\E8\00\00\00\00\C9\C3UH\89\E5SH\83\EC\89}\EC\83}\ECu\B8\00\00\00\EB\8BE\ECHc؋E\EC\83\E8\89\C7\E8\00\00\00\00H\AF\C3H\83\C4[]\C3please insert n:\00%d\00%d!=%ld\00\00GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609\00\00\00\00\00\00\00\00\00\00\00\00zR\00x\90\00\00\00\00\00\00\00\00\00\00\00\00t\00\00\00\00A\86C
o\00\00\00\00\00<\00\00\00\00\00\00\007\00\00\00\00A\86C
E\83m\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\F1\FF\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00
\00\00\00\00\00\00\00\00\00\00\00\00\00t\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00(\00\00\00\00\00t\00\00\00\00\00\00\007\00\00\00\00\00\00\002\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00factorial.c\00main\00printf\00__isoc99_scanf\00factorial\00__stack_chk_fail\00\00\00\00\00\00\00\00\00\00\00\00\00
\00\00\00\00\00\00\00\00\00\00\00\00\00\00"\00\00\00\00\00\00\00\00\00\00
\00\00\00\FC\FF\FF\FF\FF\FF\FF\FF.\00\00\00\00\00\00\00
\00\00\00\00\00\00\00\00\00\00\00\00\008\00\00\00\00\00\00\00\00\00\00\00\00\00\FC\FF\FF\FF\FF\FF\FF\FFB\00\00\00\00\00\00\00\00\00\00\00\00\00\FC\FF\FF\FF\FF\FF\FF\FFO\00\00\00\00\00\00\00
\00\00\00\00\00\00\00\00\00\00\00\00\00Y\00\00\00\00\00\00\00\00\00\00
\00\00\00\FC\FF\FF\FF\FF\FF\FF\FFn\00\00\00\00\00\00\00\00\00\00
\00\00\00\FC\FF\FF\FF\FF\FF\FF\FF\9C\00\00\00\00\00\00\00\00\00\00\00\00\00\FC\FF\FF\FF\FF\FF\FF\FF \00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00@\00\00\00\00\00\00\00\00\00\00\00\00\00t\00\00\00\00\00\00\00\00.symtab\00.strtab\00.shstrtab\00.rela.text\00.data\00.bss\00.rodata\00.comment\00.note.GNU-stack\00.rela.eh_frame\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00 \00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00@\00\00\00\00\00\00\00\AB\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00@\00\00\00\00\00\00\00\00\00\00\00\00\00\00\000\00\00\00\00\00\00\D8\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00&\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\EB\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00,\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\EB\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\001\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\EB\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\009\00\00\00\00\00\000\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\005\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00B\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00<\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00W\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00@\00\00\00\00\00\00X\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00R\00\00\00\00\00\00@\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\000\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\008\00\00\00\00\00\00a\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\98\00\00\00\00\00\00P\00\00\00\00\00\00\00\00\00	\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00	\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\E8\00\00\00\00\00\00C\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00
```

## 連結階段==>產生執行檔(附檔名不影響)

>gcc factorial.o -o factorial

執行factorial

>./factorial

範例:輸入5
```
please insert n:5
5!=120
```

## 產生AT&T語法格式的組語(gcc預設使用的格式)

>gcc -S -masm=att factorial.c -o factorial_att.s

```
	.file	"factorial.c"
	.section	.rodata
.LC0:
	.string	"please insert n:"
.LC1:
	.string	"%d"
.LC2:
	.string	"%d!=%ld"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leaq	-12(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-12(%rbp), %eax
	movl	%eax, %edi
	call	factorial
	movq	%rax, %rdx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	factorial
	.type	factorial, @function
factorial:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movl	%edi, -20(%rbp)
	cmpl	$1, -20(%rbp)
	jne	.L5
	movl	$1, %eax
	jmp	.L6
.L5:
	movl	-20(%rbp), %eax
```

## 產生Intel語法格式的組語(微軟預設使用的格式)

>gcc -S -masm=intel factorial.c -o factorial_intel.s

```
	.file	"factorial.c"
	.intel_syntax noprefix
	.section	.rodata
.LC0:
	.string	"please insert n:"
.LC1:
	.string	"%d"
.LC2:
	.string	"%d!=%ld"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR [rbp-8], rax
	xor	eax, eax
	mov	edi, OFFSET FLAT:.LC0
	mov	eax, 0
	call	printf
	lea	rax, [rbp-12]
	mov	rsi, rax
	mov	edi, OFFSET FLAT:.LC1
	mov	eax, 0
	call	__isoc99_scanf
	mov	eax, DWORD PTR [rbp-12]
	mov	edi, eax
	call	factorial
	mov	rdx, rax
	mov	eax, DWORD PTR [rbp-12]
	mov	esi, eax
	mov	edi, OFFSET FLAT:.LC2
	mov	eax, 0
	call	printf
	nop
	mov	rax, QWORD PTR [rbp-8]
	xor	rax, QWORD PTR fs:40
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	factorial
	.type	factorial, @function
factorial:
.LFB1:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 24
	.cfi_offset 3, -24
	mov	DWORD PTR [rbp-20], edi
	cmp	DWORD PTR [rbp-20], 1
	jne	.L5
	mov	eax, 1
	jmp	.L6
.L5:
	mov	eax, DWORD PTR [rbp-20]
	movsx	rbx, eax
	mov	eax, DWORD PTR [rbp-20]
	sub	eax, 1
	mov	edi, eax
	call	factorial
	imul	rax, rbx
.L6:
	add	rsp, 24
	pop	rbx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	factorial, .-factorial
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
```
## 要去掉一堆註解:請加上參數-fno-asynchronous-unwind-tables

>gcc -S -masm=intel factorial.c -o factorial_intel_OK.s -fno-asynchronous-unwind-tables

```
	.file	"factorial.c"
	.intel_syntax noprefix
	.section	.rodata
.LC0:
	.string	"please insert n:"
.LC1:
	.string	"%d"
.LC2:
	.string	"%d!=%ld"
	.text
	.globl	main
	.type	main, @function
main:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 16
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR [rbp-8], rax
	xor	eax, eax
	mov	edi, OFFSET FLAT:.LC0
	mov	eax, 0
	call	printf
	lea	rax, [rbp-12]
	mov	rsi, rax
	mov	edi, OFFSET FLAT:.LC1
	mov	eax, 0
	call	__isoc99_scanf
	mov	eax, DWORD PTR [rbp-12]
	mov	edi, eax
	call	factorial
	mov	rdx, rax
	mov	eax, DWORD PTR [rbp-12]
	mov	esi, eax
	mov	edi, OFFSET FLAT:.LC2
	mov	eax, 0
	call	printf
	nop
	mov	rax, QWORD PTR [rbp-8]
	xor	rax, QWORD PTR fs:40
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	ret
	.size	main, .-main
	.globl	factorial
	.type	factorial, @function
factorial:
	push	rbp
	mov	rbp, rsp
	push	rbx
	sub	rsp, 24
	mov	DWORD PTR [rbp-20], edi
	cmp	DWORD PTR [rbp-20], 1
	jne	.L5
	mov	eax, 1
	jmp	.L6
.L5:
	mov	eax, DWORD PTR [rbp-20]
	movsx	rbx, eax
	mov	eax, DWORD PTR [rbp-20]
	sub	eax, 1
	mov	edi, eax
	call	factorial
	imul	rax, rbx
.L6:
	add	rsp, 24
	pop	rbx
	pop	rbp
	ret
	.size	factorial, .-factorial
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
```
![image](https://github.com/saho-yu/CTF2018/blob/master/Reverse/pictures/reverse_program.png)

## 組譯過程

>* 將組合語言程式碼轉成機器可以執行的指令(instructions)
>* 每一個組語語句都對應一機器指令。
>* 組譯器的組譯過程相對於編譯器來講比較簡單
>* 沒有複雜的語法，也沒有語意，也不需要做指令最佳化，只是根據組語指令和機器指令的對照表一一翻譯就可以



## 將執行檔逆向=>逆向成組合語言

>objdump -S -M intel factorial

```
factorial:     file format elf64-x86-64


Disassembly of section .init:

0000000000400480 <_init>:
  400480:	48 83 ec 08          	sub    rsp,0x8
  400484:	48 8b 05 6d 0b 20 00 	mov    rax,QWORD PTR [rip+0x200b6d]        # 600ff8 <_DYNAMIC+0x1d0>
  40048b:	48 85 c0             	test   rax,rax
  40048e:	74 05                	je     400495 <_init+0x15>
  400490:	e8 5b 00 00 00       	call   4004f0 <__isoc99_scanf@plt+0x10>
  400495:	48 83 c4 08          	add    rsp,0x8
  400499:	c3                   	ret    

Disassembly of section .plt:

00000000004004a0 <__stack_chk_fail@plt-0x10>:
  4004a0:	ff 35 62 0b 20 00    	push   QWORD PTR [rip+0x200b62]        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  4004a6:	ff 25 64 0b 20 00    	jmp    QWORD PTR [rip+0x200b64]        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  4004ac:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

00000000004004b0 <__stack_chk_fail@plt>:
  4004b0:	ff 25 62 0b 20 00    	jmp    QWORD PTR [rip+0x200b62]        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  4004b6:	68 00 00 00 00       	push   0x0
  4004bb:	e9 e0 ff ff ff       	jmp    4004a0 <_init+0x20>

00000000004004c0 <printf@plt>:
  4004c0:	ff 25 5a 0b 20 00    	jmp    QWORD PTR [rip+0x200b5a]        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  4004c6:	68 01 00 00 00       	push   0x1
  4004cb:	e9 d0 ff ff ff       	jmp    4004a0 <_init+0x20>

00000000004004d0 <__libc_start_main@plt>:
  4004d0:	ff 25 52 0b 20 00    	jmp    QWORD PTR [rip+0x200b52]        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  4004d6:	68 02 00 00 00       	push   0x2
  4004db:	e9 c0 ff ff ff       	jmp    4004a0 <_init+0x20>

00000000004004e0 <__isoc99_scanf@plt>:
  4004e0:	ff 25 4a 0b 20 00    	jmp    QWORD PTR [rip+0x200b4a]        # 601030 <_GLOBAL_OFFSET_TABLE_+0x30>
  4004e6:	68 03 00 00 00       	push   0x3
  4004eb:	e9 b0 ff ff ff       	jmp    4004a0 <_init+0x20>

Disassembly of section .plt.got:

00000000004004f0 <.plt.got>:
  4004f0:	ff 25 02 0b 20 00    	jmp    QWORD PTR [rip+0x200b02]        # 600ff8 <_DYNAMIC+0x1d0>
  4004f6:	66 90                	xchg   ax,ax

Disassembly of section .text:

0000000000400500 <_start>:
  400500:	31 ed                	xor    ebp,ebp
  400502:	49 89 d1             	mov    r9,rdx
  400505:	5e                   	pop    rsi
  400506:	48 89 e2             	mov    rdx,rsp
  400509:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
  40050d:	50                   	push   rax
  40050e:	54                   	push   rsp
  40050f:	49 c7 c0 20 07 40 00 	mov    r8,0x400720
  400516:	48 c7 c1 b0 06 40 00 	mov    rcx,0x4006b0
  40051d:	48 c7 c7 f6 05 40 00 	mov    rdi,0x4005f6
  400524:	e8 a7 ff ff ff       	call   4004d0 <__libc_start_main@plt>
  400529:	f4                   	hlt    
  40052a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000400530 <deregister_tm_clones>:
  400530:	b8 4f 10 60 00       	mov    eax,0x60104f
  400535:	55                   	push   rbp
  400536:	48 2d 48 10 60 00    	sub    rax,0x601048
  40053c:	48 83 f8 0e          	cmp    rax,0xe
  400540:	48 89 e5             	mov    rbp,rsp
  400543:	76 1b                	jbe    400560 <deregister_tm_clones+0x30>
  400545:	b8 00 00 00 00       	mov    eax,0x0
  40054a:	48 85 c0             	test   rax,rax
  40054d:	74 11                	je     400560 <deregister_tm_clones+0x30>
  40054f:	5d                   	pop    rbp
  400550:	bf 48 10 60 00       	mov    edi,0x601048
  400555:	ff e0                	jmp    rax
  400557:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
  40055e:	00 00 
  400560:	5d                   	pop    rbp
  400561:	c3                   	ret    
  400562:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
  400566:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  40056d:	00 00 00 

0000000000400570 <register_tm_clones>:
  400570:	be 48 10 60 00       	mov    esi,0x601048
  400575:	55                   	push   rbp
  400576:	48 81 ee 48 10 60 00 	sub    rsi,0x601048
  40057d:	48 c1 fe 03          	sar    rsi,0x3
  400581:	48 89 e5             	mov    rbp,rsp
  400584:	48 89 f0             	mov    rax,rsi
  400587:	48 c1 e8 3f          	shr    rax,0x3f
  40058b:	48 01 c6             	add    rsi,rax
  40058e:	48 d1 fe             	sar    rsi,1
  400591:	74 15                	je     4005a8 <register_tm_clones+0x38>
  400593:	b8 00 00 00 00       	mov    eax,0x0
  400598:	48 85 c0             	test   rax,rax
  40059b:	74 0b                	je     4005a8 <register_tm_clones+0x38>
  40059d:	5d                   	pop    rbp
  40059e:	bf 48 10 60 00       	mov    edi,0x601048
  4005a3:	ff e0                	jmp    rax
  4005a5:	0f 1f 00             	nop    DWORD PTR [rax]
  4005a8:	5d                   	pop    rbp
  4005a9:	c3                   	ret    
  4005aa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

00000000004005b0 <__do_global_dtors_aux>:
  4005b0:	80 3d 91 0a 20 00 00 	cmp    BYTE PTR [rip+0x200a91],0x0        # 601048 <__TMC_END__>
  4005b7:	75 11                	jne    4005ca <__do_global_dtors_aux+0x1a>
  4005b9:	55                   	push   rbp
  4005ba:	48 89 e5             	mov    rbp,rsp
  4005bd:	e8 6e ff ff ff       	call   400530 <deregister_tm_clones>
  4005c2:	5d                   	pop    rbp
  4005c3:	c6 05 7e 0a 20 00 01 	mov    BYTE PTR [rip+0x200a7e],0x1        # 601048 <__TMC_END__>
  4005ca:	f3 c3                	repz ret 
  4005cc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

00000000004005d0 <frame_dummy>:
  4005d0:	bf 20 0e 60 00       	mov    edi,0x600e20
  4005d5:	48 83 3f 00          	cmp    QWORD PTR [rdi],0x0
  4005d9:	75 05                	jne    4005e0 <frame_dummy+0x10>
  4005db:	eb 93                	jmp    400570 <register_tm_clones>
  4005dd:	0f 1f 00             	nop    DWORD PTR [rax]
  4005e0:	b8 00 00 00 00       	mov    eax,0x0
  4005e5:	48 85 c0             	test   rax,rax
  4005e8:	74 f1                	je     4005db <frame_dummy+0xb>
  4005ea:	55                   	push   rbp
  4005eb:	48 89 e5             	mov    rbp,rsp
  4005ee:	ff d0                	call   rax
  4005f0:	5d                   	pop    rbp
  4005f1:	e9 7a ff ff ff       	jmp    400570 <register_tm_clones>

00000000004005f6 <main>:
  4005f6:	55                   	push   rbp
  4005f7:	48 89 e5             	mov    rbp,rsp
  4005fa:	48 83 ec 10          	sub    rsp,0x10
  4005fe:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  400605:	00 00 
  400607:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  40060b:	31 c0                	xor    eax,eax
  40060d:	bf 34 07 40 00       	mov    edi,0x400734
  400612:	b8 00 00 00 00       	mov    eax,0x0
  400617:	e8 a4 fe ff ff       	call   4004c0 <printf@plt>
  40061c:	48 8d 45 f4          	lea    rax,[rbp-0xc]
  400620:	48 89 c6             	mov    rsi,rax
  400623:	bf 45 07 40 00       	mov    edi,0x400745
  400628:	b8 00 00 00 00       	mov    eax,0x0
  40062d:	e8 ae fe ff ff       	call   4004e0 <__isoc99_scanf@plt>
  400632:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
  400635:	89 c7                	mov    edi,eax
  400637:	e8 2e 00 00 00       	call   40066a <factorial>
  40063c:	48 89 c2             	mov    rdx,rax
  40063f:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
  400642:	89 c6                	mov    esi,eax
  400644:	bf 48 07 40 00       	mov    edi,0x400748
  400649:	b8 00 00 00 00       	mov    eax,0x0
  40064e:	e8 6d fe ff ff       	call   4004c0 <printf@plt>
  400653:	90                   	nop
  400654:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  400658:	64 48 33 04 25 28 00 	xor    rax,QWORD PTR fs:0x28
  40065f:	00 00 
  400661:	74 05                	je     400668 <main+0x72>
  400663:	e8 48 fe ff ff       	call   4004b0 <__stack_chk_fail@plt>
  400668:	c9                   	leave  
  400669:	c3                   	ret    

000000000040066a <factorial>:
  40066a:	55                   	push   rbp
  40066b:	48 89 e5             	mov    rbp,rsp
  40066e:	53                   	push   rbx
  40066f:	48 83 ec 18          	sub    rsp,0x18
  400673:	89 7d ec             	mov    DWORD PTR [rbp-0x14],edi
  400676:	83 7d ec 01          	cmp    DWORD PTR [rbp-0x14],0x1
  40067a:	75 07                	jne    400683 <factorial+0x19>
  40067c:	b8 01 00 00 00       	mov    eax,0x1
  400681:	eb 17                	jmp    40069a <factorial+0x30>
  400683:	8b 45 ec             	mov    eax,DWORD PTR [rbp-0x14]
  400686:	48 63 d8             	movsxd rbx,eax
  400689:	8b 45 ec             	mov    eax,DWORD PTR [rbp-0x14]
  40068c:	83 e8 01             	sub    eax,0x1
  40068f:	89 c7                	mov    edi,eax
  400691:	e8 d4 ff ff ff       	call   40066a <factorial>
  400696:	48 0f af c3          	imul   rax,rbx
  40069a:	48 83 c4 18          	add    rsp,0x18
  40069e:	5b                   	pop    rbx
  40069f:	5d                   	pop    rbp
  4006a0:	c3                   	ret    
  4006a1:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  4006a8:	00 00 00 
  4006ab:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000004006b0 <__libc_csu_init>:
  4006b0:	41 57                	push   r15
  4006b2:	41 56                	push   r14
  4006b4:	41 89 ff             	mov    r15d,edi
  4006b7:	41 55                	push   r13
  4006b9:	41 54                	push   r12
  4006bb:	4c 8d 25 4e 07 20 00 	lea    r12,[rip+0x20074e]        # 600e10 <__frame_dummy_init_array_entry>
  4006c2:	55                   	push   rbp
  4006c3:	48 8d 2d 4e 07 20 00 	lea    rbp,[rip+0x20074e]        # 600e18 <__init_array_end>
  4006ca:	53                   	push   rbx
  4006cb:	49 89 f6             	mov    r14,rsi
  4006ce:	49 89 d5             	mov    r13,rdx
  4006d1:	4c 29 e5             	sub    rbp,r12
  4006d4:	48 83 ec 08          	sub    rsp,0x8
  4006d8:	48 c1 fd 03          	sar    rbp,0x3
  4006dc:	e8 9f fd ff ff       	call   400480 <_init>
  4006e1:	48 85 ed             	test   rbp,rbp
  4006e4:	74 20                	je     400706 <__libc_csu_init+0x56>
  4006e6:	31 db                	xor    ebx,ebx
  4006e8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
  4006ef:	00 
  4006f0:	4c 89 ea             	mov    rdx,r13
  4006f3:	4c 89 f6             	mov    rsi,r14
  4006f6:	44 89 ff             	mov    edi,r15d
  4006f9:	41 ff 14 dc          	call   QWORD PTR [r12+rbx*8]
  4006fd:	48 83 c3 01          	add    rbx,0x1
  400701:	48 39 eb             	cmp    rbx,rbp
  400704:	75 ea                	jne    4006f0 <__libc_csu_init+0x40>
  400706:	48 83 c4 08          	add    rsp,0x8
  40070a:	5b                   	pop    rbx
  40070b:	5d                   	pop    rbp
  40070c:	41 5c                	pop    r12
  40070e:	41 5d                	pop    r13
  400710:	41 5e                	pop    r14
  400712:	41 5f                	pop    r15
  400714:	c3                   	ret    
  400715:	90                   	nop
  400716:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  40071d:	00 00 00 

0000000000400720 <__libc_csu_fini>:
  400720:	f3 c3                	repz ret 

Disassembly of section .fini:

0000000000400724 <_fini>:
  400724:	48 83 ec 08          	sub    rsp,0x8
  400728:	48 83 c4 08          	add    rsp,0x8
  40072c:	c3                   	ret  
```
