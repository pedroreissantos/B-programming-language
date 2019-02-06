ARCH=#-DpfARM
DEST=..
EXE=blc
EXT=.b
.SUFFIXES: $(EXT) .brg .asm
CC=gcc
CFLAGS=-g -DYYDEBUG -I"$(INC)" $(ARCH)
LEX=flex
LFLAGS=-l # -ld for debug
YACC=byacc
YFLAGS=-dv
BURG=pburg
BFLAGS=-T
LDLIBS=$(LIB)

INC=../lib
LIB=$(INC)/libutil.a
OBJ=scan.o gram.o code.o

all: $(EXE)
	cp $^ $(DEST)

$(EXE): $(OBJ)
	$(MAKE) $(MFLAGS) -C $(INC)
	$(LINK.c) $^ $(LDLIBS) -o $@

btr: scan.o tree.o
	$(MAKE) $(MFLAGS) -C $(INC)
	$(LINK.c) $^ $(LDLIBS) -o $@

.brg.c:
	$(BURG) $(BFLAGS) $< $@

scan.o: gram.o
code.o: gram.o

%: %.b
	./blc $< out.asm
	nasm -felf32 out.asm
	ld -melf_i386 out.o run/librun.a

clean:
	rm -f $(EXE) $(OBJ) a.out yyselect.c lex.yy.c *~ y.* *.o *.asm
