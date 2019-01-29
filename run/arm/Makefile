DEST=../..
LDLIBS=librun.a
LDOBJ=run.o
SOFT=soft.o # use 'make SOFT=' for hard-float processors, e.g. raspberry-pi
OBJ=arm.o lib.o sys.o stk.o dbl.o $(SOFT) wrap.o char.o

all: $(LDLIBS) $(LDOBJ)
	cp $^ $(DEST)

$(LDLIBS): $(OBJ)
	ar crl $@ $?

$(LDOBJ): $(OBJ)
	ld -r -o $@ $^
	
soft.o:
	cd soft; $(MAKE) $(MFLAGS)
	cp soft/soft.o .

lib.o: lib.c
	$(CC) $(CFLAGS) -c -Denv=_env $<

dbl.o: dbl.c
	$(CC) $(CFLAGS) -c -DPOSTFIX $<

%:%.s
	as $< -o $*.o
	ld -o $@ $*.o $(LDLIBS)

%:%.o
	ld -o $@ $< $(LDLIBS)

.s.o:
	as $< -o $@

install:: $(LDLIBS)
	-cp $(LDLIBS) ..

clean::
	-rm -f *.o
	-rm -f $(LDLIBS) $(LDOBJ)
	cd soft; $(MAKE) $(MFLAGS) clean
