#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, rq[1000], totalheadmom = 0, inihead, size, temp, move, index, i, j;
    printf("enter the number of requests");
    scanf("%d", &n);
    printf("enter the request sequence");
    for (int i = 0; i < n; i++) {
        scanf("%d", &rq[i]);
    }
    printf("enter the initial head position");
    scanf("%d", &inihead);
    printf("enter the total disk size");
    scanf("%d", &size);
    printf("enter the head movement direction - 1 or 0");
    scanf("%d", &move);

    // Sort the array
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (rq[j] > rq[j + 1]) {
                temp = rq[j];
                rq[j] = rq[j + 1];
                rq[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (inihead < rq[i]) {
            index = i;
            break;
        }
    }

    if (move == 1) {
        // Forward movement
        for (i = index; i < n; i++) {
            totalheadmom = totalheadmom + abs(rq[i] - inihead);
            inihead = rq[i];
        }
        // Move to the end
        totalheadmom = totalheadmom + abs(size - rq[n - 1] - 1);
        inihead = 0;  // Move to the beginning

        for (i = 0; i < index; i++) {
            totalheadmom = totalheadmom + abs(rq[i] - inihead);
            inihead = rq[i];
        }
    } else {
        // Backward movement
        for (i = index - 1; i >= 0; i--) {
            totalheadmom = totalheadmom + abs(rq[i] - inihead);
            inihead = rq[i];
        }
        // Move to the beginning
        totalheadmom = totalheadmom + rq[0];
        inihead = size - 1;  // Move to the end

        for (i = n - 1; i >= index; i--) {
            totalheadmom = totalheadmom + abs(rq[i] - inihead);
            inihead = rq[i];
        }
    }

    printf("total head movement is %d", totalheadmom + size-1);
    return 0;
}
