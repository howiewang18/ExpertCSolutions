#!/bin/bash

clang c_declaration.c -o get_type

declarations=(
"char **argv"
"int (*daytab)[13]"
"void *comp()"
"volatile int a[5][]"
"const int b[3][2][]"
"void (*comp)()"
"char (*(*x())[])()"
"char (*(*x[3])[])[5]"
"char *(*c[10])(int **p)"
"void (*signal(int sig, int x))(int)"
"void (*signal(int sig, void(*f)()))(int)"
"void (*signal(int sig, void(*func)(int)))(int)"
)

for declaration in "${declarations[@]}"; do
	echo "$declaration"
	echo "$declaration" > input.txt
	./get_type < input.txt
	echo ""
done
