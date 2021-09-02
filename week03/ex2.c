#include <stdio.h>
#include <stdlib.h>

struct array {
	int *p;
	int n;
};

void bubble_sort(struct array a) {
	for (int i = 0;i < a.n; ++i)
		for (int j = 0; j < a.n; ++j)
			if (a.p[i] < a.p[j])
			{
				int t = a.p[i];
				a.p[i] = a.p[j];
				a.p[j] = t;
			}
}
#define SIZE 3
int main() {
	struct array a = {malloc(sizeof(int)*SIZE), SIZE};
	a.p[0] = 3; a.p[1] = 1; a.p[2] = 6; 
	for (int i = 0;i < SIZE; ++i)
		printf("%d ", a.p[i]);
	printf("\n");	
	bubble_sort(a);
	for (int i = 0;i < SIZE; ++i)
		printf("%d ", a.p[i]);
}
