#include <stdio.h>
#include <string.h>

void *swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    printf("imma ask you to input integers\n");
    int a, b;
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}
