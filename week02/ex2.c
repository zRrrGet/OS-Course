#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

int main()
{
    char *a = NULL;
    size_t n = 0;
    getline(&a, &n, stdin);
    for (int i = strlen(a)-2; i>-1; --i)
        printf("%c", a[i]);
    return 0;
}
