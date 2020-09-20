echo "Plain hello world"
clang ${OPTION} v1.c
ls -l a.out
size a.out
echo "Hello world with uninitialized array"
clang ${OPTION} v2.c
ls -l a.out
size a.out
echo "Hello world with initialized array"
clang ${OPTION} v3.c
ls -l a.out
size a.out
echo "Hello world with uninitialized array in function"
clang ${OPTION} v4.c
ls -l a.out
size a.out
echo "Hello world with initialized array in function"
clang ${OPTION} v5.c
ls -l a.out
size a.out
