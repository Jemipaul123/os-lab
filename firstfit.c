#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 1024 // maximum memory size
int memory[MAX_MEMORY]; // memory array
int num_processes = 0; // number of processes

// allocate memory using first fit algorithm
int firstFit(int process_size)
{
    for(int i=0; i<MAX_MEMORY; i++)
    {
        if(memory[i] == 0)
        {
            int j = i;
            while(memory[j] == 0 && j < MAX_MEMORY && j-i+1 < process_size)
                j++;
            if(j-i+1 == process_size)
            {
                for(int k=i; k<=j; k++)
                    memory[k] = num_processes+1;
                return i;
            }
            i = j;
        }
    }
    return -1; // memory allocation failed
}

// main function
int main()
{
    int choice, process_size, process_id;
    printf("1. Allocate Memory using First Fit\n2. Exit\n");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\nEnter process size: ");
                    scanf("%d", &process_size);
                    process_id = firstFit(process_size);
                    if(process_id == -1)
                        printf("\nMemory allocation failed!\n");
                    else
                    {
                        num_processes++;
                        printf("\nMemory allocated successfully to process %d\n", process_id+1);
                    }
                    break;
            case 2: exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
