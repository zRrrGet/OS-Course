#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    for(;;) {
        char *cmd = NULL;
        int n = 0;
        getline(&cmd, &n, stdin);
        system(cmd);
    }

}

