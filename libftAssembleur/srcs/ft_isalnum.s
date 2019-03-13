;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalnum.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/22 22:56:16 by bchoukri          #+#    #+#              ;
;    Updated: 2015/04/24 00:19:53 by bchoukri         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

extern	_ft_isalpha
extern	_ft_isdigit
global	_ft_isalnum

_ft_isalnum:
	call _ft_isalpha
	cmp rax, 1
	je return
	call _ft_isdigit
	ret
return:
	ret