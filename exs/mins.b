main() {
	extrn min();
	extrn putint(), putchar();
	extrn getint();

	putint(min(getint(), getint()));
	putchar('*n');
	return (0);
	}
