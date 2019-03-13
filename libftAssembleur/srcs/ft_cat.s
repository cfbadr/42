;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/28 15:48:26 by bchoukri          #+#    #+#              ;
;    Updated: 2015/05/28 15:48:57 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;


%define WRITE 0x2000004
%define READ 0x2000003

section .bss
	buff resb 1024
	buff_size equ $-buff

	section .text
	global _ft_cat

_ft_cat:
loop:
		push rdi
		lea rsi, [rel buff]
		mov rdx, buff_size
		mov rax, READ
		syscall
		jc end
		cmp rax, 0
		jle end
		mov rdi, 1
		mov rdx, rax
		mov rax, WRITE
		syscall
		pop rdi
	jmp loop

end:
	pop rdi
	ret