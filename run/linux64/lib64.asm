BUFsiz	equ	64

section .rodata
	$nl	db	10, 0
	$sp	db	32, 0
section .data
	global _env
	$bufsiz	dq	BUFsiz
	$_env	dq	0

section .bss
	$buffer	resb	BUFsiz

section .text
	global _println, _printsp, _printi, _readln, _readi, _debug
	global _strlen, _atoi, _itoa, _argc, _argv, _envp
	extern _prints, _readb

_argc:	mov	rax, [abs qword _env]
	mov	rax, [rax]
	ret

_argv:	mov	rax, [abs qword _env]
	add	rax, 8
	mov	rbx, [rsp+8]
	lea	rax, [rax+rbx*8]
	mov	rax, [rax]
	ret

_envp:	mov	rax, [abs qword _env]
	mov	rbx, rax
	mov	rdx, [rbx]
	lea	rax, [rbx+rdx*8+16]
	mov	rbx, [rsp+8]
	lea	rax, [rax+rbx*8]
	mov	rax, [rax]
	ret

_strlen:
	mov	rdx, [rsp+8]
	cmp	byte [rdx], 0
	mov	rax, rdx
	je	.Lend
.Lrep:	inc	rax
	cmp	byte [rax], 0
	jne	.Lrep
.Lend:	sub	rax, rdx
	ret

_println:
	mov	rax, $nl
	push	rax
	call	_prints
	add	rsp, 8
	ret

_printsp:
	mov	rax, $nl
	push	rax
.Lmais:	;cmp	qword [rsp+16], 0
	mov	rax, [rsp+16]
	cmp	rax, 0
	jle	.Lfim
	call	_prints
	dec	qword [rsp+16]
	jmp	.Lmais
.Lfim:	add	rsp, 8
	ret

_debug:	ret

_itoa:
	mov	rcx, [rsp+8]	; load arg
	mov	rdi, $buffer+30
	mov	rsi, 0
	test	rcx, rcx
	jge	.L8
	inc	rsi
	neg	rcx
.L8:	mov	[rdi], byte 0	; put the NULL character and walk backwards
	dec	rdi
	mov	rbx, 10
.L9:	mov	rax, rcx
	xor	rdx, rdx
	div	rbx
	mov	rcx, rax
	add	rdx, byte '0'
	mov	[rdi], dl
	dec	rdi
	test	rcx, rcx
	jg	.L9
	test	rsi, rsi
	je	.L10
	mov	[rdi], byte '-'
	dec	rdi
.L10:	mov	rax, rdi
	inc	rax
	ret

_printi:
	push	qword [rsp+8]
	call	_itoa
	add	rsp, 8
	push	rax
	call	_prints
	add	rsp, 8
	ret

_atoi:
	mov	rsi, [rsp+8]
	mov	rcx, 1
	xor	rbx, rbx
	xor	rax, rax
	cld
	lodsb
	cmp	rax, '-'
	jne	.L1
	neg	rcx
	lodsb
.L1:	cmp	rax, '0'
	jb	.L2
	cmp	rax, '9'
	ja	.L2
	sub	rax, '0'
	xchg	rbx, rax
	mov	rdx, 10
	mul	rdx
	add	rbx, rax
	xor	rax, rax
	lodsb
	jmp	.L1
.L2:	mov	rax, rbx
	mul	rcx
	ret

_readln:			; readln(buf, siz)
	mov	rcx, [rsp+16]	;
	mov	rdi, [rsp+8]	;
	cld
_Lnext:	call	_readb
	cmp	rax, 0
	jle	_Lerr
	cmp	rax, 10
	je	_Lend
	cmp	rcx, 1
	jle	_Lend
	stosb
	dec	rcx
	jmp	_Lnext
_Lend:	xor	rax, rax
	stosb
	mov	rax, [rsp+8]
	ret
_Lerr:	xor	rax, rax
	ret

_readi:
	mov	rax, $bufsiz
	push	rax
	mov	rax, $buffer
	push	rax
	call	_readln
	add	rsp, 16
	cmp	rax, 0
	je	.Lerr
	push	rax
	call	_atoi
	add	rsp,8
	ret
.Lerr:	mov	rax, 0x8000000000000000
	ret
