;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/27 16:00:58 by bchoukri          #+#    #+#              ;
;    Updated: 2015/05/28 16:45:32 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

%define WRITE 0x2000004
extern _ft_strlen
	global _ft_puts

	section .data
null:
	.string db "(null)", 10
	.len equ $ - null.string

	section .text

_ft_puts:
	cmp rdi, 0
	je is_null
	mov rsi, rdi
	call _ft_strlen
	mov rdi, 1
	mov rdx, rax
	mov rax, WRITE
	syscall
	push 10
	mov rsi, rsp
	mov rdi, 1
	mov rdx, 1
	mov rax, WRITE
	syscall
	add rsp, 8
	mov rax, 10
	ret

is_null:
	mov rdi, 1
	lea rsi, [rel null.string]
	mov rdx, null.len
	mov rax, 0x2000004
	syscall
	mov rax, 10
	ret