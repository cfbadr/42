;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isascii.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/24 01:33:19 by bchoukri          #+#    #+#              ;
;    Updated: 2015/04/24 01:36:38 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_isascii

_ft_isascii:	
	cmp rdi, 0
	jl no
	cmp rdi, 128
	jl yes
	jmp no

yes:
	mov rax, 1
	ret

no:
	mov rax, 0
	ret
	