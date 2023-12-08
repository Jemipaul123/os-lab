#include <stdio.h>

int main()
{

    int process[10], at[10], bt[10], tat[10], wt[10], ct[10];
    int n, temp, ttat, twt;
    float avwt, avtat;
    printf("Enter the no of processes\n");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time of each process\n");
    for (int i = 0; i < n; i++)
    {
        process[i] = i;
        printf(" P%d", i);
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }


    ct[0] = bt[0] + at[0];
    wt[0] = 0;
    tat[0] = bt[0] + wt[0];
    ttat = tat[0];
    twt = wt[0];

    for (int i = 1; i < n; i++)
    {
        if (at[i] <= ct[i - 1])
        {
            wt[i] = ct[i - 1] - at[i];
        }
        else
            wt[i] = 0;
        tat[i] = wt[i] + bt[i];
        ttat = ttat + tat[i];
        twt = twt + wt[i];
        ct[i] = tat[i] + at[i];
    }

    avwt = (float)twt / (float)n;
    avtat = (float)ttat / (float)n;
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tCompletion time\tTAT\n");

    for (int i = 0; i < n; i++)
    {
        printf("p");
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], at[i], bt[i], wt[i], ct[i], tat[i]);
    }
    printf("\nAverage Waiting time is %f\n", avwt);
    printf("Average Turn Around Time is %f\n", avtat);
}
