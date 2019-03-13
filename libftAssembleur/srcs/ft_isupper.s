;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/28 15:58:31 by bchoukri          #+#    #+#              ;
;    Updated: 2015/05/28 16:00:24 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text

	global _ft_isupper

_ft_isupper:
	cmp rdi, 65
	jl is_wrong
	cmp rdi, 90
	jg is_wrong
	mov rax, 1
	ret

is_wrong:
	mov rax, 0
	ret