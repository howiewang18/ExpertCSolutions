#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
	time_t time = 0x1, max_time;
	int i = 0;
	do {
		printf("Iteration %d, %*s", i++, 36, ctime(&time));
		max_time = time;
		time <<= 1;
	} while (ctime(&time) != NULL);
	printf("The max local time is approximately: %s", ctime(&max_time));
	
    return 0;
}


