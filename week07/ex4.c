#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *realloc(void *ptr, size_t size) {
    if (!size) {
        free(ptr);
        return NULL;
    }
    void *new_ptr;
    new_ptr = malloc(size);
    if (!ptr) {
        return new_ptr;
    }
    memcpy(new_ptr, ptr, size);
    free(ptr);
    return new_ptr;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int *array = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++){
        array[i] = i;
        printf("%d\n", array[i]);
    }
    int nn=0;
    scanf("%d", &nn);
    array = realloc(array, sizeof(int) * nn);
	for(int i = n; i < nn; i++) {
		array[i] = i;
	}
    for(int i=0; i < nn;i++){
        printf("%d\n", array[i]);
    }
    printf("\n");
    return 0;
}