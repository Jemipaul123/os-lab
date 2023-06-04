#include<stdio.h>
#include<conio.h>
#define max 30

void main()
{
    int i,j,n,t,bt[max],at[max],wt[max],tat[max],temp[max],p[max];
    float awt =0, atat=0;
    printf("enter the number of processes");
    scanf("%d",&n);
    printf("enter the process numbers");
    for(i=0;i<n;i++){
    scanf("%d",&p[i]);
    }
    printf("enter the burst times");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    //sort it
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;

                t=p[j];
                p[j]=p[j+1];
                p[j+1] =t;

            }
printf("process\t bt\t wt\t tat\n");
 for(i=0;i<n;i++)
 {
    wt[i]=0;
    tat[i]=0;
    for(j=0;j<i;j++)
    {
        wt[i]=wt[i]+bt[j];

    }
    tat[i]=bt[i] + wt[i];
    awt =awt+wt[i];
    atat=atat + tat[i];
 printf("%d\t %d\t  %d\t %d\n",p[i],bt[i],wt[i],tat[i]);
 
 }
 awt=awt/n;
    atat=atat/n;
    printf("Avg wait time %f",awt);
    printf("Avg tat %f",atat);
}

        }
    }
