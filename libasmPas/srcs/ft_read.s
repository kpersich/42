; rax == return, rdi == filedes, rsi == buf, rdx  == nbyte ;

extern ___error
segment .text
	global _ft_read

_ft_read:
	mov rax, 0x2000003
	syscall
	jc error
	ret

error:
	push rax
	call ___error
	pop qword[rax]
	mov rax, -1
	ret
