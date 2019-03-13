;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isblank.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/28 16:04:47 by bchoukri          #+#    #+#              ;
;    Updated: 2015/05/28 16:05:08 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_isblank

_ft_isblank:
	cmp		rdi, 9
	je		success
	cmp		rdi, 32
	je		success
	mov		rax, 0
	ret

success:
	mov		rax, 1
	ret