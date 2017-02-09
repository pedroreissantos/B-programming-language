s[100];
main() {
	extrn strcopy();
	extrn putstr(), putchar();

	putstr(strcopy(s, "hello world!")); putchar('*n');
	strcopy(s, "the end!");
	putstr(s);
	putchar('*n');
}
