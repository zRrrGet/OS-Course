#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	// when program works, free memory goes down by 10 mb each second
	// after 10 seconds, all allocated memory deallocated, so free memory goes up by 100 mb
	for (int i = 0; i < 10; ++i) {
		void *ptr = malloc(10 * 1024 * 1024);
		memset(ptr, 0, 10 * 1024 * 1024);
		sleep(1);
	}
}
