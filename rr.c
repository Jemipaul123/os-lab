
#include<stdio.h>
int main(){
    int i,j,n,time,remain,ts,totalwait=0,totalturnaround=0;
    float avgwaittime,avgturntime;
    int at[10],bt[10],rt[10];
    printf("enter the number of processes");
    scanf("%d",&n);
    remain=n;
    for(i=0;i<n;i++){
        printf("enter the arrival time of each");
        scanf("%d",&at[i]);

    }
    for(int i=0;i<n;i++)
    {
        printf("enter the burst time of each");
        scanf("%d",&bt[i]);
        rt[i]=bt[i];                                      

    }
printf("enter the time slice");
scanf("%d",&ts);
int flag=0;
//main loop
for(time=0,i=0;remain!=0;)
{
    if(rt[i]<=ts&&rt[i]>0)
    {
        time=time+rt[i];
         rt[i]=0;
        flag=1;
       
}
else if(rt[i]>0)
{
    rt[i]=rt[i]-ts;
    time=time+ts;
}
//finally when remaining time is 0 calculate everything and set flag to 0
if(rt[i]==0 && flag==1){

remain--;
totalwait=totalwait+time-at[i]-bt[i];
totalturnaround=totalturnaround+time-at[i];
flag=0;

}
if(i==n-1)
i=0;
else if(at[i+1]<=time)
i++;
else
{
    i=0;
}

    
}
avgwaittime=totalwait/n;
avgturntime=totalturnaround/n;
printf("total waiting time=%d\n",totalwait);
printf("total turn around time=%d\n",totalturnaround);
printf("avg waiting time=%f\n",avgwaittime);
printf("avg turn around  time=%f\n",avgturntime);
}
