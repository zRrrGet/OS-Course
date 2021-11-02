#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>

typedef struct dirent dirent_t;

int main() {
	DIR *d = opendir("/");
	if (d == NULL) return EXIT_FAILURE;
	dirent_t *dp;
	while ((dp = readdir(d)) != NULL) {
		if (dp->d_type == DT_REG || dp->d_type == DT_DIR)
			printf("%s\n", dp->d_name);
	}
	closedir(d);
	return EXIT_SUCCESS;
}