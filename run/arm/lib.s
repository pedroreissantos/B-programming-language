	.arch armv5te
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 18, 4
	.file	"lib.c"
	.global	_env
	.bss
	.align	2
	.type	_env, %object
	.size	_env, 4
_env:
	.space	4
	.data
	.align	2
	.type	nl, %object
	.size	nl, 2
nl:
	.ascii	"\012\000"
	.align	2
	.type	sp, %object
	.size	sp, 2
sp:
	.ascii	" \000"
	.local	buffer
	.comm	buffer,32,4
	.text
	.align	2
	.global	argc
	.type	argc, %function
argc:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	ldr	r3, .L2
.LPIC0:
	add	r3, pc, r3
	ldr	r2, .L2+4
	ldr	r3, [r3, r2]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #0]
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.L3:
	.align	2
.L2:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC0+8)
	.word	_env(GOT)
	.size	argc, .-argc
	.align	2
	.global	argv
	.type	argv, %function
argv:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	r0, [fp, #-8]
	ldr	r3, .L5
.LPIC1:
	add	r3, pc, r3
	ldr	r2, .L5+4
	ldr	r3, [r3, r2]
	ldr	r2, [r3, #0]
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	mov	r3, r3, asl #2
	add	r3, r2, r3
	ldr	r3, [r3, #0]
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.L6:
	.align	2
.L5:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC1+8)
	.word	_env(GOT)
	.size	argv, .-argv
	.align	2
	.global	envp
	.type	envp, %function
envp:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	r0, [fp, #-8]
	ldr	r3, .L8
.LPIC2:
	add	r3, pc, r3
	ldr	r2, .L8+4
	ldr	r2, [r3, r2]
	ldr	r2, [r2, #0]
	ldr	r1, .L8+4
	ldr	r3, [r3, r1]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #0]
	mov	r1, r3
	ldr	r3, [fp, #-8]
	add	r3, r1, r3
	add	r3, r3, #2
	mov	r3, r3, asl #2
	add	r3, r2, r3
	ldr	r3, [r3, #0]
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.L9:
	.align	2
.L8:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC2+8)
	.word	_env(GOT)
	.size	envp, .-envp
	.align	2
	.global	_strlen
	.type	_strlen, %function
_strlen:
	mov	r3, r0
.L:
	ldrb	r2, [r3, #0]	@ zero_extendqisi2
	add	r3, r3, #1
	cmp	r2, #0
	bne	.L
	sub	r3, r3, r0
	sub	r0, r3, #1
	bx	lr
strlen:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-16]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L11
.L12:
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L11:
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-16]
	add	r3, r2, r3
	ldrb	r3, [r3, #0]	@ zero_extendqisi2
	cmp	r3, #0
	bne	.L12
	ldr	r3, [fp, #-8]
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
	.size	_strlen, .-_strlen
	.align	2
	.global	println
	.type	println, %function
println:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	ldr	r3, .L14
.LPIC3:
	add	r3, pc, r3
	mov	r0, r3
	bl	prints(PLT)
	ldmfd	sp!, {fp, pc}
.L15:
	.align	2
.L14:
	.word	nl-(.LPIC3+8)
	.size	println, .-println
	.align	2
	.global	printsp
	.type	printsp, %function
printsp:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	ldr	r3, .L17
.LPIC4:
	add	r3, pc, r3
	mov	r0, r3
	bl	prints(PLT)
	ldmfd	sp!, {fp, pc}
.L18:
	.align	2
.L17:
	.word	sp-(.LPIC4+8)
	.size	printsp, .-printsp
	.align	2
	.global	debug
	.type	debug, %function
debug:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
	.size	debug, .-debug
	.align	2
	.global	atoi
	.type	atoi, %function
atoi:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-16]
	mov	r3, #0
	str	r3, [fp, #-8]
	mov	r3, #1
	strh	r3, [fp, #-10]	@ movhi
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #0]	@ zero_extendqisi2
	cmp	r3, #45
	bne	.L25
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
	mvn	r3, #0
	strh	r3, [fp, #-10]	@ movhi
	b	.L25
.L24:
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #0]	@ zero_extendqisi2
	cmp	r3, #47
	bls	.L23
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #0]	@ zero_extendqisi2
	cmp	r3, #57
	bhi	.L23
	ldr	r2, [fp, #-8]
	mov	r3, r2
	mov	r3, r3, asl #2
	add	r3, r3, r2
	mov	r3, r3, asl #1
	mov	r2, r3
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #0]	@ zero_extendqisi2
	add	r3, r2, r3
	sub	r3, r3, #48
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
	b	.L22
.L25:
	mov	r0, r0	@ nop
.L22:
	ldr	r3, [fp, #-16]
	ldrb	r3, [r3, #0]	@ zero_extendqisi2
	cmp	r3, #0
	bne	.L24
.L23:
	ldrsh	r3, [fp, #-10]
	ldr	r2, [fp, #-8]
	mul	r3, r2, r3
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
	.size	atoi, .-atoi
	.align	2
	.global	itoa
	.type	itoa, %function
itoa:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-16]
	mov	r3, #31
	str	r3, [fp, #-8]
	mov	r3, #0
	str	r3, [fp, #-12]
	ldr	r3, .L29
.LPIC5:
	add	r3, pc, r3
	ldr	r2, [fp, #-8]
	add	r3, r3, r2
	mov	r2, #0
	strb	r2, [r3, #0]
	ldr	r3, [fp, #-8]
	sub	r3, r3, #1
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-16]
	cmp	r3, #0
	bge	.L27
	mov	r3, #1
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-16]
	rsb	r3, r3, #0
	str	r3, [fp, #-16]
.L27:
	ldr	r1, [fp, #-16]
	ldr	r3, .L29+4
	smull	r2, r3, r1, r3
	mov	r2, r3, asr #2
	mov	r3, r1, asr #31
	rsb	r2, r3, r2
	mov	r3, r2
	mov	r3, r3, asl #2
	add	r3, r3, r2
	mov	r3, r3, asl #1
	rsb	r2, r3, r1
	and	r3, r2, #255
	add	r3, r3, #48
	and	r2, r3, #255
	ldr	r3, .L29+8
.LPIC6:
	add	r3, pc, r3
	ldr	r1, [fp, #-8]
	add	r3, r3, r1
	strb	r2, [r3, #0]
	ldr	r3, [fp, #-8]
	sub	r3, r3, #1
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-16]
	ldr	r2, .L29+4
	smull	r1, r2, r3, r2
	mov	r2, r2, asr #2
	mov	r3, r3, asr #31
	rsb	r3, r3, r2
	str	r3, [fp, #-16]
	ldr	r3, [fp, #-16]
	cmp	r3, #0
	bne	.L27
	ldr	r3, [fp, #-12]
	cmp	r3, #0
	beq	.L28
	ldr	r3, .L29+12
.LPIC7:
	add	r3, pc, r3
	ldr	r2, [fp, #-8]
	add	r3, r3, r2
	mov	r2, #45
	strb	r2, [r3, #0]
	ldr	r3, [fp, #-8]
	sub	r3, r3, #1
	str	r3, [fp, #-8]
.L28:
	ldr	r3, [fp, #-8]
	add	r2, r3, #1
	ldr	r3, .L29+16
.LPIC8:
	add	r3, pc, r3
	add	r3, r2, r3
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.L30:
	.align	2
.L29:
	.word	buffer-(.LPIC5+8)
	.word	1717986919
	.word	buffer-(.LPIC6+8)
	.word	buffer-(.LPIC7+8)
	.word	buffer-(.LPIC8+8)
	.size	itoa, .-itoa
	.align	2
	.global	printi
	.type	printi, %function
printi:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	ldr	r0, [fp, #-8]
	bl	itoa(PLT)
	mov	r3, r0
	mov	r0, r3
	bl	prints(PLT)
	sub	sp, fp, #4
	ldmfd	sp!, {fp, pc}
	.size	printi, .-printi
	.align	2
	.global	readln
	.type	readln, %function
readln:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-16]
	str	r1, [fp, #-20]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L33
.L37:
	ldr	r3, [fp, #-12]
	cmp	r3, #10
	beq	.L34
	ldr	r2, [fp, #-20]
	ldr	r3, [fp, #-8]
	rsb	r3, r3, r2
	cmp	r3, #1
	bne	.L35
.L34:
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-16]
	add	r3, r2, r3
	mov	r2, #0
	strb	r2, [r3, #0]
	ldr	r3, [fp, #-16]
	b	.L36
.L35:
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-16]
	add	r3, r2, r3
	ldr	r2, [fp, #-12]
	and	r2, r2, #255
	strb	r2, [r3, #0]
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L33:
	bl	readb(PLT)
	str	r0, [fp, #-12]
	ldr	r3, [fp, #-12]
	cmp	r3, #0
	bgt	.L37
	ldr	r3, [fp, #-16]
.L36:
	mov	r0, r3
	sub	sp, fp, #4
	ldmfd	sp!, {fp, pc}
	.size	readln, .-readln
	.align	2
	.global	readi
	.type	readi, %function
readi:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	ldr	r3, .L41
.LPIC9:
	add	r3, pc, r3
	mov	r0, r3
	mov	r1, #32
	bl	readln(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L39
	ldr	r3, .L41+4
.LPIC10:
	add	r3, pc, r3
	mov	r0, r3
	bl	atoi(PLT)
	mov	r3, r0
	b	.L40
.L39:
	mvn	r3, #0
.L40:
	mov	r0, r3
	ldmfd	sp!, {fp, pc}
.L42:
	.align	2
.L41:
	.word	buffer-(.LPIC9+8)
	.word	buffer-(.LPIC10+8)
	.size	readi, .-readi
	.ident	"GCC: (GNU) 4.6.0"
	.section	.note.GNU-stack,"",%progbits
