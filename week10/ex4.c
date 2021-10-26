#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define BUF_SIZE 2048
#define INODE_NUM_SIZE 10
#define PATH_TO_FOLDER "./tmp"
#define HARDLINK_MIN_NUM 2
#define SHOW_NUM 0

typedef struct stat stat_t;
typedef struct dirent dirent_t;

int check(const ino_t inodeNum[], stat_t stats) {

    int flag = 0;
    for (int i = 0; i < 10; i++) {
        if (inodeNum[i] == stats.st_ino) {
            flag = 1;
            break;
        }
    }
    if (flag)
        return 1;
    return 0;
}

void getLnks(const char *p, const ino_t inodeNum[], int ind) {
    stat_t stats;
    dirent_t *ent;
    char buf[1024];
    DIR *dir = opendir(p);
    while ((ent = readdir(dir)) != NULL) {
        snprintf(buf, sizeof(buf), "%s/%s", p, ent->d_name);
        stat(buf, &stats);
        if (inodeNum[ind] == stats.st_ino) {
            printf("%s ", ent->d_name);
        }
    }
    closedir(dir);
    printf("\n");
}

int main() {
    const char *p = PATH_TO_FOLDER;
    DIR *d = opendir(p);
    dirent_t *ent = {0};
    stat_t stats = {0};
    char buf[BUF_SIZE];
    ino_t inodeNum[INODE_NUM_SIZE] = {0};
    int ind = 0;

    printf("File — Hard Links\n");

    while ((ent = readdir(d)) != NULL) {
        snprintf(buf, sizeof(buf), "%s/%s", p, ent->d_name);
        if (stat(buf, &stats) < 0) {
            perror("stats");
            continue;
        }
        if (SHOW_NUM == 1) {
            if (check(inodeNum, stats) == 1)
                continue;
        }
        if (!S_ISREG(stats.st_mode))
            continue;
        if (stats.st_nlink >= HARDLINK_MIN_NUM) {
            inodeNum[ind] = stats.st_ino;
            printf("%s(inode: %lu) — ", ent->d_name, inodeNum[ind]);
        } else { continue; }
        getLnks(p, inodeNum, ind);
        ind++;
    }
    closedir(d);

    return 0;
}