#include<stdio.h>
#include<conio.h>
#define max 30

void main()
{
    int i,j,n,bt[max],at[max],wt[max],tat[max],temp[max];
    float awt=0,atat =0;
    printf("enter the number of processes");
    scanf("%d",&n);
    printf("enter the burst times");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
     printf("enter the arrival times");
    for(i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
    printf("process\t bt\t at\t wt\t tat\n");
    temp[0]=0;
    for(i=0;i<n;i++)
    {   wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i]+ bt[i];
        wt[i]=temp[i]-at[i];
        tat[i]=bt[i]+wt[i];

    awt=awt +wt[i];
    atat= atat+tat[i];
 printf("%d\t %d\t %d\t %d\t %d\n",i+1,bt[i],at[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("Avg wait time %f",awt);
    printf("Avg tat %f",atat);
}
