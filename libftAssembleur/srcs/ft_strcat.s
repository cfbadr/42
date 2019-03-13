;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/24 02:25:25 by bchoukri          #+#    #+#              ;
;    Updated: 2015/05/18 17:23:03 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_strcat

_ft_strcat:
	mov		rax, rdi

loop:
	cmp		byte[rdi], 0
	je		copy
	inc		rdi
	jmp		loop

copy:
	cmp		byte[rsi], 0
	je		end
	movsb
	jmp		copy

end:
	mov		byte[rdi], 0
	ret