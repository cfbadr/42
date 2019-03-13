;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/27 14:39:22 by bchoukri          #+#    #+#              ;
;    Updated: 2015/05/27 14:44:53 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_strlen

	section .text

_ft_strlen:
	mov rcx, -1
	mov al, 0
	cld
	repne scasb
	mov rax, -2
	sub rax, rcx
	ret