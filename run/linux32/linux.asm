section .bss
	$buf2	resb	2

section .text
	global _prints, _readb, _exit, _start
	extern _env, _strlen, _main

_prints:
	push	dword [esp+4]		; pushd 'prints' first argument
	call	_strlen
	mov	edx, eax
	pop	ecx		; pop-it back, instead of 'add esp,4' and 'mov ecx, [esp+4]'
	mov	eax, 4
	mov	ebx, 1
	int	0x80
	ret

_readb:
	push	ebx
	push	ecx
	push	edx
	mov	edx, 1
	mov	ecx, $buf2
	mov	ebx, 0
	mov	eax, 3
	int	0x80
	cmp	eax, 1
	jne	.Lret
	xor	eax, eax
	mov	al, [$buf2]
.Lret:	pop	edx
	pop	ecx
	pop	ebx
	ret

_start:	
	mov	[$_env], esp
	mov	eax, [esp]	; argc
	lea	ebx, [esp+4]	; argv
	lea	edx, [ebx+eax*4]; &(argv[argc])
	add	edx, 4		; envp
	push	dword 0
	mov	ebp, esp	; init frame pointer
	push	edx
	push	ebx
	push	eax
; truncate real to integer conversions
	fstcw	word [buf2]
	or	word [buf2], 0x0C00
	fldcw	word [buf2]
; start program
	call	_main
	push	eax
	call	_exit

_exit:	mov	ebx, [esp+4]
.L0:	mov	eax, 1
	int	0x80
	jmp	.L0
