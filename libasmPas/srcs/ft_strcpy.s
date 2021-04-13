; rax == return, rdx == index, rdi == dest, rsi == src ;

segment .text
	global _ft_strcpy

_ft_strcpy:
	mov rdx, 0
	jmp loop

loop:
	cmp byte [rsi + rdx], 0		; see if char exists
	je exit
	mov al, byte [rsi + rdx]	; copy to 8 bit register
	mov byte [rdi + rdx], al	; copy register to dest
	inc rdx
	jmp loop

exit:
	mov byte [rdi + rdx], 0		; null terminate dest
	mov rax, rdi				; copy to return register
	ret