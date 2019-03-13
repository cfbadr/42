;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_ispunct.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/28 16:10:01 by bchoukri          #+#    #+#              ;
;    Updated: 2015/05/28 16:10:14 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global	_ft_ispunct

_ft_ispunct:
	cmp		rdi, 33
	jl		failed
	cmp		rdi, 47
	jle		success
	cmp		rdi, 58
	jl		failed
	cmp		rdi, 64
	jle		success
	cmp		rdi, 91
	jl		failed
	cmp		rdi, 96
	jle		success
	cmp		rdi, 123
	jl		failed
	cmp		rdi, 126
	jle		success

failed:
	mov		rax, 0
	ret

success:
	mov		rax, 1
	ret