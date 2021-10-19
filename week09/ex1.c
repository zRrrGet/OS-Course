#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEFAULT_PFRAME_NUM 10
#define INPUT_FILE "input.txt"
#define NONE -1

typedef struct pframe {
    int id;
    u_int16_t priority;
} pframe_t;

int main(int argc, char* argv[]) {
    int pframeNum;
    if (argc > 1) pframeNum = atoi(argv[1]);
    else pframeNum = DEFAULT_PFRAME_NUM;

    pframe_t *pframes = malloc(pframeNum * sizeof(pframe_t));
    for (int i = 0; i < pframeNum; i++) {
        pframes[i].id = NONE;
        pframes[i].priority = 0;
    }

    int pId = NONE;
    float hits = 0, misses = 0;
    FILE *f = fopen(INPUT_FILE, "r");
    printf("Print the number of pages");
    while (fscanf(f, "%d", &pId) != EOF) {
        bool isHit = false;
        int minPriority = NONE, minPriorityIndex = 0;
        for (int i = 0; i < pframeNum; i++) {
            printf("\ni = %d id = %d %d", i, pframes[i].id, pframes[i].priority);
            if (pframes[i].priority <= minPriority || minPriority == NONE) {
                minPriorityIndex = i;
                minPriority = pframes[i].priority;
            }
            if (pframes[i].id == pId) {
                ++hits;
                isHit = true;
                pframes[i].priority += (1 << 16);
            }
            pframes[i].priority >>= 1;
        }
        if (!isHit) {
            ++misses;
            pframes[minPriorityIndex].id = pId;
            pframes[minPriorityIndex].priority = (1 << 15);
        }
        printf("\ncurrent page number %d\n", pId);
    }
    printf("\nhit = %f miss = %f ratio = %f\n", hits, misses, hits / misses);
    fclose(f);
    free(pframes);
    return EXIT_SUCCESS;
}
