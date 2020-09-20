#include <stdlib.h>
#include <stdio.h>

int a = 0;
int b;

void f() {
	int i;
	printf("Now the stack top is near %p\n", &i);
}
int main() {
	int i;
	printf("The stack top is near     %p\n", &i);
	f();
	int *c = malloc(sizeof(int));
	printf("One address on heap is %p\n", c);
	free(c);
	printf("BSS  is near %p\n", &b);
	printf("Data is near %p\n", &a);
	printf("Text is near %p\n", &f);
	return 0;
}
