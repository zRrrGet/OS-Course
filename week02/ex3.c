#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
    int r = -1, c = 1;
    sscanf(argv[1], "%d", &r);
    c = r * 2 - 1;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            if (j >= (c / 2 - i) && j <= (c / 2 + i))
                putchar('*');
            else
                putchar(' ');
        putchar('\n');
    }
    return 0;
}
