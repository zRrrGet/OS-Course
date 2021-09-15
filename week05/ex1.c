#include <stdio.h>
#include <pthread.h>
#define N 3

void *callback(int n) {
	printf("pow! from thread %d \n", n);
	pthread_exit(NULL);
}

int main() {
	for (int i = 0; i < N; ++i) {
		pthread_t t;
		if (!pthread_create(&t, NULL, callback, i)) {
			printf("Thread number %d created\n", i);
			pthread_join(t, NULL);
		}
		else
			printf("Failed to create %d thread\n", i);
	}
}
