#include<stdio.h>
#include<conio.h>
#define max 30
void main(){
     int i,j,n,count=0,sq=0,qt,bt[max],at[max],wt[max],tat[max],temp,pr[max],rem_bt[max];
     float awt=0,atat=0;
     printf("enter the number of processes");
     scanf("%d",&n);
     printf("enter the burst times");
     for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
     }
     printf("enter the quantum time");
     scanf("%d",&qt);

     while(1){
        for(i=0,count=0;i<n;i++)
        {
            temp=qt;
            if(rem_bt[i]==0)
            {
                count++;
                continue;
            }
            if(rem_bt[i]>qt)
            {
               rem_bt[i]=rem_bt[i]-qt;
            }
            else
            {if(rem_bt[i]>=0)
            {
                temp=rem_bt[i];
                rem_bt[i]=0;
            }}
            sq=sq+temp;
            tat[i]= sq;
        }
        if(n==count)
        break;
     }
     printf("process\t bt\t wt\t tat\n");
     for(i=0;i<n;i++){
     wt[i]=tat[i]-bt[i];
     awt=awt+wt[i];
     atat=atat +tat[i];
     printf("%d\t %d\t %d\t %d\n",i+1,bt[i],wt[i],tat[i]);
     }
     awt=awt/n;
    atat=atat/n;
    printf("Avg wait time %f",awt);
    printf("Avg tat %f",atat);
}
