;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/27 18:52:04 by bchoukri          #+#    #+#              ;
;    Updated: 2015/05/27 18:52:17 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_memset

section .text

_ft_memset:
	push rdi
	mov rcx, rdx
	mov rax, rsi
	cld
	rep stosb
	pop rax
	ret