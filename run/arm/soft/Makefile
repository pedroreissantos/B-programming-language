GCCLIB=_arm_addsubdf3.o _arm_cmpdf2.o _arm_fixdfsi.o _arm_muldivdf3.o _arm_negdf2.o _arm_truncdfsf2.o _divsi3.o _udivsi3.o

all: soft.o

soft.o: stub.o
	ld -r -o $@ $< $(GCCLIB)
	nm -u $@
	
clean:
	rm -f soft.o stub.o
