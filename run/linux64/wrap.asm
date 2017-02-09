section .text
	global _putstr, _putint, _getint, _getstr, _getchar
	extern _prints, _printi, _readi, _readln, _readb

_putstr:	jmp _prints
_putint:	jmp _printi
_getint:	jmp _readi
_getstr:	jmp _readln
_getchar:	jmp _readb
