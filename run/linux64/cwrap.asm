section .text
	global _char, _lchar, _putchar, prints
	extern Char, lchar, putchar, _prints

_char:
	mov	rdi, [rsp+8]
	mov	rsi, [rsp+16]
	jmp	Char
_lchar:	
	mov	rdi, [rsp+8]
	mov	rsi, [rsp+16]
	mov	rdx, [rsp+24]
	jmp	lchar
_putchar:
	mov	rdi, [rsp+8]
	jmp	putchar
prints:
	push	qword rdi
	call	_prints
	add	rsp, 8
