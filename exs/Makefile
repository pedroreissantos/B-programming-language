COMP=../blc
EXT=.b
LDLIBS=../librun.a
.SUFFIXES: $(EXT) .brg .asm
NASM=nasm -felf32
#NASM=as -o $@
LD=ld -melf_i386 # 32-bit binaries in a 64-bit system
#LD=ld

SRC= 1.b 2.b 3.b ack.b bubble.b convert.b div.b \
	empty.b fib.b fibiter.b gcd.b \
	hello.b histograma.b incr.b iter.b lower.b mfind.b \
	nep.b novrfl.b powfunc.b printf.b printn.b \
	prog.b r.b recurs.b snide.b \
	tab.b testfit.b tri.b world.b

EXE=$(SRC:%.b=%)

all: $(EXE)

arm:
	$(MAKE) $(MFLAGS) NASM="as -o $@"

i386:
	$(MAKE) $(MFLAGS) LD="ld --melf_i386" NASM="nasm -felf32"

linux32:
	$(MAKE) $(MFLAGS) NASM="nasm -felf32"

linux64:
	$(MAKE) $(MFLAGS) NASM="nasm -felf64"

iter: iter.o fact.o
	$(LD) -o $@ $^ $(LDLIBS)
recurs: recurs.o fact.o
	$(LD) -o $@ $^ $(LDLIBS)
testfit: testfit.o fit.o
	$(LD) -o $@ $^ $(LDLIBS)
empty: empty.o hello.o
	$(LD) -o $@ $^ $(LDLIBS)
powfunc: powfunc.o power.o
	$(LD) -o $@ $^ $(LDLIBS)
mfind: find.o mfind.o
	$(LD) -o $@ $^ $(LDLIBS)
lower: lower.o tolower.o char.o
	$(LD) -o $@ $^ $(LDLIBS)
printf: printf.o printn.o printfunc.o
	$(LD) -o $@ $^ $(LDLIBS)
world: printf.o printn.o world.o
	$(LD) -o $@ $^ $(LDLIBS)
printn: printn.o printnum.o
	$(LD) -o $@ $^ $(LDLIBS)
convert: convert.o conv.o char.o printn.o printf.o
	$(LD) -o $@ $^ $(LDLIBS)
snide: snide.o unit.o char.o printn.o printf.o
	$(LD) -o $@ $^ $(LDLIBS)
bubble: bubble.o sort.o fit.o string.o
	$(LD) -o $@ $^ $(LDLIBS)
cmp: cmp.o string.o fit.o
	$(LD) -o $@ $^ $(LDLIBS)

%: %.o
	$(LD) -o $@ $< $(LDLIBS)

.asm.o:
	$(NASM) $<

.b.asm:
	$(COMP) $<

clean:
	rm -f a.out *~ *.o *.asm $(EXE)
