#include <stdio.h>

int main() {
    int i, j, n, ref_str[50], frame[10], no, k, avail, fcount = 0;
    printf("\n ENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &n); // total no. of pages in the reference string

    printf("\n ENTER THE PAGE NUMBER:\n");
    for (i = 0; i < n; i++) // accept the entire reference string
        scanf("%d", &ref_str[i]);

    printf("\n ENTER THE NUMBER OF FRAMES: ");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
        frame[i] = -1; // initialize all page frames to -1

    printf("\n ref string  \t page frames     \tHit/Fault\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t", ref_str[i]);
        avail = 0; // Default value of available flag is 0


        for (k = 0; k < no; k++) {
            if (frame[k] == ref_str[i]) // input of the page requested is compared with existing content of FRAME
            {
                avail = 1; // as the page is found, available is turned 1

                // Move the accessed page to the most recently used position
                int temp = frame[k];
                for (int l = k; l <no-1; l++) {
                    frame[l] = frame[l + 1];
                }
                frame[no-1] = temp;

                for (k = 0; k < no; k++)
                    printf("%d\t", frame[k]); // Print the current state of the FRAME

                printf("H"); // Indication of Page Hit
                break;
            }
        }

        if (avail == 0) // input page requested NOT existing in FRAME
        {
           frame[j]=ref_str[i];
            j=(j+1)%no; // Place the requested page at the front of the FRAME
            fcount++;             // Increment Counter for Page Fault

            for (k = 0; k < no; k++)
                printf("%d\t", frame[k]); // Print the current state of the FRAME

            printf("F"); // Indication of Page Fault
        }

        printf("\n");
    }

    printf("Page Fault Is %d", fcount);
    return 0;
}
