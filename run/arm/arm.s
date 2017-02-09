.lcomm buf2, 2
.global prints, readb, _exit, _start
.extern _env, _strlen, _main
.section .text

prints:
	push {lr}
        push {r0}
	bl	_strlen
	mov	r2, r0
	mov r0, $0 @ stdout
        pop {r1}
        mov r7, $4 @ write
        swi 0
        pop {pc}

readb:
	push	{lr}
	mov r0, $0 @ stdin
        ldr r1, =buf2
        mov r2, $1 @ 1-byte
        mov r7, $3 @ read
        swi 0
        cmp	r0, $1
	bne	.Lret
        ldr r1, =buf2
        ldrb r0, [r1]
.Lret:
        pop {pc}

_start:	
        ldr r0, =_env
        str sp, [r0]
        ldr r0, [sp] @ argc
        add r1, sp, $4 @ argv
        add r2, r1, r0, LSL#2
        add r2, r2, $4 @ envp = &argv[argc]+1
        mov fp, $0 @ init frame pointer
@ start program
	bl	_main
	bl	_exit

_exit:
	ldr r7, =1
	swi 0
	b	_exit
