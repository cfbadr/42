;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalalpha.s                                     :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/23 23:08:23 by bchoukri          #+#    #+#              ;
;    Updated: 2015/04/24 00:18:06 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global	_ft_isalpha

_ft_isalpha:
	cmp rdi, 65
	jl no
	cmp rdi, 91
	jl yes
	cmp rdi, 97
	jl no
	cmp  rdi, 123
	jl yes
	jmp no

no:
	mov rax, 0
	ret

yes:
	mov rax, 1
	ret