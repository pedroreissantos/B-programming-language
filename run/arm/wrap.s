.section .text
.global _putstr@function
.global _putint@function
.global _getint@function
.global _getchar@function
.global _getstr@function
.global _argc@function
.global _argv@function
.global _envp@function
.global _atoi@function
.global _itoa@function
.global _println@function
.global _prints@function
.global _printsp@function
.global _readb@function
.global _readi@function
.global _readln@function
.global _strlen@function

_putstr:	b prints
_putint:	b printi
_getint:	b readi
_getchar:	b readb
_getstr:	b readln
_argc:		b argc
_argv:		b argv
_envp:		b envp
_atoi:		b atoi
_itoa:		b itoa
_println:	b println
_prints:	b prints
_printsp:	b printsp
_readb:		b readb
_readi:		b readi
_readln:	b readln
_strlen:	b strlen
