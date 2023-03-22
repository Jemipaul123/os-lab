#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;  // process ID
    int bt;   // burst time
    int at;   // arrival time
} process;

int compare(const void *a, const void *b) {
    process *p1 = (process *) a;
    process *p2 = (process *) b;
    return p1->at - p2->at;
}

int main() {
    int n, i, j, t = 0, wt = 0, tat = 0, total_bt = 0;
    float avg_wt, avg_tat;
    process *p;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    p = (process *) malloc(n * sizeof(process));

    // input process details
    for (i = 0; i < n; i++) {
        printf("Enter process %d details (AT BT): ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].pid = i + 1;
        total_bt += p[i].bt;
    }

    // sort processes by arrival time
    qsort(p, n, sizeof(process), compare);

    // run SJRF algorithm
    while (total_bt > 0) {
        int sj_idx = -1;
        for (i = 0; i < n; i++) {
            if (p[i].at <= t && p[i].bt > 0) {
                if (sj_idx == -1 || p[i].bt < p[sj_idx].bt) {
                    sj_idx = i;
                }
            }
        }

        if (sj_idx == -1) {
            // no process available to execute, wait for next arrival
            t++;
            continue;
        }

        // execute the shortest job for 1 unit of time
        p[sj_idx].bt--;
        total_bt--;
        t++;

        if (p[sj_idx].bt == 0) {
            // process is complete
            tat = t - p[sj_idx].at;
            wt += tat - p[sj_idx].bt;
        }
    }

    avg_wt = (float) wt / n;
    avg_tat = (float) tat / n;

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, tat - p[i].bt, tat);
    }

    printf("\nAverage waiting time: %f\n", avg_wt);
    printf("Average turnaround time: %f\n", avg_tat);

    free(p);

    return 0;
}
