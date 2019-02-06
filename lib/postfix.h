/* $Id: postfix.h,v 1.8 2014/02/22 15:07:12 prs Exp $ */
/* ld --dynamic-linker /lib/ld-linux.so.2 -lc -o program program.o */
#ifndef _postfix_h_
#define _postfix_h_

#define pfCONST pfINTEGER
#define pfINT pfIMM
#define pfDUP pfCOPY
#define pfDUP2 pfCOPY2

#if defined(pfDEBUG)

#define pfCOMM "COMM %s\n"
#define pfNOP "NOP\n"
#define pfIMM "IMM %d\n"
#define pfADD "ADD\n"
#define pfSUB "SUB\n"
#define pfMUL "MUL\n"
#define pfDIV "DIV\n"
#define pfMOD "MOD\n"
#define pfNEG "NEG\n"
#define pfINCR "INCR %d\n"
#define pfDECR "DECR %d\n"
#define pfGT "GT\n"
#define pfGE "GE\n"
#define pfLT "LT\n"
#define pfLE "LE\n"
#define pfEQ "EQ\n"
#define pfNE "NE\n"
#define pfAND "AND\n"
#define pfOR "OR\n"
#define pfXOR "XOR\n"
#define pfNOT "NOT\n"
#define pfROTL "ROTL\n"
#define pfROTR "ROTR\n"
#define pfSHTL "SHTL\n"
#define pfSHTRU "SHTRU\n"
#define pfSHTRS "SHTRS\n"
#define pfLOCAL "LOCAL %d\n"
#define pfADDR "ADDR %s\n"
#define pfLOCV "LOCV %d\n"
#define pfADDRV "ADDRV %s\n"
#define pfLOCA "LOCA %d\n"
#define pfADDRA "ADDRA %s\n"
#define pfLOAD "LOAD\n"
#define pfSTORE "STORE\n"
#define pfLDCHR "LDCHR\n"
#define pfSTCHR "STCHR\n"
#define pfLD16 "LD16\n"
#define pfST16 "ST16\n"
#define pfENTER "ENTER %d\n"
#define pfSTART "START\n"
#define pfALLOC "ALLOC\n"
#define pfLEAVE "LEAVE\n"
#define pfTRASH "TRASH %d\n"
#define pfCALL "CALL %s\n"
#define pfRET "RET\n"
#define pfRETN "RETN %d\n"
#define pfBRANCH "BRANCH\n"
#define pfLEAP "LEAP\n"
#define pfJMP "JMP %s\n"
#define pfJZ "JZ %s\n"
#define pfJNZ "JNZ %s\n"
#define pfCOPY "COPY\n"
#define pfSWAP "SWAP\n"
#define pfSP "SP\n"
#define pfPUSH "PUSH\n"
#define pfPOP "POP\n"
#define pfI2D "I2D\n"
#define pfF2D "F2D\n"
#define pfD2I "D2I\n"
#define pfD2F "D2F\n"
#define pfDADD "DADD\n"
#define pfDSUB "DSUB\n"
#define pfDMUL "DMUL\n"
#define pfDDIV "DDIV\n"
#define pfDCMP "DCMP\n"
#define pfDNEG "DNEG\n"
#define pfLOAD2 "LOAD2\n"
#define pfSTORE2 "STORE2\n"
#define pfCOPY2 "COPY2\n"
#define pfDPUSH "DPUSH\n"
#define pfDPOP "DPOP\n"
#define pfNIL "NIL\n"
#define pfBEGIN "BEGIN %s\n"
#define pfEND "END\n"
#define pfTEXT "TEXT\n"
#define pfRODATA "RODATA\n"
#define pfDATA "DATA\n"
#define pfBSS "BSS\n"
#define pfALIGN "ALIGN\n"
#define pfEXTRN "EXTRN %s\n"
#define pfCOMMON "COMMON %d\n"
#define pfGLOBL "GLOBL %s %s\n"
#define pfLABEL "LABEL %s\n"
#define pfINTEGER "INTEGER %d\n"
#define pfSHORT "SHORT %d\n"
#define pfLONG "LONG %lld\n"
#define pfSTR "STR \"%s\"\n"
#define pfCHAR "CHAR 0x%2.2X\n"
#define pfID "ID %s\n"
#define pfBYTE "BYTE %d\n"
#define pfFLOAT "FLOAT %e\n"
#define pfDOUBLE "DOUBLE %e\n"
#define pfULDCHR "ULDCHR\n"
#define pfULD16 "ULD16\n"
#define pfUDIV "UDIV\n"
#define pfUMOD "UMOD\n"
#define pfUGT "UGT\n"
#define pfUGE "UGE\n"
#define pfULT "ULT\n"
#define pfULE "ULE\n"
#define pfJEQ "JEQ %s\n"
#define pfJNE "JNE %s\n"
#define pfJGT "JGT %s\n"
#define pfJGE "JGE %s\n"
#define pfJLT "JLT %s\n"
#define pfJLE "JLE %s\n"
#define pfJUGT "JUGT %s\n"
#define pfJUGE "JUGE %s\n"
#define pfJULT "JULT %s\n"
#define pfJULE "JULE %s\n"

#define pfLD64 "LD64\n"
#define pfST64 "ST64\n"
#define pfULD64 "ULD64\n"
#define pfLD32 pfLOAD
#define pfST32 pfSTORE
#define pfULD32 pfLOAD

#define pfASM "ASM %s\n"
#define pfBB "BB\n"

#elif defined(pfNUM)

#define pfCOMM	1
#define pfNOP	2
#define pfIMM	3
#define pfADD	4
#define pfSUB	5
#define pfMUL	6
#define pfDIV	7
#define pfMOD	8
#define pfNEG	9
#define pfINCR	10
#define pfDECR	11
#define pfGT	12
#define pfGE	13
#define pfLT	14
#define pfLE	15
#define pfEQ	16
#define pfNE	17
#define pfAND	18
#define pfOR	19
#define pfXOR	20
#define pfNOT	21
#define pfROTL	22
#define pfROTR	23
#define pfSHTL	24
#define pfSHTRU	25
#define pfSHTRS	26
#define pfLOCAL	27
#define pfADDR	28
#define pfLOCV	29
#define pfADDRV	30
#define pfLOCA	31
#define pfADDRA	32
#define pfLOAD	33
#define pfSTORE	34
#define pfLDCHR	35
#define pfSTCHR	36
#define pfLD16	37
#define pfST16	38
#define pfENTER	39
#define pfSTART	40
#define pfALLOC	41
#define pfLEAVE	42
#define pfTRASH	43
#define pfCALL	44
#define pfRET	45
#define pfRETN	46
#define pfBRANCH	47
#define pfLEAP	48
#define pfJMP	49
#define pfJZ	50
#define pfJNZ	51
#define pfCOPY	52
#define pfSWAP	53
#define pfSP	54
#define pfPUSH	55
#define pfPOP	56
#define pfI2D	57
#define pfF2D	58
#define pfD2I	59
#define pfD2F	60
#define pfDADD	61
#define pfDSUB	62
#define pfDMUL	63
#define pfDDIV	64
#define pfDCMP	65
#define pfDNEG	66
#define pfLOAD2	67
#define pfSTORE2	68
#define pfCOPY2	69
#define pfDPUSH	70
#define pfDPOP	71
#define pfNIL	72
#define pfBEGIN	73
#define pfEND	74
#define pfTEXT	75
#define pfRODATA	76
#define pfDATA	77
#define pfBSS	78
#define pfALIGN	79
#define pfEXTRN	80
#define pfCOMMON	81
#define pfGLOBL	82
#define pfLABEL	83
#define pfINTEGER	84
#define pfSHORT	85
#define pfLONG	86
#define pfSTR	87
#define pfCHAR	88
#define pfID	89
#define pfBYTE	90
#define pfFLOAT	91
#define pfDOUBLE	92
#define pfULDCHR	93
#define pfULD16	94
#define pfUDIV	95
#define pfUMOD	96
#define pfUGT	97
#define pfUGE	98
#define pfULT	99
#define pfULE	100
#define pfJEQ	101
#define pfJNE	102
#define pfJGT	103
#define pfJGE	104
#define pfJLT	105
#define pfJLE	106
#define pfJUGT	107
#define pfJUGE	108
#define pfJULT	109
#define pfJULE	110

#define pfLD64	111
#define pfST64	112
#define pfULD64	113
#define pfLD32	114
#define pfST32	115
#define pfULD32	116

static char *pfNAMES[] = { 0, "comm", "nop", "imm", "add", "sub", "mul", "div",
	"mod", "neg", "incr", "decr", "gt", "ge", "lt", "le", "eq", "ne",
	"and", "or", "xor", "not", "rotl", "rotr", "shtl", "shtru", "shtrs",
	"local", "addr", "locv", "addrv", "loca", "addra", "load", "store",
	"ldchr", "stchr", "ld16", "st16", "enter", "start", "alloc", "leave",
	"trash", "call", "ret", "retn", "branch", "leap", "jmp", "jz", "jnz",
	"copy", "swap", "sp", "push", "pop", "i2d", "f2d", "d2i", "d2f",
	"dadd", "dsub", "dmul", "ddiv", "dcmp", "dneg", "load2", "store2",
	"copy2", "dpush", "dpop", "nil", "begin", "end", "text", "rodata",
	"data", "bss", "align", "extrn", "common", "globl", "label",
	"integer", "short", "long", "str", "char", "id", "byte", "float",
	"double", "uldchr", "uld16", "udiv", "umod", "ugt", "uge", "ult",
	"ule", "jeq", "jne", "jgt", "jge", "jlt", "jle", "jugt", "juge",
	"jult", "jule", "ld64", "st64", "uld64", "ld32", "st32", "uld32",
	0, "asm", "BB", "func", "obj"
};

#define pfASM		118
#define pfBB		119

#define pfR0	0x40
#define pfR1	0x20
#define pfR2	0x10
#define pfRreg	0x0
#define pfRint	0x1
#define pfRstr	0x2
#define pfRdbl	0x3
#define pfRlng	0x4

#elif defined(pfARM)

#define pfCOMM "@ COMM %s\n"
#define pfNOP "@ NOP\n\tnop\n"
#define pfIMM "@ IMM\n\tldr\tr0, =%d\n\tpush\t{r0}\n"
#define pfADD "@ ADD\n\tpop\t{r0,r1}\n\tadd\tr0, r1, r0\n\tpush\t{r0}\n"
#define pfSUB "@ SUB\n\tpop\t{r0,r1}\n\tsub\tr0, r1, r0\n\tpush\t{r0}\n"
#define pfMUL "@ MUL\n\tpop\t{r0,r1}\n\tmul\tr0, r1, r0\n\tpush\t{r0}\n"
#define pfDIV "@ DIV\n\tpop\t{r1}\n\tpop\t{r0}\n\tbl\t_div\n\tpush\t{r0}\n"
#define pfMOD "@ MOD\n\tpop\t{r1}\n\tpop\t{r0}\n\tbl\t_mod\n\tpush\t{r0}\n"
#define pfNEG "@ NEG\n\tpop\t{r0}\n\trsb\tr0, r0, #0\n\tpush\t{r0}\n"
#define pfINCR "@ INCR\n\tpop\t{r0}\n\tldr\tr1, [r0]\n\tldr\tr2, =%d\n\tadd\tr1, r1, r2\n\tstr\tr1, [r0]\n"
#define pfDECR "@ DECR\n\tpop\t{r0}\n\tldr\tr1, [r0]\n\tldr\tr2, =%d\n\tsub\tr1, r1, r2\n\tstr\tr1, [r0]\n"
#define pfGT "@ GT\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tmovgt\tr0, #1\n\tmovle\tr0, #0\n\tpush\t{r0}\n"
#define pfGE "@ GE\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tmovge\tr0, #1\n\tmovlt\tr0, #0\n\tpush\t{r0}\n"
#define pfLT "@ LT\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tmovlt\tr0, #1\n\tmovge\tr0, #0\n\tpush\t{r0}\n"
#define pfLE "@ LE\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tmovle\tr0, #1\n\tmovgt\tr0, #0\n\tpush\t{r0}\n"
#define pfEQ "@ EQ\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tmoveq\tr0, #1\n\tmovne\tr0, #0\n\tpush\t{r0}\n"
#define pfNE "@ NE\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tmovne\tr0, #1\n\tmoveq\tr0, #0\n\tpush\t{r0}\n"
#define pfAND "@ AND\n\tpop\t{r0,r1}\n\tand\tr0, r0, r1\n\tpush\t{r0}\n"
#define pfOR "@ OR\n\tpop\t{r0,r1}\n\torr\tr0, r0, r1\n\tpush\t{r0}\n"
#define pfXOR "@ XOR\n\tpop\t{r0,r1}\n\teor\tr0, r0, r1\n\tpush\t{r0}\n"
#define pfNOT "@ NOT\n\tpop\t{r0}\n\tmvn\tr0, r0\n\tpush\t{r0}\n"
#define pfROTL "@ ROTL\n\tpop\t{r0,r1}\n\trsb\tr0, r0, #32\n\tmov\tr0, r0, ror r1\n\tpush\t{r0}\n"
#define pfROTR "@ ROTR\n\tpop\t{r0,r1}\n\tmov\tr0, r0, ror r1\n\tpush\t{r0}\n"
#define pfSHTL "@ SHTL\n\tpop\t{r0,r1}\n\tmov\tr0, r0, lsl r1\n\tpush\t{r0}\n"
#define pfSHTRU "@ SHTRU\n\tpop\t{r0,r1}\n\tmov\tr0, r0, lsr r1\n\tpush\t{r0}\n"
#define pfSHTRS "@ SHTRS\n\tpop\t{r0,r1}\n\tmov\tr0, r0, asr r1\n\tpush\t{r0}\n"
#define pfLOCAL "@ LOCAL\n\tldr\tr0, =%d\n\tadd\tr0, fp, r0\n\tpush\t{r0}\n"
#define pfADDR "@ ADDR\n\tldr\tr0, =%s\n\tpush\t{r0}\n"
#define pfLOCV "@ LOCV\n\tldr\tr0, =%d\n\tldr\tr0, [fp, r0]\n\tpush\t{r0}\n"
#define pfADDRV "@ ADDRV\n\tldr\tr0, =%s\n\tldr\tr0, [r0]\n\tpush\t{r0}\n"
#define pfLOCA "@ LOCA\n\tpop\t{r1}\n\tldr\tr0, =%d\n\tstr\tr1, [fp, r0]\n"
#define pfADDRA "@ ADDRA\n\tpop\t{r1}\n\tldr\tr0, =%s\n\tstr\tr1, [r0]\n"
#define pfLOAD "@ LOAD\n\tpop\t{r0}\n\tldr\tr0, [r0]\n\tpush\t{r0}\n"
#define pfSTORE "@ STORE\n\tpop\t{r0,r1}\n\tstr\tr1, [r0]\n"
#define pfLDCHR "@ LDCHR\n\tpop\t{r0}\n\tldrsb\tr0, [r0]\n\tpush\t{r0}\n"
#define pfSTCHR "@ STCHR\n\tpop\t{r0,r1}\n\tstrb\tr1, [r0]\n"
#define pfLD16 "@ LD16\n\tpop\t{r0}\n\tldrsh\tr0, [r0]\n\tpush\t{r0}\n"
#define pfST16 "@ ST16\n\tpop\t{r0,r1}\n\tstrh\tr1, [r0]\n"
#define pfENTER "@ ENTER\n\tpush\t{lr}\n\tpush\t{fp}\n\tmov\tfp, sp\n\tldr\tr0, =%d\n\tsub\tsp, sp, r0\n"
#define pfSTART "@ START\n\tpush\t{lr}\n\tpush\t{fp}\n\tmov\tfp, sp\n"
#define pfALLOC "@ ALLOC\n\tpop\t{r0}\n\tsub\tsp, sp, r0\n"
#define pfLEAVE "@ LEAVE\n\tmov\tsp, fp\n\tpop\t{fp}\n"
#define pfTRASH "@ TRASH\n\tldr\tr2, =%d\n\tadd\tsp, sp, r2\n"
#define pfCALL "@ CALL\n\tbl\t%s\n"
#define pfRET "@ RET\n\tpop\t{pc}\n"
#define pfRETN "@ RETN\n\tpop\t{lr}\n\tldr\tr2, =%d\n\tadd\tsp, sp, r2\n\tbx\tlr\n"
#define pfBRANCH "@ BRANCH\n\tmov\trl, pc\n\tpop\t{pc}\n"
#define pfLEAP "@ LEAP\n\tpop\t{pc}\n"
#define pfJMP "@ JMP\n\tb\t%s\n"
#define pfJZ "@ JZ\n\tpop\t{r0}\n\tcmp\tr0, #0\n\tbeq\t%s\n"
#define pfJNZ "@ JNZ\n\tpop\t{r0}\n\tcmp\tr0, #0\n\tbne\t%s\n"
#define pfCOPY "@ COPY\n\tpop\t{r0}\n\tpush\t{r0}\n\tpush\t{r0}\n"
#define pfSWAP "@ SWAP\n\tpop\t{r0,r1}\n\tpush\t{r0}\n\tpush\t{r1}\n"
#define pfSP "@ SP\n\tpush\t{sp}\n"
#define pfPUSH "@ PUSH\n\tpush\t{r0}\n"
#define pfPOP "@ POP\n\tpop\t{r0}\n"
#define pfI2D "@ I2D\n\tpop\t{r0}\n\tbl\t_i2d\n\tpush\t{r0,r1}\n"
#define pfF2D "@ F2D\n\tpop\t{r0}\n\tbl\t_f2d\n\tpush\t{r0,r1}\n"
#define pfD2I "@ D2I\n\tpop\t{r0,r1}\n\tbl\t_d2i\n\tpush\t{r0}\n"
#define pfD2F "@ D2F\n\tpop\t{r0,r1}\n\tbl\t_d2f\n\tpush\t{r0}\n"
#define pfDADD "@ DADD\n\tpop\t{r0,r1,r2,r3}\n\tbl\t_dadd\n\tpush\t{r0,r1}\n"
#define pfDSUB "@ DSUB\n\tpop\t{r0,r1,r2,r3}\n\tbl\t_dsub\n\tpush\t{r0,r1}\n"
#define pfDMUL "@ DMUL\n\tpop\t{r0,r1,r2,r3}\n\tbl\t_dmul\n\tpush\t{r0,r1}\n"
#define pfDDIV "@ DDIV\n\tpop\t{r0,r1,r2,r3}\n\tbl\t_ddiv\n\tpush\t{r0,r1}\n"
#define pfDCMP "@ DCMP\n\tpop\t{r0,r1,r2,r3}\n\tbl\t_dcmp\n\tpush\t{r0}\n"
#define pfDNEG "@ DNEG\n\tpop\t{r0,r1}\n\tbl\t_dneg\n\tpush\t{r0,r1}\n"
#define pfLOAD2 "@ LOAD2\n\tpop\t{r0}\n\tldr\tr1, [r0, #4]\n\tldr\tr0, [r0]\n\tpush\t{r0,r1}\n"
#define pfSTORE2 "@ STORE2\n\tpop\t{r0,r1,r2}\n\tstr\tr1, [r0]\n\tstr\tr2, [r0, #4]\n"
#define pfCOPY2 "@ COPY2\n\tldr\tr0, [sp, #4]\n\tpush\t{r0}\n\tldr\tr0, [sp, #4]\n\tpush\t{r0}\n"
#define pfDPUSH "@ DPUSH\n\tpush\t{r0,r1}\n"
#define pfDPOP "@ DPOP\n\tpop\t{r0,r1}\n"
#define pfNIL "@ NIL\n"
#define pfBEGIN "@ BEGIN\n\t.file \"%s\"\n"
#define pfEND "@ END\n"
#define pfTEXT "@ TEXT\n.section\t.text\n"
#define pfRODATA "@ RODATA\n.section\t.rodata\n"
#define pfDATA "@ DATA\n.section\t.data\n"
#define pfBSS "@ BSS\n.section\t.bss\n"
#define pfALIGN "@ ALIGN\n.align\t4\n"
#define pfEXTRN "@ EXTRN\n.extern\t%s\n"
#define pfCOMMON "@ COMMON\n.comm\t%s,4\n"
#define pfGLOBL "@ GLOBL\n.global\t%s%s\n"
#define pfLABEL "@ LABEL\n%s:\n"
#define pfINTEGER "@ INTEGER\n\t.word\t%d\n"
#define pfSHORT "@ SHORT\n\t.short\t%d\n"
#define pfLONG "@ LONG\n\t.word\t%d\n\t.word\t%d\n"
#define pfSTR "@ STR\n\t.asciz\t\"%s\"\n"
#define pfCHAR "@ CHAR\n\t.byte\t0x%2.2X\n"
#define pfID "@ ID\n\t.word\t%s\n"
#define pfBYTE "@ BYTE\n\t.space\t%d\n"
#define pfFLOAT "@ FLOAT\n\t.float\t0f%g\n"
#define pfDOUBLE "@ DOUBLE\n\t.double\t0d%15.15e\n"
#define pfULDCHR "@ ULDCHR\n\tpop\t{r0}\n\tldrb\tr0, [r0]\n\tpush\t{r0}\n"
#define pfULD16 "@ ULD16\n\tpop\t{r0}\n\tldrh\tr0, [r0]\n\tpush\t{r0}\n"
#define pfUDIV "@ UDIV\n\tpop\t{r1}\n\tpop\t{r0}\n\tbl\t_udiv\n\tpush\t{r0}\n"
#define pfUMOD "@ UMOD\n\tpop\t{r1}\n\tpop\t{r0}\n\tbl\t_umod\n\tpush\t{r0}\n"
#define pfUGT "@ UGT\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tmovls\tr0, #1\n\tmovhi\tr0, #0\n\tpush\t{r0}\n"
#define pfUGE "@ UGE\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tmovcc\tr0, #1\n\tmovcs\tr0, #0\n\tpush\t{r0}\n"
#define pfULT "@ ULT\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tmovcs\tr0, #1\n\tmovcc\tr0, #0\n\tpush\t{r0}\n"
#define pfULE "@ ULE\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tmovhi\tr0, #1\n\tmovls\tr0, #0\n\tpush\t{r0}\n"
#define pfJEQ "@ JEQ\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tbeq\t%s\n"
#define pfJNE "@ JNE\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tbne\t%s\n"
#define pfJGT "@ JGT\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tbgt\t%s\n"
#define pfJGE "@ JGE\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tbge\t%s\n"
#define pfJLT "@ JLT\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tblt\t%s\n"
#define pfJLE "@ JLE\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tble\t%s\n"
#define pfJUGT "@ JUGT\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tbls\t%s\n"
#define pfJUGE "@ JUGE\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tbcc\t%s\n"
#define pfJULT "@ JULT\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tbcs\t%s\n"
#define pfJULE "@ JULE\n\tpop\t{r0,r1}\n\tcmp\tr1, r0\n\tbhi\t%s\n"

#define pfLD64 "@ LD64\n"
#define pfST64 "@ ST64\n"
#define pfULD64 "@ ULD64\n"
#define pfLD32 pfLOAD
#define pfST32 pfSTORE
#define pfULD32 pfLOAD

#define pfASM "@ ASM\n\t%s\n"
#define pfBB "@ BB\n"

#define pfARG1	"; ARG1\n\tldr\tr0, [sp]\n"
#define pfARG2	"; ARG2\n\tldr\tr1, [sp,#4]\n"
#define pfARG3	"; ARG3\n\tldr\tr2, [sp,#8]\n"
#define pfARG4	"; ARG4\n\tldr\tr3, [sp,#12]\n"
#define pfARG1D	"; ARG1D\n\tldr\tr0, [sp]\n\tldr\tr1, [sp,#4]\n"
#define pfARG2D	"; ARG2D\n\tldr\tr0, [sp,#8]\n\tldr\tr1, [sp,#12]\n"

#elif defined(pfAMD64)
#define pfWORD 8

#define pfCOMM "; COMM %s\n"
#define pfNOP "; NOP\n\tnop\n"
#define pfIMM "; IMM\n\tmov\trax, qword %lld\n\tpush\trax\n" /* only MOVs accept 64-bit immediates */
#define pfADD "; ADD\n\tpop\trax\n\tadd\tqword [rsp], rax\n"
#define pfSUB "; SUB\n\tpop\trax\n\tsub\tqword [rsp], rax\n"
#define pfMUL "; MUL\n\tpop\trax\n\timul\tqword rax, [rsp]\n\tmov\t[rsp], rax\n"
#define pfDIV "; DIV\n\tpop\trcx\n\tpop\trax\n\tmov\trdx, rax\n\tsar\trdx, 63\n\tidiv\trcx\n\tpush\trax\n"
#define pfMOD "; MOD\n\tpop\trcx\n\tpop\trax\n\tmov\trdx, rax\n\tsar\trdx, 63\n\tidiv\trcx\n\tpush\trdx\n"
#define pfNEG "; NEG\n\tneg\tqword [rsp]\n"
#define pfINCR "; INCR\n\tpop\trax\n\tadd\tqword [rax], %d\n"
#define pfDECR "; DECR\n\tpop\trax\n\tsub\tqword [rax], %d\n"
#define pfGT "; GT\n\tpop\trax\n\txor\trcx, rcx\n\tcmp\t[rsp], rax\n\tsetg\tcl\n\tmov\t[rsp], rcx\n"
#define pfGE "; GE\n\tpop\trax\n\txor\trcx, rcx\n\tcmp\t[rsp], rax\n\tsetge\tcl\n\tmov\t[rsp], rcx\n"
#define pfLT "; LT\n\tpop\trax\n\txor\trcx, rcx\n\tcmp\t[rsp], rax\n\tsetl\tcl\n\tmov\t[rsp], rcx\n"
#define pfLE "; LE\n\tpop\trax\n\txor\trcx, rcx\n\tcmp\t[rsp], rax\n\tsetle\tcl\n\tmov\t[rsp], rcx\n"
#define pfEQ "; EQ\n\tpop\trax\n\txor\trcx, rcx\n\tcmp\t[rsp], rax\n\tsete\tcl\n\tmov\t[rsp], rcx\n"
#define pfNE "; NE\n\tpop\trax\n\txor\trcx, rcx\n\tcmp\t[rsp], rax\n\tsetne\tcl\n\tmov\t[rsp], rcx\n"
#define pfAND "; AND\n\tpop\trax\n\tand\tqword [rsp], rax\n"
#define pfOR "; OR\n\tpop\trax\n\tor\tqword [rsp], rax\n"
#define pfXOR "; XOR\n\tpop\trax\n\txor\tqword [rsp], rax\n"
#define pfNOT "; NOT\n\tnot\tqword [rsp]\n"
#define pfROTL "; ROTL\n\tpop\trcx\n\trol\tqword [rsp], cl\n"
#define pfROTR "; ROTR\n\tpop\trcx\n\tror\tqword [rsp], cl\n"
#define pfSHTL "; SHTL\n\tpop\trcx\n\tsal\tqword [rsp], cl\n"
#define pfSHTRU "; SHTRU\n\tpop\trcx\n\tshr\tqword [rsp], cl\n"
#define pfSHTRS "; SHTRS\n\tpop\trcx\n\tsar\tqword [rsp], cl\n"
#define pfLOCAL "; LOCAL\n\tlea\trax, [rbp+%d]\n\tpush\trax\n"
#define pfADDR "; ADDR\n\tmov\trax, $%s\n\tpush\trax\n"
#define pfLOCV "; LOCV\n\tpush\tqword [rbp+%d]\n"
#define pfADDRV "; ADDRV\n\tmov\trax, [abs qword $%s]\n\tpush\trax\n"
#define pfLOCA "; LOCA\n\tpop\trax\n\tmov\t[rbp+%d], rax\n"
#define pfADDRA "; ADDRA\n\tpop\trax\n\tmov\t[abs qword $%s], rax\n"
#define pfLOAD "; LOAD\n\tpop\trax\n\tpush\tqword [rax]\n"
#define pfSTORE "; STORE\n\tpop\trcx\n\tpop\trax\n\tmov\t[rcx], rax\n"
#define pfLDCHR "; LDCHR\n\tpop\trcx\n\tmovsx\trax,byte [rcx]\n\tpush\trax\n"
#define pfSTCHR "; STCHR\n\tpop\trcx\n\tpop\trax\n\tmov\t[rcx], al\n"
#define pfLD16 "; LD16\n\tpop\trcx\n\tmovsx\trax,word [rcx]\n\tpush\trax\n"
#define pfST16 "; ST16\n\tpop\trcx\n\tpop\trax\n\tmov\t[rcx], ax\n"
#define pfENTER "; ENTER\n\tpush\trbp\n\tmov\trbp, rsp\n\tsub\trsp, %d\n"
#define pfSTART "; START\n\tpush\trbp\n\tmov\trbp, rsp\n"
#define pfALLOC "; ALLOC\n\tpop\trax\n\tsub\trsp, rax\n"
#define pfLEAVE "; LEAVE\n\tleave\n"
#define pfTRASH "; TRASH\n\tadd\trsp, %d\n"
#define pfCALL "; CALL\n\tcall\t$%s\n"
#define pfRET "; RET\n\tret\n"
#define pfRETN "; RETN\n\tret\t%d\n"
#define pfBRANCH "; BRANCH\n\tpop\trax\n\tcall\trax\n"
#define pfLEAP "; LEAP\n\tpop\trax\n\tjmp\trax\n"
#define pfJMP "; JMP\n\tjmp\t$%s\n"
#define pfJZ "; JZ\n\tpop\trax\n\tcmp\trax, byte 0\n\tje\tnear $%s\n"
#define pfJNZ "; JNZ\n\tpop\trax\n\tcmp\trax, byte 0\n\tjne\tnear $%s\n"
#define pfCOPY "; COPY\n\tpush\tqword [rsp]\n"
#define pfSWAP "; SWAP\n\tpop\trax\n\tpop\trcx\n\tpush\trax\n\tmov\trax, rcx\n\tpush\trax\n"
#define pfSP "; SP\n\tpush\trsp\n"
#define pfPUSH "; PUSH\n\tpush\trax\n"
#define pfPOP "; POP\n\tpop\trax\n"
#define pfI2D "; I2D\n\tfild\tqword [rsp]\n\tsub\trsp, byte 4\n\tfstp\tqword [rsp]\n"
#define pfF2D "; F2D\n\tfld\tqword [rsp]\n\tsub\trsp, byte 4\n\tfstp\tqword [rsp]\n"
#define pfD2I "; D2I\n\tfld\tqword [rsp]\n\tadd\trsp, byte 4\n\tfistp\tqword [rsp]\n"
#define pfD2F "; D2F\n\tfld\tqword [rsp]\n\tadd\trsp, byte 4\n\tfstp\tqword [rsp]\n"
#define pfDADD "; DADD\n\tfld\tqword [rsp]\n\tadd\trsp, byte 8\n\tfld\tqword [rsp]\n\tfaddp\tst1\n\tfstp\tqword [rsp]\n"
#define pfDSUB "; DSUB\n\tfld\tqword [rsp]\n\tadd\trsp, byte 8\n\tfld\tqword [rsp]\n\tfsubrp\tst1\n\tfstp\tqword [rsp]\n"
#define pfDMUL "; DMUL\n\tfld\tqword [rsp]\n\tadd\trsp, byte 8\n\tfld\tqword [rsp]\n\tfmulp\tst1\n\tfstp\tqword [rsp]\n"
#define pfDDIV "; DDIV\n\tfld\tqword [rsp]\n\tadd\trsp, byte 8\n\tfld\tqword [rsp]\n\tfdivrp\tst1\n\tfstp\tqword [rsp]\n"
#define pfDCMP "; DCMP\n\tfld\tqword [rsp+8]\n\tfld\tqword [rsp]\n\tadd\trsp, byte 12\n\tfsubp\tst1\n\tfxtract\n\tffree\tst1\n\tfistp\tqword [rsp]\n"
#define pfDNEG "; DNEG\n\tfld\tqword [rsp]\n\tfchs\n\tfstp\tqword [rsp]\n"
#define pfLOAD2 "; LOAD2\n\tpop\trax\n\tpush\tqword [rax+4]\n\tpush\tqword [rax]\n"
#define pfSTORE2 "; STORE2\n\tpop\trcx\n\tpop\trax\n\tmov\t[rcx], rax\n\tpop\trax\n\tmov\t[rcx+4], rax\n"
#define pfCOPY2 "; COPY2\n\tpush\tqword [rsp+4]\n\tpush\tqword [rsp+4]\n"
#define pfDPUSH "; DPUSH\n\tsub\trsp, byte 8\n\tfstp\tqword [rsp]\n"
#define pfDPOP "; DPOP\n\tfld\tqword [rsp]\n\tadd\trsp, byte 8\n"
#define pfNIL "; NIL\n"
#define pfBEGIN "; BEGIN %s\n"
#define pfEND "; END\n"
#define pfTEXT "; TEXT\nsegment\t.text\n"
#define pfRODATA "; RODATA\nsegment\t.rodata\n"
#define pfDATA "; DATA\nsegment\t.data\n"
#define pfBSS "; BSS\nsegment\t.bss\n"
#define pfALIGN "; ALIGN\nalign\t8\n"
#define pfEXTRN "; EXTRN\nextern\t$%s\n"
#define pfCOMMON "; COMMON\Ncommon\t%d\n"
#define pfGLOBL "; GLOBL\nglobal\t$%s%s\n"
#define pfLABEL "; LABEL\n$%s:\n"
#define pfINTEGER "; INTEGER\n\tdd\t%d\n"
#define pfSHORT "; SHORT\n\tdw\t%d\n"
#define pfLONG "; LONG\n\tdq\t%lld\n"
#define pfSTR "; STR\n\tdb\t'%s', 0\n"
#define pfCHAR "; CHAR\n\tdb\t0x%2.2X\n"
#define pfID "; ID\n\tdq\t$%s\n"
#define pfBYTE "; BYTE\n\tresb\t%d\n"
#define pfFLOAT "; FLOAT\n\tdd\t%e\n"
#define pfDOUBLE "; DOUBLE\n\tdq\t%e\n"
#define pfULDCHR "; ULDCHR\n\tmovzx\trax,byte [rcx]\n"
#define pfULD16 "; ULD16\n\tmovzx\trax,word [rcx]\n"
#define pfUDIV "; UDIV\n\tpop\trcx\n\tpop\trax\n\txor\trdx, rdx\n\tidiv\trcx\n\tpush\trax\n"
#define pfUMOD "; UMOD\n\tpop\trcx\n\tpop\trax\n\txor\trdx, rdx\n\tidiv\trcx\n\tpush\trdx\n"
#define pfUGT "; UGT\n\tpop\trax\n\txor\trcx, rcx\n\tcmp\t[rsp], rax\n\tseta\tcl\n\tmov\t[rsp], rcx\n"
#define pfUGE "; UGE\n\tpop\trax\n\txor\trcx, rcx\n\tcmp\t[rsp], rax\n\tsetae\tcl\n\tmov\t[rsp], rcx\n"
#define pfULT "; ULT\n\tpop\trax\n\txor\trcx, rcx\n\tcmp\t[rsp], rax\n\tsetb\tcl\n\tmov\t[rsp], rcx\n"
#define pfULE "; ULE\n\tpop\trax\n\txor\trcx, rcx\n\tcmp\t[rsp], rax\n\tsetbe\tcl\n\tmov\t[rsp], rcx\n"
#define pfJEQ "; JEQ\n\tpop\trax\n\tpop\trcx\n\tcmp\trcx, rax\n\tje\tnear $%s\n"
#define pfJNE "; JNE\n\tpop\trax\n\tpop\trcx\n\tcmp\trcx, rax\n\tjne\tnear $%s\n"
#define pfJGT "; JGT\n\tpop\trax\n\tpop\trcx\n\tcmp\trcx, rax\n\tjg\tnear $%s\n"
#define pfJGE "; JGE\n\tpop\trax\n\tpop\trcx\n\tcmp\trcx, rax\n\tjge\tnear $%s\n"
#define pfJLT "; JLT\n\tpop\trax\n\tpop\trcx\n\tcmp\trcx, rax\n\tjl\tnear $%s\n"
#define pfJLE "; JLE\n\tpop\trax\n\tpop\trcx\n\tcmp\trcx, rax\n\tjle\tnear $%s\n"
#define pfJUGT "; JUGT\n\tpop\trax\n\tpop\trcx\n\tcmp\trcx, rax\n\tja\tnear $%s\n"
#define pfJUGE "; JUGE\n\tpop\trax\n\tpop\trcx\n\tcmp\trcx, rax\n\tjae\tnear $%s\n"
#define pfJULT "; JULT\n\tpop\trax\n\tpop\trcx\n\tcmp\trcx, rax\n\tjbe\tnear $%s\n"
#define pfJULE "; JULE\n\tpop\trax\n\tpop\trcx\n\tcmp\trcx, rax\n\tjb\tnear $%s\n"

#define pfLD32 "; LD32\n\tpop\trcx\n\tmovsx\trax,dword [rcx]\n\tpush\trax\n" /* sign extend */
#define pfST32 "; ST32\n\tpop\trcx\n\tpop\trax\n\tmov\t[rcx], eax\n" /* truncate: does not save sign if number overflows 31-bits */
#define pfULD32 "; ULD32\n\tmovzx\trax, dword [rcx]\n" /* zero extend */
#define pfLD64 pfLOAD
#define pfST64 pfSTORE
#define pfULD64 pfLOAD

#define pfASM "; ASM\n\t%s\n"
#define pfBB "; BB\n"

#define pfARG1	"; ARG1\n\tmov\trdi, [rsp+0]\n"
#define pfARG2	"; ARG2\n\tmov\trsi, [rsp+8]\n"
#define pfARG3	"; ARG3\n\tmov\trdx, [rsp+16]\n"
#define pfARG4	"; ARG4\n\tmov\tr10, [rsp+24]\n"
#define pfARG5	"; ARG5\n\tmov\tr8,  [rsp+32]\n"
#define pfARG6	"; ARG6\n\tmov\tr9,  [rsp+40]\n"
#define pfARG1D	"; ARG1D\n\tmov\txmm0, [rsp+0]\n"
#define pfARG2D	"; ARG2D\n\tmov\txmm1, [rsp+8]\n"
#define pfARG3D	"; ARG3D\n\tmov\txmm2, [rsp+16]\n"
#define pfARG4D	"; ARG4D\n\tmov\txmm3, [rsp+24]\n"
#define pfARG5D	"; ARG5D\n\tmov\txmm4, [rsp+32]\n"
#define pfARG6D	"; ARG6D\n\tmov\txmm5, [rsp+40]\n"

#elif defined(pfI386GAS)

#define pfCOMM "# COMM %s\n"
#define pfNOP "# NOP\n\tnop\n"
#define pfIMM "# IMM\n\tpushl\t$%d\n"
#define pfADD "# ADD\n\tpopl\t%%eax\n\taddl\t%%eax, (%%esp)\n"
#define pfSUB "# SUB\n\tpopl\t%%eax\n\tsubl\t%%eax, (%%esp)\n"
#define pfMUL "# MUL\n\tpopl\t%%eax\n\timull\t(%%esp), %%eax\n\tmovl\t%%eax, (%%esp)\n"
#define pfDIV "# DIV\n\tpopl\t%%ecx\n\tpopl\t%%eax\n\tcltd\n\tidivl\t%%ecx\n\tpushl\t%%eax\n"
#define pfMOD "# MOD\n\tpopl\t%%ecx\n\tpopl\t%%eax\n\tcltd\n\tidivl\t%%ecx\n\tpushl\t%%edx\n"
#define pfNEG "# NEG\n\tnegl\t(%%esp)\n"
#define pfINCR "# INCR\n\tpopl\t%%eax\n\taddl\t$%d, (%%eax)\n"
#define pfDECR "# DECR\n\tpopl\t%%eax\n\tsubl\t$%d (%%eax)\n"
#define pfGT "# GT\n\tpopl\t%%eax\n\txorl\t%%ecx, %%ecx\n\tcmp\t%%eax, (%%esp)\n\tsetg\t%%cl\n\tmovl\t%%ecx, (%%esp)\n"
#define pfGE "# GE\n\tpopl\t%%eax\n\txorl\t%%ecx, %%ecx\n\tcmp\t%%eax, (%%esp)\n\tsetge\t%%cl\n\tmovl\t%%ecx, (%%esp)\n"
#define pfLT "# LT\n\tpopl\t%%eax\n\txorl\t%%ecx, %%ecx\n\tcmp\t%%eax, (%%esp)\n\tsetl\t%%cl\n\tmovl\t%%ecx, (%%esp)\n"
#define pfLE "# LE\n\tpopl\t%%eax\n\txorl\t%%ecx, %%ecx\n\tcmp\t%%eax, (%%esp)\n\tsetle\t%%cl\n\tmovl\t%%ecx, (%%esp)\n"
#define pfEQ "# EQ\n\tpopl\t%%eax\n\txorl\t%%ecx, %%ecx\n\tcmp\t%%eax, (%%esp)\n\tsete\t%%cl\n\tmovl\t%%ecx, (%%esp)\n"
#define pfNE "# NE\n\tpopl\t%%eax\n\txorl\t%%ecx, %%ecx\n\tcmp\t%%eax, (%%esp)\n\tsetne\t%%cl\n\tmovl\t%%ecx, (%%esp)\n"
#define pfAND "# AND\n\tpopl\t%%eax\n\tandl\t%%eax, (%%esp)\n"
#define pfOR "# OR\n\tpopl\t%%eax\n\torl\t%%eax, (%%esp)\n"
#define pfXOR "# XOR\n\tpopl\t%%eax\n\txorl\t%%eax, (%%esp)\n"
#define pfNOT "# NOT\n\tnotl\t(%%esp)\n"
#define pfROTL "# ROTL\n\tpopl\t%%ecx\n\troll\t%%cl, (%%esp)\n"
#define pfROTR "# ROTR\n\tpopl\t%%ecx\n\trorl\t%%cl, (%%esp)\n"
#define pfSHTL "# SHTL\n\tpopl\t%%ecx\n\tsall\t%%cl, (%%esp)\n"
#define pfSHTRU "# SHTRU\n\tpopl\t%%ecx\n\tshrl\t%%cl, (%%esp)\n"
#define pfSHTRS "# SHTRS\n\tpopl\t%%ecx\n\tsarl\t%%cl, (%%esp)\n"
#define pfLOCAL "# LOCAL\n\tleal\t(%%ebp+$%d), %%eax\n\tpushl\t%%eax\n"
#define pfADDR "# ADDR\n\tpushl\t$%s\n"
#define pfLOCV "# LOCV\n\tpushl\t$%d(%%ebp)\n"
#define pfADDRV "# ADDRV\n\tpushl\t(%s)\n"
#define pfLOCA "# LOCA\n\tpopl\t%%eax\n\tmovl\t%%eax, $%d(%%ebp)\n"
#define pfADDRA "# ADDRA\n\tpopl\t%%eax\n\tmovl\t%%eax, (%s)\n"
#define pfLOAD "# LOAD\n\tpopl\t%%eax\n\tpushl\t(%%eax)\n"
#define pfSTORE "# STORE\n\tpopl\t%%ecx\n\tpopl\t%%eax\n\tmovl\t%%eax, (%%ecx)\n"

#define pfLDCHR "# LDCHR\n\tpopl\t%%ecx\n\tmovsbl\t(%%ecx), %%eax\n\tpushl\t%%eax\n"
#define pfSTCHR "# STCHR\n\tpopl\t%%ecx\n\tpopl\t%%eax\n\tmovb\t%%al, (%%ecx)\n"
#define pfLD16 "# LD16\n\tpopl\t%%ecx\n\tmovsbw\t(%%ecx), %eax\n\tpushl\t%%eax\n"
#define pfST16 "# ST16\n\tpopl\t%%ecx\n\tpopl\t%%eax\n\tmovw\t%%ax, (%%ecx)\n"
#define pfENTER "# ENTER\n\tpushl\t%%ebp\n\tmovl\t%%esp, %%ebp\n\tsubl\t$%d, %%esp\n"
#define pfSTART "# START\n\tpushl\t%%ebp\n\tmovl\t%%esp, %%ebp\n"
#define pfALLOC "# ALLOC\n\tpopl\t%%eax\n\tsubl\t%%eax, %%esp\n"
#define pfLEAVE "# LEAVE\n\tleave\n"
#define pfTRASH "# TRASH\n\tadd\t$%d, %%esp\n"
#define pfCALL "# CALL\n\tcall\t%s\n"
#define pfRET "# RET\n\tret\n"
#define pfRETN "# RETN\n\tret\t$%d\n"
#define pfBRANCH "# BRANCH\n\tpopl\t%%eax\n\tcall\t%%eax\n"
#define pfLEAP "# LEAP\n\tpopl\t%%eax\n\tjmp\t%%eax\n"
#define pfJMP "# JMP\n\tjmp\t%s\n"
#define pfJZ "# JZ\n\tpopl\t%%eax\n\tcmpl\t$0, %%eax\n\tje\t%s\n"
#define pfJNZ "# JNZ\n\tpopl\t%%eax\n\tcmpl\t$0, %%eax\n\tjne\t%s\n"
#define pfCOPY "# COPY\n\tpushl\t(%%esp)\n"
#define pfSWAP "# SWAP\n\tpopl\t%%eax\n\tpopl\t%%ecx\n\tpushl\t%%eax\n\tpushl\t%%ecx\n"
#define pfSP "# SP\n\tpushl\t%%esp\n"
#define pfPUSH "# PUSH\n\tpushl\t%%eax\n"
#define pfPOP "# POP\n\tpopl\t%%eax\n"
#define pfI2D "# I2D\n\tfildl\t(%%esp)\n\tsubl\t$4, %%esp\n\tfstpl\t(%%esp)\n"
#define pfF2D "# F2D\n\tflds\t(%%esp)\n\tsubl\t$4, %%esp\n\tfstpl\t(%%esp)\n"
#define pfD2I "# D2I\n\tfldl\t(%%esp)\n\taddl\t$4, %%esp\n\tfistpl\t(%%esp)\n"
#define pfD2F "# D2F\n\tfldl\t(%%esp)\n\taddl\t$4, %%esp\n\tfstps\t(%%esp)\n"
#define pfDADD "# DADD\n\tfldl\t(%%esp)\n\taddl\t$8, %%esp\n\tfldl\t(%%esp)\n\tfaddp\t%%st(1)\n\tfstpl\t(%%esp)\n"
#define pfDSUB "# DSUB\n\tfldl\t(%%esp)\n\taddl\t$8, %%esp\n\tfldl\t(%%esp)\n\tfsubp\t%%st(1)\n\tfstpl\t(%%esp)\n"
#define pfDMUL "# DMUL\n\tfldl\t(%%esp)\n\taddl\t$8, %%esp\n\tfldl\t(%%esp)\n\tfmulp\t%%st(1)\n\tfstpl\t(%%esp)\n"
#define pfDDIV "# DDIV\n\tfldl\t(%%esp)\n\taddl\t$8, %%esp\n\tfldl\t(%%esp)\n\tfdivp\t%%st(1)\n\tfstpl\t(%%esp)\n"
#define pfDCMP "# DCMP\n\tfldl\t8(%%esp)\n\tfldl\t(%%esp)\n\taddl\t$12, %%esp\n\tfsubp\t%%st(1)\n\tfxtract\n\tffree\t%%st(1)\n\tfistpl\t(%%esp)\n"
#define pfDNEG "# DNEG\n\tfldl\t(%%esp)\n\tfchs\n\tfstpl\t(%%esp)\n"
#define pfLOAD2 "# LOAD2\n\tpopl\t%%eax\n\tpushl\t4(%%eax)\n\tpushl\t(%%eax)\n"
#define pfSTORE2 "# STORE2\n\tpopl\t%%ecx\n\tpopl\t%%eax\n\tmovl\t%%eax, (%%ecx)\n\tpopl\t%%eax\n\tmovl\t%%eax, 4(%%ecx)\n"
#define pfCOPY2 "# COPY2\n\tpushl\t4(%%esp)\n\tpushl\t4(%%esp)\n"
#define pfDPUSH "# DPUSH\n\tsubl\t$8, %%esp\n\tfstpl\t(%%esp)\n"
#define pfDPOP "# DPOP\n\tfldl\t(%%esp)\n\taddl\t$8, %%esp\n"
#define pfNIL "# NIL\n"
#define pfBEGIN "# BEGIN %s\n"
#define pfEND "# END\n"
#define pfTEXT "# TEXT\n.section\t.text\n"
#define pfRODATA "# RODATA\n.section\t.rodata\n"
#define pfDATA "# DATA\n.section\t.data\n"
#define pfBSS "# BSS\n.section\t.bss\n"
#define pfALIGN "# ALIGN\n.align\t4\n"
#define pfEXTRN "# EXTRN\n.extern\t%s\n"
#define pfCOMMON "# COMMON\N.common\t$%d\n"
#define pfGLOBL "# GLOBL\n.globl\t%s\t# %s\n"
#define pfLABEL "# LABEL\n%s:\n"
#define pfINTEGER "# INTEGER\n\t.int\t%d\n"
#define pfSHORT "# SHORT\n\t.short\t%d\n"
#define pfLONG "# LONG\n\t.quad\t%lld\n" /* %Ld %lld %llu %ql %I64 ? */
#define pfSTR "# STR\n\t.asciz\t\"%s\"\n"
#define pfCHAR "# CHAR\n\t.byte\t0x%2.2X\n"
#define pfID "# ID\n\t.int\t%s\n"
#define pfBYTE "# BYTE\n\t.space\t%d\n"
#define pfFLOAT "# FLOAT\n\t.float\t%e\n"
#define pfDOUBLE "# DOUBLE\n\t.double\t%e\n"
#define pfULDCHR "# ULDCHR\n\tmovzxb\t%%eax, (%%ecx)\n"
#define pfULD16 "# ULD16\n\tmovzxw\t%%eax, (%%ecx)\n"
#define pfUDIV "# UDIV\n\tpopl\t%%ecx\n\tpopl\t%%eax\n\txor\t%%edx, %%edx\n\tidiv\t%%ecx\n\tpushl\t%%eax\n"
#define pfUMOD "# UMOD\n\tpopl\t%%ecx\n\tpopl\t%%eax\n\txor\t%%edx, %%edx\n\tidiv\t%%ecx\n\tpushl\t%%edx\n"
#define pfUGT "# UGT\n\tpopl\t%%eax\n\txorl\t%%ecx, %%ecx\n\tcmpl\t%%eax, (%%esp)\n\tseta\t%%cl\n\tmovl\t%%ecx, (%%esp)\n"
#define pfUGE "# UGE\n\tpopl\t%%eax\n\txorl\t%%ecx, %%ecx\n\tcmpl\t%%eax, (%%esp)\n\tsetae\t%%cl\n\tmovl\t%%ecx, (%%esp)\n"
#define pfULT "# ULT\n\tpopl\t%%eax\n\txorl\t%%ecx, %%ecx\n\tcmpl\t%%eax, (%%esp)\n\tsetb\t%%cl\n\tmovl\t%%ecx, (%%esp)\n"
#define pfULE "# ULE\n\tpopl\t%%eax\n\txorl\t%%ecx, %%ecx\n\tcmpl\t%%eax, (%%esp)\n\tsetbe\t%%cl\n\tmovl\t%%ecx, (%%esp)\n"
#define pfJEQ "# JEQ\n\tpopl\t%%eax\n\tpopl\t%%ecx\n\tcmpl\t%%ecx, %%eax\n\tje %s\n"
#define pfJNE "# JNE\n\tpopl\t%%eax\n\tpopl\t%%ecx\n\tcmpl\t%%ecx, %%eax\n\tjne %s\n"
#define pfJGT "# JGT\n\tpopl\t%%eax\n\tpopl\t%%ecx\n\tcmpl\t%%ecx, %%eax\n\tjg %s\n"
#define pfJGE "# JGE\n\tpopl\t%%eax\n\tpopl\t%%ecx\n\tcmpl\t%%ecx, %%eax\n\tjge %s\n"
#define pfJLT "# JLT\n\tpopl\t%%eax\n\tpopl\t%%ecx\n\tcmpl\t%%ecx, %%eax\n\tjl %s\n"
#define pfJLE "# JLE\n\tpopl\t%%eax\n\tpopl\t%%ecx\n\tcmpl\t%%ecx, %%eax\n\tjle %s\n"
#define pfJUGT "# JUGT\n\tpopl\t%%eax\n\tpopl\t%%ecx\n\tcmpl\t%%ecx, %%eax\n\tja %s\n"
#define pfJUGE "# JUGE\n\tpopl\t%%eax\n\tpopl\t%%ecx\n\tcmpl\t%%ecx, %%eax\n\tjae %s\n"
#define pfJULT "# JULT\n\tpopl\t%%eax\n\tpopl\t%%ecx\n\tcmpl\t%%ecx, %%eax\n\tjbe %s\n"
#define pfJULE "# JULE\n\tpopl\t%%eax\n\tpopl\t%%ecx\n\tcmpl\t%%ecx, %%eax\n\tjb %s\n"

#define pfLD64 pfLOAD /* who cares if useful data is truncated! */
#define pfST64 "# ST64\n\tpopl\t%%ecx\n\tpopl\t%%eax\n\tmov\t(%%ecx), %%eax\n\tand %%eax, 0x80000000\n\tmov %%eax, 0\n\tmov %%edx, -1\n\tcmovnz %%eax, %%edx\n\tmov (%%ecx+4), %%eax\n" /* copy 32bit-sign to upper 32bits */
#define pfULD64 pfLOAD /* who cares if useful data is truncated! */
#define pfLD32 pfLOAD
#define pfST32 pfSTORE
#define pfULD32 pfLOAD

#define pfASM "; ASM\n\t%s\n"
#define pfBB "; BB\n"

#else

#define pfCOMM "; COMM %s\n"
#define pfNOP "; NOP\n\tnop\n"
#define pfIMM "; IMM\n\tpush\tdword %d\n"
#define pfADD "; ADD\n\tpop\teax\n\tadd\tdword [esp], eax\n"
#define pfSUB "; SUB\n\tpop\teax\n\tsub\tdword [esp], eax\n"
#define pfMUL "; MUL\n\tpop\teax\n\timul\tdword eax, [esp]\n\tmov\t[esp], eax\n"
#define pfDIV "; DIV\n\tpop\tecx\n\tpop\teax\n\tcdq\n\tidiv\tecx\n\tpush\teax\n"
#define pfMOD "; MOD\n\tpop\tecx\n\tpop\teax\n\tcdq\n\tidiv\tecx\n\tpush\tedx\n"
#define pfNEG "; NEG\n\tneg\tdword [esp]\n"
#define pfINCR "; INCR\n\tpop\teax\n\tadd\tdword [eax], %d\n"
#define pfDECR "; DECR\n\tpop\teax\n\tsub\tdword [eax], %d\n"
#define pfGT "; GT\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetg\tcl\n\tmov\t[esp], ecx\n"
#define pfGE "; GE\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetge\tcl\n\tmov\t[esp], ecx\n"
#define pfLT "; LT\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetl\tcl\n\tmov\t[esp], ecx\n"
#define pfLE "; LE\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetle\tcl\n\tmov\t[esp], ecx\n"
#define pfEQ "; EQ\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsete\tcl\n\tmov\t[esp], ecx\n"
#define pfNE "; NE\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetne\tcl\n\tmov\t[esp], ecx\n"
#define pfAND "; AND\n\tpop\teax\n\tand\tdword [esp], eax\n"
#define pfOR "; OR\n\tpop\teax\n\tor\tdword [esp], eax\n"
#define pfXOR "; XOR\n\tpop\teax\n\txor\tdword [esp], eax\n"
#define pfNOT "; NOT\n\tnot\tdword [esp]\n"
#define pfROTL "; ROTL\n\tpop\tecx\n\trol\tdword [esp], cl\n"
#define pfROTR "; ROTR\n\tpop\tecx\n\tror\tdword [esp], cl\n"
#define pfSHTL "; SHTL\n\tpop\tecx\n\tsal\tdword [esp], cl\n"
#define pfSHTRU "; SHTRU\n\tpop\tecx\n\tshr\tdword [esp], cl\n"
#define pfSHTRS "; SHTRS\n\tpop\tecx\n\tsar\tdword [esp], cl\n"
#define pfLOCAL "; LOCAL\n\tlea\teax, [ebp+%d]\n\tpush\teax\n"
#define pfADDR "; ADDR\n\tpush\tdword $%s\n"
#define pfLOCV "; LOCV\n\tpush\tdword [ebp+%d]\n"
#define pfADDRV "; ADDRV\n\tpush\tdword [$%s]\n"
#define pfLOCA "; LOCA\n\tpop\teax\n\tmov\t[ebp+%d], eax\n"
#define pfADDRA "; ADDRA\n\tpop\teax\n\tmov\t[$%s], eax\n"
#define pfLOAD "; LOAD\n\tpop\teax\n\tpush\tdword [eax]\n"
#define pfSTORE "; STORE\n\tpop\tecx\n\tpop\teax\n\tmov\t[ecx], eax\n"
#define pfLDCHR "; LDCHR\n\tpop\tecx\n\tmovsx\teax,byte [ecx]\n\tpush\teax\n"
#define pfSTCHR "; STCHR\n\tpop\tecx\n\tpop\teax\n\tmov\t[ecx], al\n"
#define pfLD16 "; LD16\n\tpop\tecx\n\tmovsx\teax,word [ecx]\n\tpush\teax\n"
#define pfST16 "; ST16\n\tpop\tecx\n\tpop\teax\n\tmov\t[ecx], ax\n"
#define pfENTER "; ENTER\n\tpush\tebp\n\tmov\tebp, esp\n\tsub\tesp, %d\n"
#define pfSTART "; START\n\tpush\tebp\n\tmov\tebp, esp\n"
#define pfALLOC "; ALLOC\n\tpop\teax\n\tsub\tesp, eax\n"
#define pfLEAVE "; LEAVE\n\tleave\n"
#define pfTRASH "; TRASH\n\tadd\tesp, %d\n"
#define pfCALL "; CALL\n\tcall\t$%s\n"
#define pfRET "; RET\n\tret\n"
#define pfRETN "; RETN\n\tret\t%d\n"
#define pfBRANCH "; BRANCH\n\tpop\teax\n\tcall\teax\n"
#define pfLEAP "; LEAP\n\tpop\teax\n\tjmp\teax\n"
#define pfJMP "; JMP\n\tjmp\tdword $%s\n"
#define pfJZ "; JZ\n\tpop\teax\n\tcmp\teax, byte 0\n\tje\tnear $%s\n"
#define pfJNZ "; JNZ\n\tpop\teax\n\tcmp\teax, byte 0\n\tjne\tnear $%s\n"
#define pfCOPY "; COPY\n\tpush\tdword [esp]\n"
#define pfSWAP "; SWAP\n\tpop\teax\n\tpop\tecx\n\tpush\teax\n\tmov\teax, ecx\n\tpush\teax\n"
#define pfSP "; SP\n\tpush\tesp\n"
#define pfPUSH "; PUSH\n\tpush\teax\n"
#define pfPOP "; POP\n\tpop\teax\n"
#define pfI2D "; I2D\n\tfild\tdword [esp]\n\tsub\tesp, byte 4\n\tfstp\tqword [esp]\n"
#define pfF2D "; F2D\n\tfld\tdword [esp]\n\tsub\tesp, byte 4\n\tfstp\tqword [esp]\n"
#define pfD2I "; D2I\n\tfld\tqword [esp]\n\tadd\tesp, byte 4\n\tfistp\tdword [esp]\n"
#define pfD2F "; D2F\n\tfld\tqword [esp]\n\tadd\tesp, byte 4\n\tfstp\tdword [esp]\n"
#define pfDADD "; DADD\n\tfld\tqword [esp]\n\tadd\tesp, byte 8\n\tfld\tqword [esp]\n\tfaddp\tst1\n\tfstp\tqword [esp]\n"
#define pfDSUB "; DSUB\n\tfld\tqword [esp]\n\tadd\tesp, byte 8\n\tfld\tqword [esp]\n\tfsubrp\tst1\n\tfstp\tqword [esp]\n"
#define pfDMUL "; DMUL\n\tfld\tqword [esp]\n\tadd\tesp, byte 8\n\tfld\tqword [esp]\n\tfmulp\tst1\n\tfstp\tqword [esp]\n"
#define pfDDIV "; DDIV\n\tfld\tqword [esp]\n\tadd\tesp, byte 8\n\tfld\tqword [esp]\n\tfdivrp\tst1\n\tfstp\tqword [esp]\n"
#define pfDCMP "; DCMP\n\tfld\tqword [esp+8]\n\tfld\tqword [esp]\n\tadd\tesp, byte 12\n\tfsubp\tst1\n\tfxtract\n\tffree\tst1\n\tfistp\tdword [esp]\n"
#define pfDNEG "; DNEG\n\tfld\tqword [esp]\n\tfchs\n\tfstp\tqword [esp]\n"
#define pfLOAD2 "; LOAD2\n\tpop\teax\n\tpush\tdword [eax+4]\n\tpush\tdword [eax]\n"
#define pfSTORE2 "; STORE2\n\tpop\tecx\n\tpop\teax\n\tmov\t[ecx], eax\n\tpop\teax\n\tmov\t[ecx+4], eax\n"
#define pfCOPY2 "; COPY2\n\tpush\tdword [esp+4]\n\tpush\tdword [esp+4]\n"
#define pfDPUSH "; DPUSH\n\tsub\tesp, byte 8\n\tfstp\tqword [esp]\n"
#define pfDPOP "; DPOP\n\tfld\tqword [esp]\n\tadd\tesp, byte 8\n"
#define pfNIL "; NIL\n"
#define pfBEGIN "; BEGIN %s\n"
#define pfEND "; END\n"
#define pfTEXT "; TEXT\nsegment\t.text\n"
#define pfRODATA "; RODATA\nsegment\t.rodata\n"
#define pfDATA "; DATA\nsegment\t.data\n"
#define pfBSS "; BSS\nsegment\t.bss\n"
#define pfALIGN "; ALIGN\nalign\t4\n"
#define pfEXTRN "; EXTRN\nextern\t$%s\n"
#define pfCOMMON "; COMMON\Ncommon\t%d\n"
#define pfGLOBL "; GLOBL\nglobal\t$%s%s\n"
#define pfLABEL "; LABEL\n$%s:\n"
#define pfINTEGER "; INTEGER\n\tdd\t%d\n"
#define pfSHORT "; SHORT\n\tdw\t%d\n"
#define pfLONG "; LONG\n\tdq\t%lld\n"
#define pfSTR "; STR\n\tdb\t'%s', 0\n"
#define pfCHAR "; CHAR\n\tdb\t0x%2.2X\n"
#define pfID "; ID\n\tdd\t$%s\n"
#define pfBYTE "; BYTE\n\tresb\t%d\n"
#define pfFLOAT "; FLOAT\n\tdd\t%e\n"
#define pfDOUBLE "; DOUBLE\n\tdq\t%e\n"
#define pfULDCHR "; ULDCHR\n\tmovzx\teax,byte [ecx]\n"
#define pfULD16 "; ULD16\n\tmovzx\teax,word [ecx]\n"
#define pfUDIV "; UDIV\n\tpop\tecx\n\tpop\teax\n\txor\tedx, edx\n\tidiv\tecx\n\tpush\teax\n"
#define pfUMOD "; UMOD\n\tpop\tecx\n\tpop\teax\n\txor\tedx, edx\n\tidiv\tecx\n\tpush\tedx\n"
#define pfUGT "; UGT\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tseta\tcl\n\tmov\t[esp], ecx\n"
#define pfUGE "; UGE\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetae\tcl\n\tmov\t[esp], ecx\n"
#define pfULT "; ULT\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetb\tcl\n\tmov\t[esp], ecx\n"
#define pfULE "; ULE\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetbe\tcl\n\tmov\t[esp], ecx\n"
#define pfJEQ "; JEQ\n\tpop\teax\n\tpop\tecx\n\tcmp\tecx, eax\n\tje\tnear $%s\n"
#define pfJNE "; JNE\n\tpop\teax\n\tpop\tecx\n\tcmp\tecx, eax\n\tjne\tnear $%s\n"
#define pfJGT "; JGT\n\tpop\teax\n\tpop\tecx\n\tcmp\tecx, eax\n\tjg\tnear $%s\n"
#define pfJGE "; JGE\n\tpop\teax\n\tpop\tecx\n\tcmp\tecx, eax\n\tjge\tnear $%s\n"
#define pfJLT "; JLT\n\tpop\teax\n\tpop\tecx\n\tcmp\tecx, eax\n\tjl\tnear $%s\n"
#define pfJLE "; JLE\n\tpop\teax\n\tpop\tecx\n\tcmp\tecx, eax\n\tjle\tnear $%s\n"
#define pfJUGT "; JUGT\n\tpop\teax\n\tpop\tecx\n\tcmp\tecx, eax\n\tja\tnear $%s\n"
#define pfJUGE "; JUGE\n\tpop\teax\n\tpop\tecx\n\tcmp\tecx, eax\n\tjae\tnear $%s\n"
#define pfJULT "; JULT\n\tpop\teax\n\tpop\tecx\n\tcmp\tecx, eax\n\tjbe\tnear $%s\n"
#define pfJULE "; JULE\n\tpop\teax\n\tpop\tecx\n\tcmp\tecx, eax\n\tjb\tnear $%s\n"

#define pfLD64 pfLOAD /* who cares if useful data is truncated! */
#define pfST64 "; ST64\n\tpop\tecx\n\tpop\teax\n\tmov\t[ecx], eax\n\tand\teax, 0x80000000\n\tmov\teax, 0\n\tmov\tedx, -1\n\tcmovnz\teax, edx\n\tmov\t[ecx+4], eax\n" /* copy 32bit-sign to upper 32bits */
#define pfULD64 pfLOAD /* who cares if useful data is truncated! */
#define pfLD32 pfLOAD
#define pfST32 pfSTORE
#define pfULD32 pfLOAD

#define pfASM "; ASM\n\t%s\n"
#define pfBB "; BB\n"

#endif

/* Used as the 2nd argument of pfGLOBL */
#define pfNONE	""	/* unknown global label type */
#ifdef _WIN32
#define pfFUNC	""	/* no symbol types in win32-PE */
#define pfOBJ	""	/* no symbol types in win32-PE */
#elif defined(pfNUM)
#define pfFUNC	120
#define pfOBJ	121
#elif defined(pfARM)
#define pfFUNC	" @function"	/* should declare in .type */
#define pfOBJ	""
#else
#define pfFUNC	":function"	/* global label is a function */
#define pfOBJ	":object"	/* global label is data */
#endif

#ifndef pfARG1
#define pfARG1 ""
#endif
#ifndef pfARG2
#define pfARG2 ""
#endif
#ifndef pfARG3
#define pfARG3 ""
#endif
#ifndef pfARG4
#define pfARG4 ""
#endif
#ifndef pfARG5
#define pfARG5 ""
#endif
#ifndef pfARG6
#define pfARG6 ""
#endif
#ifndef pfARG1D
#define pfARG1D ""
#endif
#ifndef pfARG2D
#define pfARG2D ""
#endif
#ifndef pfARG3D
#define pfARG3D ""
#endif
#ifndef pfARG4D
#define pfARG4D ""
#endif
#ifndef pfARG5D
#define pfARG5D ""
#endif
#ifndef pfARG6D
#define pfARG6D ""
#endif

#ifndef pfWORD
#define pfWORD 4
#endif

#endif /* _postfix_h_ */
