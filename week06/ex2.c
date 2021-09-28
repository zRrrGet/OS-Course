#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct process {
    int AT;
    int BT;
};

int comp (const void *a, const void *b) {
    return ((struct process *)a)->BT-((struct process *)b)->BT;
}

int main() {
    int n = 0;
    struct process ps[SIZE];

    FILE *f = NULL;
    f = fopen("input.csv", "r");
    for (int i = 0; fscanf(f, "%d,%d", &ps[i].AT, &ps[i].BT) != EOF && i < SIZE; i++, n++);
    printf("P#\tAT\tBT\tCT\tTAT\tWT\n\n");

    qsort(ps, n, sizeof(*ps), comp);
    int totalTat = 0;
    int totalWt = 0;
    int minIndex = -2;
    int t = 0, k = 1;
    for (;;) {
        minIndex = -1;
        int minT = -1;
        for (int i = 0; i < n; i++) {
            if (ps[i].AT != -1) {
                if (ps[i].AT <= t) {
                    minIndex = i;
                    break;
                }
                if (minT == -1 || minT > ps[i].AT) {
                    minIndex = i;
                    minT = ps[i].AT;
                }
            }
        }
        if (minIndex == -1) {
            break;
        }

        if (t < ps[minIndex].AT) {
            t = ps[minIndex].AT;
        }
        int ct = t + ps[minIndex].BT;
        int tat = ct - ps[minIndex].AT;
        int wt = t - ps[minIndex].AT;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", k, ps[minIndex].AT, ps[minIndex].BT,
               ct, tat, wt);

        totalTat += tat;
        totalWt += wt;
        t = ct;

        ps[minIndex].AT = -1;
        k += 1;
    }

    float avgTat = (float) totalTat / n, avgWt = (float) totalWt / n;

    printf("\nAverage Turnaround Time = %f", avgTat);
    printf("\nAverage WT = %f\n", avgWt);

    return 0;
}