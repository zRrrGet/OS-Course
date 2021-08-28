#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("int %d\nfloat %f\ndouble %f\n", a, b, c);
    printf("int %d\nfloat %d\ndouble %d",
           sizeof(a), sizeof(b), sizeof(c));
    return 0;
}
