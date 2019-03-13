;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/24 02:13:43 by bchoukri          #+#    #+#              ;
;    Updated: 2015/05/28 16:32:52 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_bzero

_ft_bzero:
	cmp rdi, 0
	je end

question:	
	cmp rsi, 0
	je end
	cmp rsi, 0
loop:
	dec rsi
	mov [rdi], byte 0
	inc rdi
	jmp question

end:
	ret