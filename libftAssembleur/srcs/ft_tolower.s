;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/24 02:09:04 by bchoukri          #+#    #+#              ;
;    Updated: 2015/04/24 02:10:29 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;



	global _ft_tolower

_ft_tolower:
	cmp rdi, 65
	jl no
	cmp rdi, 91
	jae no
	add rdi, 32
	mov rax, rdi

no:
	mov rax, rdi
	ret