#include <stdio.h>

void take_array(int ca[]) {
	printf("take_array: %p %p %p\n", &ca, &ca[0], &ca[1]);
}

void take_pointer(int* pa) {
	printf("take_pointer: %p %p %p %p\n", &pa, &pa[0], &pa[1], pa);
}

int ga[4] = {1, 2, 3, 4};

int main() {
	take_array(ga);
	take_pointer(ga);
	printf("on stack: %p %p %p\n", &ga, &ga[0], &ga[1]);
	return 0;
}
