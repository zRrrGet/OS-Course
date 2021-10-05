#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int *array = malloc(sizeof(int)*n);
	for (int i = 0;i < n; ++i)
		array[i] = i;
	for (int i = 0;i < n; ++i)
		printf("%d\n", array[i]);
	int nn;
	scanf("%d", &nn);
	array = realloc(array, sizeof(int)*nn);
	for (int i = 0;i < nn; ++i)
		array[i] = i;
	for (int i = 0;i < nn; ++i)
		printf("%d\n", array[i]);
	free(array);
	return 0;
}
