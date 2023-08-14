#include <stdio.h>

int main() {
    int i, j, blocknos, blocksize[10], processnos, processsize[10];
    int t;
    
    printf("Enter the no of memory blocks: ");
    scanf("%d", &blocknos);

    printf("Enter the size of each block in order:\n");
    for (i = 0; i < blocknos; i++) {
        scanf("%d", &blocksize[i]);
    }

    printf("Enter the no of processes: ");
    scanf("%d", &processnos);

    printf("Enter the size of each process:\n");
    for (i = 0; i < processnos; i++) {
        scanf("%d", &processsize[i]);
    }

    printf("Blockno.\tBlocksize\n");
    for (i = 0; i < blocknos; i++) {
        printf("%d\t\t%d\n", i + 1, blocksize[i]);
    }
    
    printf("Processno.\tProcessSize\n");
    for (i = 0; i < processnos; i++) {
        printf("%d\t\t%d\n", i + 1, processsize[i]);
    }

    printf("FIRST FIT MEMORY ALLOCATION\n");
    printf("Processno\tAllocated blockno\tAllocated blocksize\tFragment left\n");
    
    i = 0;
    while (i < processnos) {
        int allocated = 0;  // Flag to track if the process is allocated
        
        for (j = 0; j < blocknos; j++) {
            if (processsize[i] <= blocksize[j]) {
                t = blocksize[j];
                blocksize[j] -= processsize[i];
                printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n", i + 1, j + 1, t, blocksize[j]);
                allocated = 1;  // Set the flag to indicate allocation
                break;
            }
        }
        
        if (!allocated) {
            printf("%d\t\t\tNot allocated\n", i + 1);
        }
        
        i++;
    }

    return 0;
}
