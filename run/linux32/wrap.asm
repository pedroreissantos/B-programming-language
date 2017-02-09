section .text
global _getstr:function, _putstr:function, _putint:function, _getint:function, _getchar:function
extern _readln, _prints, _printi, _readi, _readb

_getstr:	jmp _readln
_putstr:	jmp _prints
_putint:	jmp _printi
_getint:	jmp _readi
_getchar:	jmp _readb
