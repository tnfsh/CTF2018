# c語言程式編譯與組譯

主程式

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

預處理階段

>gcc -E factorial.c -o factorial.i

```
https://github.com/saho-yu/CTF2018/blob/master/Reverse/factorial.i
```
編譯階段==>產生組語

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
組譯階段==>產生物件檔

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

連結階段==>產生執行檔(附檔名不影響)

>gcc factorial.o -o factorial

執行factorial

>./factorial

範例:輸入5
```
please insert n:5
5!=120
```

產生AT&T語法格式的組語(gcc預設使用的格式)

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

產生Intel語法格式的組語(微軟預設使用的格式)

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
要去掉一堆註解:請加上參數-fno-asynchronous-unwind-tables

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

組譯過程

>* 將組合語言程式碼轉成機器可以執行的指令(instructions)
>* 每一個組語語句都對應一機器指令。
>* 組譯器的組譯過程相對於編譯器來講比較簡單
>* 沒有複雜的語法，也沒有語意，也不需要做指令最佳化，只是根據組語指令和機器指令的對照表一一翻譯就可以


