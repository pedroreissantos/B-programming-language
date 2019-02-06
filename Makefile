all:
	@echo "run 'make platform' where platform is: arm, armhf, linux32, linux64"

arm: clean
	$(MAKE) $(MFLAGS) -C src ARCH=-DpfARM
	$(MAKE) $(MFLAGS) -C run/arm

armhf: clean
	$(MAKE) $(MFLAGS) -C src ARCH=-DpfARM
	$(MAKE) $(MFLAGS) -C run/arm SOFT=

linux32: clean
	$(MAKE) $(MFLAGS) -C src ARCH=
	$(MAKE) $(MFLAGS) -C run/linux32

linux64: clean
	$(MAKE) $(MFLAGS) -C src ARCH=-DpfAMD64
	$(MAKE) $(MFLAGS) -C run/linux64

clean::
	$(MAKE) $(MFLAGS) -C src clean
	$(MAKE) $(MFLAGS) -C lib clean
	$(MAKE) $(MFLAGS) -C run/arm clean
	$(MAKE) $(MFLAGS) -C run/linux32 clean
	$(MAKE) $(MFLAGS) -C run/linux64 clean
	rm -f blc run.o librun.a
