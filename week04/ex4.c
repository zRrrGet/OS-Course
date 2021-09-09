#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    for (;;) {
        char *cmd;
        fgets(cmd, 256, stdin);
        char *argv[256];
        char *pch = strtok (cmd," \n");
        int i;
        for (i = 0;pch != NULL; ++i) {
            argv[i] = pch;
            pch = strtok(NULL, " \n");
        }
        argv[i] = NULL;

        int amp = 0;
        if (!strcmp(argv[i-1], "&")) {
            amp = 1;
            argv[i-1] = NULL;
        }
        pid_t pid = fork();
        if (!pid) {
            execve(argv[0], argv, NULL); // full path should be specified
        }
        else if (!amp){
            waitpid(pid, NULL, 0);
        }
    }
}

