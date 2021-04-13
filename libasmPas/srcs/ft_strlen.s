; rax == return && index, rdi == string ;

segment .text
	global _ft_strlen

_ft_strlen:
	mov rax, 0				; set return to 0
	jmp loop

exit:
	ret

loop:
	cmp byte [rdi + rax], 0	; see if current char is 0
	je exit					; exit if char is 0
	inc rax					; increment return && index
	jmp loop