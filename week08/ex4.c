#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/resource.h>

int main() {
	struct rusage ru;
	for (int i = 0; i < 10; ++i) {
		void *ptr = malloc(10 * 1000 * 1000);
		memset(ptr, 0, 10 * 1000 * 1000);
		getrusage(RUSAGE_SELF, &ru);
		printf("mem %ld\n", ru.ru_maxrss);
		sleep(1);
	}
}
