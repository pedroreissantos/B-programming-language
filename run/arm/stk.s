.global printstr, printint, atoint, strlength, argval, printdbl
.extern prints, printi, atoi, _strlen, argv
.text

printstr:
        ldr r0, [sp]
        b prints
printint:
        ldr r0, [sp]
        b printi
atoint:
        ldr r0, [sp]
        b atoi
strlength:
        ldr r0, [sp]
        b _strlen
argval:
        ldr r0, [sp]
        b argv
printdbl:
        ldr     r0, [sp]
        ldr     r1, [sp,#4]
        b printd
