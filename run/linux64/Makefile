DEST=../..
LIB=run
OS=$(ELF64)
SYS=elf64
CFLAGS=-g -Dunderscore -fno-stack-protector # quando __stack_chk_fail em Ubunto
BOOT=$(LIB).o # bootstrap runtime for a C compiler
RUNTIME=lib$(LIB).a # stand-alone runtime

ELF32=linux.o lib.o sys.o
ELF64=linux64.o lib64.o sys64.o wrap.o char.o cwrap.o
WIN32=win.obj lib.obj

NASM=nasm -f$(SYS)

all: $(RUNTIME) $(BOOT)
	cp $^ $(DEST)

$(RUNTIME): dbl.o $(OS)
	ar crl $@ $?

$(BOOT): dbl.o $(OS)
	ld -r -o  $@ $^

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
