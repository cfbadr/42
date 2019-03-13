;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/23 23:43:43 by bchoukri          #+#    #+#              ;
;    Updated: 2015/04/24 00:05:46 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_isdigit

_ft_isdigit:
	cmp rdi, 48
	jl no
	cmp rdi, 57
	jle yes
	jmp no

yes:
	mov rax, 1
	ret

no:
	mov rax, 0
	ret 