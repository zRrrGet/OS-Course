#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct process {
    int AT;
    int BT;
};

int comp (const void *a, const void *b) {
    return ((struct process *)a)->AT-((struct process *)b)->AT;
}

int main() {
    int n = 0;
    struct process ps[100];

    FILE *f = NULL;
    f = fopen("input.csv", "r");
    for (int i = 0; fscanf(f, "%d,%d", &ps[i].AT, &ps[i].BT) != EOF && i < SIZE; i++, n++);
    
    printf("P#\tAT\tBT\tCT\tTAT\tWT\n\n");

    qsort(ps, n, sizeof(*ps), comp);

    int t = -1;
    int totalTat = 0;
    int totalWt = 0;
    for (int i = 0; i < n; i++) {
        if (t < ps[i].AT) {
            t = ps[i].AT;
        }
        int ct = t + ps[i].BT;
        int tat = ct - ps[i].AT;
        int wt = t - ps[i].AT;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, ps[i].AT, ps[i].BT, ct, tat, wt);

        totalTat += tat;
        totalWt += wt;
        t = ct;
    }

    float avgTat = (float) totalTat / n;
    float avgWt = (float) totalWt / n;

    printf("\nAverage Turnaround Time = %f", avgTat);
    printf("\nAverage WT = %f\n", avgWt);

    return 0;
}