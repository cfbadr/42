;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isspace.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/28 16:16:25 by bchoukri          #+#    #+#              ;
;    Updated: 2015/05/28 16:16:44 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_isspace

_ft_isspace:
	cmp		rdi, 32
	je		true
	cmp		rdi, 11
	je		true
	cmp		rdi, 10
	je		true
	cmp		rdi, 9
	je		true
	cmp		rdi, 13
	je		true
	cmp		rdi, 12
	je		true
	mov		rax, 0
	ret

true:
	mov		rax, 1
	ret