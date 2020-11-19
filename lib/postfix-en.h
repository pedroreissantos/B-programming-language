<!-- $Id: postfix.html,v 1.4 2004/12/09 17:24:33 prs Exp $ -->
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 3.2 Final//EN">

<HTML>
<HEAD><TITLE>Postfix code generation</TITLE>
<META NAME="description" CONTENT="postfix">
<META NAME="keywords" CONTENT="postfix">
<META NAME="resource-type" CONTENT="document">
<META NAME="distribution" CONTENT="global">

<META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=iso-8859-1">

</HEAD>
<BODY BGCOLOR="B5BDD6" link=red vlink=green>
<table border="0" width="100%" cellpadding="5" cellspacing="3">
  <tr align="left" valign="middle"><td>
  <IMG ALIGN=left SRC="istlogo.gif" ALT="IST"> </td>

  <TD> <CENTER> <H1><I><U>Postfix</U></I> code generation</H1>
  <H2>November 18, 2020</H2>
  <H3>Departament of Computer Science and Engineering</H3>
  <H3>Instituto Superior T&eacute;cnico</H3>
  <H3>University of Lisbon</H3>
	<BR> <BR>

</CENTER> </TD> </TABLE> <HR size=2 noshade> <BR>

<BR>
<BR>
<BR>
<BR>
<BR>

<P>

<H1><A NAME="SECTION1"> 1 - Introduction</A> </H1>

<P>
This document describes the code generation for a stack machine using a
predefined set of macros defined in <A HREF="postfix.h">postfix.h</A>).
<P>
The code generation assumes an stack machine architecture (SL0) with three
registers:
<UL>
	<LI><B>IP (instruction pointer)</B>: pointer to the next instruction.
	<LI><B>SP (stack pointer)</B>: pointer to the top of the stack.
  <LI><B>FP (frame pointer)</B>: pointer to the activation record of the rotine being executed, within the stack.
</UL>

<H1><A NAME="SECTION1">2 - Interface</A> </H1>

<P>
Each instruction of the stack machine architecture (SL0) is converted to
a set of real processor instrutions. At the moment the <i>intel</i> <B>i386</B>
processor, the <i>AMD</i> <b>x64</b> processor and the <i>ARM</i> <b>32-bits</b>
processor are supported, as well as <i>debug</i> and <i>bytecode</i>
pseudo-architectures. Other architectures require the mapping of each
<b>postifx</b> instruction into the given processor specific instructuions.
<P>
The <b>python</b> version of <b>postfix</b> uses a dictionary to convert
macro operations into machine code strings.
Each instruction must be printed using a <B>print</B>, or equivalent function,
supplying the required arguments for each case.
<P>
For instance, the sum <B>ADD</B> assumes two values on the top of the
stack. The macro produces processor instructions that remove these values
and pushes back the sum result.
In order to execute the sum, no argument are needed and, only a 
<TT>print(arm['ADD']);</TT> is required for the <i>ARM</i> assembler.
For a dynamic selection of target machine code dictionary, another dictionary
<TT>pf</TT> can be used. For instance <TT>arm = pf['arm']</TT>, while other
architectures include <tt>i386</tt> (<b>intel</b> assembler format),
<tt>i386gas</tt> (<b>AT&amp;T</b> assembler format),
<tt>amd64</tt> (<b>intel</b> assembler format),
<tt>x64</tt> (<b>AT&amp;T</b> assembler format).
<P>
To push an integer value to the stack, a value must be provided:
<TT>print(arm['IMM'] % value)</TT>.
The <B>IMM</B> macro includes a <B>%d</B> in the string that is replaced
by the provided value.
<P>
All the operations provided by <b>postfix</b> are described by the table below.
Each operation is described by its arguments (<B>%d</B> ans <B>%s</B> in the
string macro) and the stack effect (the poped values required and the pushed
resut).

<H1><A NAME="SECTION1">3 - Postfix operations</A></H1>


<TABLE border>
<TH>opcode		<TH>int<TH>char*<TH>effect<TH>description<TH><TD>
<TR><TD>NIL 	<TD>   <TD>    <TD><TD>Empty operation
<TR><TD>BEGIN	<TD>   <TD>file<TD><TD>File start sequence
<TR><TD>END 	<TD>   <TD>    <TD><TD>File end sequence
<TR><TD>TEXT 	<TD>   <TD>    <TD><TD>Start of the text segment (code)
<TR><TD>RODATA 	<TD>   <TD>    <TD><TD>Start of the read-only data segment (constant)
<TR><TD>DATA 	<TD>   <TD>    <TD><TD>Start of initialized data segment
<TR><TD>BSS 	<TD>   <TD>    <TD><TD>Start of non-initialized data segment
<TR><TD>ALIGN 	<TD>   <TD>    <TD><TD>Force data or code alignement
<TR><TD>EXTRN 	<TD>   <TD>name<TD><TD>Declare an external symbol (import from a foreign module)
<TR><TD>COMMON 	<TD>   <TD>len<TD><TD>Declare a common module symbol. [*10*]
<TR><TD>GLOBL 	<TD>tipo<TD>name<TD><TD>Declare a global symbol; the second argument describes the symbol type: NONE - unknown, FUNC - function, OBJ - data
<TR><TD>ENDF	 	<TD>   <TD>name<TD><TD>Declare the end of a function (used by some assembler to determine the function size for PIC code).
<TR><TD>ARGS	 	<TD>num<TD>    <TD><TD>Declares the number of function arguments (see CALL below).
<TR><TD>STR 	<TD>   <TD>str <TD><TD>Declares a null terminated byte sequence of the given string, without any special characters [*1*]
<TR><TD>CHAR 	<TD>   <TD>char<TD><TD>Declares a single character byte (use <I>unsigned char</I> for non-ASCII characters)
<TR><TD>SHORT 	<TD>val<TD>    <TD><TD>Declares a 16 bit short
<TR><TD>INTEGER 	<TD>val<TD>    <TD><TD>Declares a 32 bit integer
<TR><TD>LONG 	<TD>val<TD>    <TD><TD>Declares a 64 bit long integer
<TR><TD>FLOAT 	<TD>   <TD>num <TD><TD>Declares a 32 bit single precision floating point number
<TR><TD>DOUBLE 	<TD>   <TD>num <TD><TD>Declares a 64 bit single precision floating point number
<TR><TD>ID 		<TD>name<TD><TD><TD>Declares a name, the address to which the name refers [*1*]
<TR><TD>BYTE 	<TD>len<TD>    <TD><TD>Declares an array of <TT>len</TT> bytes.
<TR><TD>IMM 	<TD>val<TD>    <TD>: val<TD>Pushes an immediate <tt>val</tt> to the stack.
<TR><TD>ADD 	<TD>   <TD>    <TD>b a : b+a<TD>Add two integers and push the result [*2*]
<TR><TD>SUB 	<TD>   <TD>    <TD>b a : b-a<TD>Subtract two integers [*2*]
<TR><TD>MUL 	<TD>   <TD>    <TD>b a : b*a<TD>Multiply two integers [*2*]
<TR><TD>DIV 	<TD>   <TD>    <TD>b a : b/a<TD>Divide two integers [*2*]
<TR><TD>MOD 	<TD>   <TD>    <TD>b a : b%a<TD>Division remainder of two integers [*2*]
<TR><TD>NEG 	<TD>   <TD>    <TD>a : -a<TD>Replaces the top of the stack by its simetric value
<TR><TD>INCR 	<TD>val<TD>    <TD>a : a<TD>Increment by <B>val</B> the contents of the address at the top of the stack
<TR><TD>DECR 	<TD>val<TD>    <TD>a : a<TD>Decrements by <B>val</B> the contents of the address at the top of the stack
<TR><TD>GT 		<TD>   <TD>    <TD>b a : b&gt;a<TD>Compares two integers and pushes the greater than result [*3*]
<TR><TD>GE 		<TD>   <TD>    <TD>b a : b&gt;=a<TD>Compares two integers and pushes the greater or equal result [*3*]
<TR><TD>LT 		<TD>   <TD>    <TD>b a : b&lt;a<TD>Compares two integers and pushes the lesser than result [*3*]
<TR><TD>LE 		<TD>   <TD>    <TD>b a : b&lt;=a<TD>Compares two integers and pushes the lesser or equal result [*3*]
<TR><TD>EQ 		<TD>   <TD>    <TD>b a : b==a<TD>Compares two integers and pushes the equal result [*3*]
<TR><TD>NE 		<TD>   <TD>    <TD>b a : b!=a<TD>Compares two integers and pushes the not equal result [*3*]
<TR><TD>AND 	<TD>   <TD>    <TD>b a : b&amp;a<TD>Bit-wise AND [*2*]
<TR><TD>OR 		<TD>   <TD>    <TD>b a : b|a<TD>Bit-wise OR (inclusive) [*2*]
<TR><TD>XOR 	<TD>   <TD>    <TD>b a : b^a<TD>Bit-wise OR (exclusive) [*2*]
<TR><TD>NOT 	<TD>   <TD>    <TD>a : ~a<TD>Negate the top of the stack (ones complement)
<TR><TD>LOCAL 	<TD>val<TD>    <TD>: fp+val<TD>Push the frame pointer address added by <tt>val</tt> to the top of the stack (function argments for <tt>val &gt;= 8</tt> and locals for <tt>val &lt;= -4</tt>; frame-pointer for <tt>val = 0</tt>, retorn value <tt>val = 4</tt> for 32-bit) [*4*]
<TR><TD>ADDR 	<TD>   <TD>name<TD>: addr<TD>Pushes the address of the given label [*4*]
<TR><TD>LOAD 	<TD>   <TD>    <TD>addr : [addr]<TD>Replaces the address on the top of stack by its contents (rvalue)
<TR><TD>LDCHR 	<TD>   <TD>    <TD>addr : [addr]<TD>Replaces the address on the top of stack by its contents (char)
<TR><TD>LD16 	<TD>   <TD>    <TD>addr : [addr]<TD>Replaces the address on the top of stack by its contents (short)
<TR><TD>LD32 	<TD>   <TD>    <TD>addr : [addr]<TD>Replaces the address on the top of stack by its contents (int)
<TR><TD>LD64 	<TD>   <TD>    <TD>addr : [addr]<TD>Replaces the address on the top of stack by its contents (long)
<TR><TD>STORE 	<TD>   <TD>    <TD>val addr :<TD>Store the value <tt>val</tt> into the address <tt>addr</tt>
<TR><TD>STCHR 	<TD>   <TD>    <TD>val addr :<TD>Store the value <tt>val</tt> into the address <tt>addr</tt> (char)
<TR><TD>ST16 	<TD>   <TD>    <TD>val addr :<TD>Store the value <tt>val</tt> into the address <tt>addr</tt> (short)
<TR><TD>ST32 	<TD>   <TD>    <TD>val addr :<TD>Store the value <tt>val</tt> into the address <tt>addr</tt> (int)
<TR><TD>ST64 	<TD>   <TD>    <TD>val addr :<TD>Store the value <tt>val</tt> into the address <tt>addr</tt> (long)
<TR><TD>ENTER 	<TD>val<TD>    <TD>: fp #val<TD>Build a function frame with <tt>val</tt> bytes of reserved local data [*6*]
<TR><TD>START 	<TD>   <TD>    <TD>: fp<TD>Build an empty function frame [*6*]
<TR><TD>ALLOC 	<TD>   <TD>    <TD>val : #val<TD>Reserve <tt>val</tt> bytes in the stack. [*5*]
<TR><TD>LEAVE 	<TD>   <TD>    <TD>fp ... :<TD>Remove a function frame and all local data. [*6*]
<TR><TD>TRASH 	<TD>val<TD>    <TD>#val :<TD>Remove <tt>val</tt> bytes from the stack [*6*]
<TR><TD>LABEL 	<TD>   <TD>name<TD><TD>Generate a label named <tt>name</tt>.
<TR><TD>CALL 	<TD>   <TD>name<TD>: ret<TD>Call a function by <tt>name</tt>.
<TR><TD>RET 	<TD>   <TD>    <TD>ret :<TD>Return from function.
<TR><TD>RETN 	<TD>num<TD>    <TD>#num ret :<TD>Return from function and remove <tt>num</tt> byte from stack (for <b>Pascal</b> calls).
<TR><TD>JMP 	<TD>   <TD>name<TD>:<TD>Inconditional jump to label <tt>name</tt>.
<TR><TD>JZ 		<TD>   <TD>name<TD>val :<TD>Jump on zero (on top of the stack) to label <tt>name</tt>.
<TR><TD>JNZ 	<TD>   <TD>name<TD>val :<TD>Jump on not-zero (on top of the stack) to label <tt>name</tt>.
<TR><TD>BRANCH 	<TD>   <TD>    <TD>addr : ret<TD>Call function by address (on top of the stack).
<TR><TD>LEAP 	<TD>   <TD>    <TD>addr :<TD>Inconditional jump to address on top of the stack.
<TR><TD>DUP 	<TD>   <TD>    <TD>a : a a<TD>Duplicate the top of the stack.
<TR><TD>PICK 	<TD>   <TD>    <TD>n : a@n<TD>Duplicate the stack element <B>n</B> stack positions deep (PICK 0 = DUP)
<TR><TD>SWAP 	<TD>   <TD>    <TD>a b : b a<TD>Swap the two elements of the top of the stack.
<TR><TD>PUSH 	<TD>   <TD>    <TD>: a<TD>Push the machine accumulator register to the top of the stack (function return values) [*8*]
<TR><TD>POP 	<TD>   <TD>    <TD>a :<TD>Pop the top of the stack to the machine accumulator register (function return values) [*8*]
<TR><TD>ROTL 	<TD>   <TD>    <TD>a b : a&gt;rotl&lt;b<TD>Rotate left by <tt>a</tt> bits the <tt>b</tt> value [*9*]
<TR><TD>ROTR 	<TD>   <TD>    <TD>a b : a&gt;rotr&lt;b<TD>Rotate right by <tt>a</tt> bits the <tt>b</tt> value [*9*]
<TR><TD>SHTL 	<TD>   <TD>    <TD>a b : a&gt;&gt;b<TD>Shift left by <tt>a</tt> bits the <tt>b</tt> value [*9*]
<TR><TD>SHTRU 	<TD>   <TD>    <TD>a b : a&gt;&gt;b<TD>Shift right arithemtic by <tt>a</tt> bits the <tt>b</tt> value [*9*]
<TR><TD>SHTRS 	<TD>   <TD>    <TD>a b : a&gt;&gt;&gt;b<TD>Shift right signed by <tt>a</tt> bits the <tt>b</tt> value [*9*]
<TR><TD>SP 		<TD>   <TD>    <TD>: sp<TD>Pushes the top of the stack into the top of the stack (<I>stack pointer</I>) 
<TR><TD>I2D		<TD>   <TD>    <TD>i : d<TD>Convert an integer to double (double precision floating point number)
<TR><TD>F2D		<TD>   <TD>    <TD>f : d<TD>Convert an integer to float (single precision floating point number)
<TR><TD>D2I		<TD>   <TD>    <TD>d : i<TD>Convert a double to integer
<TR><TD>D2F		<TD>   <TD>    <TD>d : f<TD>Convert a float to integer
<TR><TD>DADD	<TD>   <TD>    <TD>d1 d2 : d3<TD>Add two double numbers
<TR><TD>DSUB	<TD>   <TD>    <TD>d1 d2 : d3<TD>Subtract two double numbers
<TR><TD>DMUL	<TD>   <TD>    <TD>d1 d2 : d3<TD>Multiply two double numbers
<TR><TD>DDIV	<TD>   <TD>    <TD>d1 d2 : d3<TD>Divide two double numbers
<TR><TD>DNEG	<TD>   <TD>    <TD>d1 d2 : d3<TD>Negate a double number (negative)
<TR><TD>DCMP		<TD>   <TD>    <TD>d1 d2 : i<TD>Compare two double number and push the comparison result (positive, negative or null) [* 10 *]
<TR><TD>DPUSH		<TD>   <TD>    <TD>: d<TD>Push the floating point machine register accumulator into the stack (function return values)
<TR><TD>DPOP		<TD>   <TD>    <TD>d :<TD>Pop the floating point machine register accumulator from the stack (function return values)
<TR><TD>LOAD2		<TD>   <TD>    <TD>a : d<TD>Replaces the address at the top of the stack by its double precision floating point contents.
<TR><TD>STORE2		<TD>   <TD>    <TD>d a :<TD>Store at the address at the top of the stack the double precision floating point value.
<TR><TD>DUP2                <TD>   <TD>    <TD>d : d d <TD>Duplicate the double precision floating point value at the top of the stack.
<TR><TD>ULDCHR 	<TD>   <TD>    <TD>addr : [addr]<TD>Load an unsigned byte at the given address (no sign extend)
<TR><TD>ULD16 	<TD>   <TD>    <TD>addr : [addr]<TD>Load an unsigned short at the given address (no sign extend)
<TR><TD>UDIV 	<TD>   <TD>    <TD>b a : b/a<TD>Divide two unsigned integers [*2*]
<TR><TD>UMOD 	<TD>   <TD>    <TD>b a : b%a<TD>Division remainder of two unsigned integers [*2*]
<TR><TD>UGT 		<TD>   <TD>    <TD>b a : b&gt;a<TD>Compare two unsigned integers: greater than [*3*]
<TR><TD>UGE 		<TD>   <TD>    <TD>b a : b&gt;=a<TD>Compare two unsigned integers: greater or equal [*3*]
<TR><TD>ULT 		<TD>   <TD>    <TD>b a : b&lt;a<TD>Compare two unsigned integers: less than [*3*]
<TR><TD>ULE 		<TD>   <TD>    <TD>b a : b&lt;=a<TD>Compare two unsigned integers: less or equal [*3*]
<TR><TD>NOP		<TD>   <TD>    <TD>:<TD>Nop operation (consumes execution time but does change processor status)
<TR><TD>LOCV 	<TD>val<TD>    <TD>: [fp+val]<TD>Pushes the contents of the frame pointer added by <tt>val</tt> bytes [*7*]
<TR><TD>ADDRV 	<TD>   <TD>name<TD>: [name]<TD>Pushes the contents of <tt>name</tt> [*7*]
<TR><TD>LOCA 	<TD>val<TD>    <TD>a :<TD>Store the value on the top of the stack into the position given by the stack pointer added by <tt>val</tt> [*7*]
<TR><TD>ADDRA 	<TD>   <TD>name<TD>a :<TD>Store the value on the top of the stack into the position given <tt>name</tt> [*7*]
<TR><TD>JEQ 	<TD>   <TD>name<TD>a b :<TD>Jump to <tt>name</tt> when the two integers on top of the stack are equal [*7*]
<TR><TD>JNEQ 	<TD>   <TD>name<TD>a b :<TD>Jump to <tt>name</tt> when the two integers on top of the stack are not equal [*7*]
<TR><TD>JGT 	<TD>   <TD>name<TD>a b :<TD>Jump to <tt>name</tt> when integer <tt>a</tt> is greater than <tt>b</tt> [*7*]
<TR><TD>JGE 	<TD>   <TD>name<TD>a b :<TD>Jump to <tt>name</tt> when integer <tt>a</tt> is greater or equal <tt>b</tt> [*7*]
<TR><TD>JLT 	<TD>   <TD>name<TD>a b :<TD>Jump to <tt>name</tt> when integer <tt>a</tt> is less than <tt>b</tt> [*7*]
<TR><TD>JLE 	<TD>   <TD>name<TD>a b :<TD>Jump to <tt>name</tt> when integer <tt>a</tt> is less or equal <tt>b</tt> [*7*]
<TR><TD>JUGT 	<TD>   <TD>name<TD>a b :<TD>Jump to <tt>name</tt> when unsigned integer <tt>a</tt> is greater than <tt>b</tt> [*7*]
<TR><TD>JUGE 	<TD>   <TD>name<TD>a b :<TD>Jump to <tt>name</tt> when unsigned integer <tt>a</tt> is greater or equal <tt>b</tt> [*7*]
<TR><TD>JULT 	<TD>   <TD>name<TD>a b :<TD>Jump to <tt>name</tt> when unsigned integer <tt>a</tt> is less than <tt>b</tt> [*7*]
<TR><TD>JULE 	<TD>   <TD>name<TD>a b :<TD>Jump to <tt>name</tt> when unsigned integer <tt>a</tt> is less or equal <tt>b</tt> [*7*]
</TABLE>


<H1><A NAME="SECTION1">
4 - Notes</A>
</H1>

<UL>
<LI>
[*0*] The column <I>effect</I> represents only the effect of values on the top of stack, not the remaining stack values.
The <B>#len</B> notation represents <B>len</B> on the stack.
<B>a #8 b : a b</B> before the opertion <B>a</B> was <b>8</b> byte appart from <B>b</B> (with <b>b</b> on the top of the stack).
After the operation <b>b</b> remains on the top of the stack and <b>a</b> is immediatley after with no gap between them.
<LI>
[*1*] Declaraed values must be stored in data segments and can not be used as executable code in the <tt>TEXT</tt> segment.
Only immediate values are executable code.
<LI>
[*2*] Binary operations obtain their arguments from the stack and push the resulting value back to it.
Some architecture implementation may provide the same result with more efficient instruction that do not move as many values.
<LI>
[*3*] Binary comparisons push and integer 0 (zero) or 1 (one) into the stack, depending whether the result is <i>false</i> or <i>true</i>, repectively.
This value can be assigned of directly used in jump instruction, such as JZ and JNZ that remove a jump condition from the top of the stack instead of a processor <i>flags</i> register.
<LI>
[*4*] These operation put the address of the symbol on the top of the stack.
The address can then be used by LOAD or STORE operations.
The alternatives described in [*10*] provide more efficient instructions for such operation sequences.
<LI>
[*5*] Stack allocation is equivalent to the <TT>alloca</TT> routine of the <B>C</B> programming language.
After a stack alocation, stack pointer offsets of temporary variables change.
Using stack allocation as an instruction, not as an expression, ensures no stack temporaries are on the stack.
<LI>
[*6*] In a stack machine, the expression evaluation of function arguments of a function calling are already on the stack, unless explicitly removed.
In a <TT><B>C</B> calling convetion</TT> the argument should be removed by a TRASH instrution after the returns.
<LI>
[*7*] Quick opcodes are more efficient operations that can be achieved by other postfix instruction.
<LI>
[*8*] Direct stack manipulation operations are implicit in most instructions, except for very specific cases.
<LI>
[*9*] Shift and rotate operations are usualy defined for the number of bits of the manipulated number.
The result is undefined for higher values.
<LI>
[*9*] In a common delcaration only one of the modules may provide an initial value, all other declarations of the same symbol must non-initialized common declarations or extern declarations.
<LI>
[*10*] In order to compare two double precision floating point numbers with DCMP an integer (positive, negative or null) is produced that can later be compared with 0 (zero) in order to produce jump conditions: DCMP, IMM 0; followed by the integer comparison (EQ, NE, LT, ...).

</UL>
<BR><HR>
<ADDRESS>
Pedro Reis Santos
$Id: postfix.html,v 1.4 2020/11/18 17:24:33 prs Exp $
</ADDRESS>
</BODY>
</HTML>
