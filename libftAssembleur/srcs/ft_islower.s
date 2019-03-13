;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_islower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/28 16:02:25 by bchoukri          #+#    #+#              ;
;    Updated: 2015/05/28 16:03:03 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_islower

_ft_islower:
	cmp rdi, 97
	jl is_wrong
	cmp rdi, 122
	jg is_wrong
	mov rax, 1
	ret

is_wrong:
	mov rax, 0
	ret