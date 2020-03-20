#include <stdio.h>

extern const char *VERSION;

int main()
{
	short s = 5000;
	float f = 3.141592653589793;
	double d = 3.141592653589793;
	long double ld = 3.141592653589793;

	printf("short value: %d, sizeof: %ld\n", s, sizeof(s));
	printf("short sizeof: %ld\n", sizeof(short));
	printf("unsigned short sizeof: %ld\n", sizeof(unsigned short));

	printf("int sizeof: %ld\n", sizeof(int));
	printf("unsigned int sizeof: %ld\n", sizeof(unsigned int));

	printf("long sizeof: %ld\n", sizeof(long));
	printf("unsigned long sizeof: %ld\n", sizeof(unsigned long));

	printf("float value: %.15f, sizeof: %ld\n", f, sizeof(f));
	printf("float sizeof: %ld\n", sizeof(float));

	printf("double value: %.15f, sizeof: %ld\n", d, sizeof(d));
	printf("double sizeof: %ld\n", sizeof(double));

	printf("long double value: %.15Lf, sizeof: %ld\n", ld, sizeof(ld));
	printf("long double sizeof: %ld\n", sizeof(long double));

	printf("compare f == d: %d\n", f == d);
	printf("compare f == ld: %d\n", f == ld);
	printf("compare d == ld: %d\n", d == ld);

	return 0;
}
