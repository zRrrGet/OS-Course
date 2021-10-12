#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	// with top command, it's clear that ex2 process takes memory each second, and it's above all the other processes
	for (int i = 0; i < 10; ++i) {
		void *ptr = malloc(10 * 1024 * 1024);
		memset(ptr, 0, 10 * 1024 * 1024);
		sleep(1);
	}
}
