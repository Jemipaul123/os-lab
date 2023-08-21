
#include <stdio.h>

int main() {
    int i, j, n, ref_string[50], frame[10], no, k, avail, fcount = 0, freq[10] = {0}, leastfreq, y;
    
    printf("\nENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &n); // total number of pages in the reference string

    printf("\nENTER THE PAGE NUMBER:\n");
    for (i = 0; i < n; i++) // accept the entire reference string
        scanf("%d", &ref_string[i]);

    printf("\nENTER THE NUMBER OF FRAMES: ");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
        frame[i] = -1; // initialize all page frames to -1

    printf("\nref string\t\tpage frames\t\tHit/Fault\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t", ref_string[i]);
        avail = 0; // Default value of available flag is 0

        for (k = 0; k < no; k++) {
            if (frame[k] == ref_string[i]) // input page requested is compared with existing content of FRAME
            {
                freq[k]++; // Increment the frequency of the accessed page
                printf("\t\t");

                for (j = 0; j < no; j++)
                    printf("%d\t", frame[j]); // Print the current state of the FRAME

                printf("H\n"); // Indication of Page Hit
                avail = 1; // Page is available in frame
                break;
            }
        }

        if (avail == 0) // Input page requested NOT existing in FRAME
        {
            leastfreq = 0;
            for (k = 1; k < no; k++)
                if (freq[k] < freq[leastfreq])
                    leastfreq = k;

            frame[leastfreq] = ref_string[i]; // Replace the least frequently used page
            freq[leastfreq] = 1; // Reset the frequency of the new page

            fcount++; // Increment Counter for Page Fault
            printf("\t\t");

            for (j = 0; j < no; j++)
                printf("%d\t", frame[j]); // Print the current state of the FRAME

            printf("F\n"); // Indication of Page Fault
        }
    }

    printf("\nPage Faults: %d\n", fcount);
    return 0;
}


