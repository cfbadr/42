;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/24 01:55:59 by bchoukri          #+#    #+#              ;
;    Updated: 2015/04/24 02:07:47 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;


	global _ft_toupper

_ft_toupper:
	cmp rdi, 97
	jl no
	cmp rdi, 123
	jae no
	sub rdi, 32
	mov rax, rdi

no:
	mov rax, rdi
	ret