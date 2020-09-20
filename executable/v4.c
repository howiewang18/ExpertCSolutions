#include <stdio.h>

int f() {
	int a[10000];
	return a[0];
}

int main() {
	printf("Hello world!\n");
	printf("%d\n", f());
	return 0;
}
