; rax == return, rdi == filedes, rsi == buf, rdx  == nbyte ;

extern ___error
segment .text
	global _ft_write

_ft_write:
	mov rax, 0x2000004
	syscall
	jc error
	ret

error:
	push rax
	call ___error
	pop qword[rax]
	mov rax, -1
	ret
