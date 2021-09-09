#include <stdio.h>
#include <unistd.h>

int main() {
    int n = 1;
    for (int i = 0;i < 5;++i) {
        printf("%d\n", fork());
    }

    sleep(5);
}

