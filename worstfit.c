#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 1024 // maximum memory size
int memory[MAX_MEMORY]; // memory array
int num_processes = 0; // number of processes

// allocate memory using worst fit algorithm
int worstFit(int process_size)
{
    int worst_fit = -1, worst_index = -1;
    for(int i=0; i<MAX_MEMORY; i++)
    {
        if(memory[i] == 0)
        {
            int j = i;
            while(memory[j] == 0 && j < MAX_MEMORY && j-i+1 < process_size)
                j++;
            if(j-i+1 >= process_size && j-i+1 > worst_fit)
            {
                worst_fit = j-i+1;
                worst_index = i;
            }
            i = j;
        }
    }
    if(worst_index != -1)
    {
        for(int k=worst_index; k<worst_index+process_size; k++)
            memory[k] = num_processes+1;
        return worst_index;
    }
    return -1; // memory allocation failed
}

// main function
int main()
{
    int choice, process_size, process_id;
    printf("1. Allocate Memory using Worst Fit\n2. Exit\n");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\nEnter process size: ");
                    scanf("%d", &process_size);
                    process_id = worstFit(process_size);
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
