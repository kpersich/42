; rax == return, rcx == index, rdi == s1 , rsi == s2;

segment .text
	global _ft_strcmp

_ft_strcmp:
	mov rcx, 0					; set index && return to 0
	jmp loop

loop:
	movzx rax, byte [rdi + rcx]
	movzx rdx, byte [rsi + rcx]
	cmp rax, rdx				; comparing chars
	jne exit
	cmp rax, 0					; see if string exists
	je exit
	cmp rdx, 0					; see if string exists
	je exit
	inc rcx
	jmp loop

exit:
	sub rax, rdx
	ret