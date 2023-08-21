#include <stdio.h>

int main() {
    int i, j, n, ref_string[50], frame[10], no, k, avail, fcount = 0,freq[40],leastfreq,y;
    printf("\n ENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &n); // total no. of pages in the reference string

    printf("\n ENTER THE PAGE NUMBER:\n");
    for (i = 0; i < n; i++) // accept the entire reference string
        scanf("%d", &ref_string[i]);

    printf("\n ENTER THE NUMBER OF FRAMES: ");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
        frame[i] = -1; // initialize all page frames to -1

    printf("\n ref string  \t page frames     \tHit/Fault\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t", ref_string[i]);
        avail = 0; // Default value of available flag is 0


        for (k = 0; k < no; k++) {
            if (frame[k] == ref_string[i]) // input of the page requested is compared with existing content of FRAME
            {
                // as the page is found, available is turned 1
                 freq[k]++;

                // Move the accessed page to the most recently used position
                break;

                for (k = 0; k < no; k++)
                    printf("%d\t", frame[k]); // Print the current state of the FRAME

                printf("H"); // Indication of Page Hit
                break;
            }
        }

        if (k == no) // input page requested NOT existing in FRAME
        {
           leastfreq=0;
     for (k = 1; k < no; k++)
       if(freq[k]<freq[leastfreq])
          
          leastfreq=k;
         ref_string[leastfreq]=ref_string[i];
         freq[leastfreq]=1;

         // Place the requested page at the front of the FRAME
            fcount++;             // Increment Counter for Page Fault

            for (k = 0; k < no; k++)
          {
                printf("%d\t", frame[k]); // Print the current state of the FRAME
                     }


            printf("F"); // Indication of Page Fault
        }

        printf("\n");
    }

    printf("Page Fault Is %d", fcount);
    return 0;
}
