LIB=run
OS=$(ELF32)
SYS=elf32
CC=gcc -m32 # para gerar elf32 em máquinas de 64 bits
LD=ld -melf_i386 # para gerar elf32 em máquinas de 64 bits
CFLAGS=-g -Dunderscore # -fno-stack-protector # quando __stack_chk_fail em Ubunto
BOOT=$(LIB).o # bootstrap runtime for a C compiler
RUNTIME=lib$(LIB).a # stand-alone runtime

ELF32=linux.o lib.o sys.o wrap.o char.o
ELF64=linux64.o lib64.o sys64.o
WIN32=win.obj lib.obj

NASM=nasm -f$(SYS)

all: $(RUNTIME) $(BOOT)

$(RUNTIME): dbl.o $(OS)
	ar crl $@ $?

$(BOOT): dbl.o $(OS)
	$(LD) -r -o  $@ $^

dbl.o: dbl.c
	$(CC) $(CFLAGS) -DPOSTFIX -c $<

.SUFFIXES: .asm .obj
.asm.obj:
	$(NASM) $<
.asm.o:
	$(NASM) $<
install:: $(RUNTIME)
	cp $(RUNTIME) ..
clean::
	rm -f $(RUNTIME) $(BOOT) *.o a.out core
