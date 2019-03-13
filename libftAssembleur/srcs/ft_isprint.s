;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isprint.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/24 01:37:56 by bchoukri          #+#    #+#              ;
;    Updated: 2015/04/24 01:41:09 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_isprint

_ft_isprint:
	cmp rdi, 32
	jl no
	cmp rdi, 127
	jl yes
	jmp no

yes:
	mov rax, 1
	ret

no:
	mov rax, 0
	ret