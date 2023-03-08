#include <stdio.h>




struct fcfs{
int pid;
int btime;
int atime;
int ttime;
int wtime;
int ctime;
}p[10];

int temp;
int main(){
int i,n;
int totttime=0; int totwtime=0;
printf("enter the number of processes");
scanf("%d",&n);
for(int i=0;i<n;i++){

printf("enter the burst time for each process");
scanf("%d",&p[i].btime);
p[0].wtime=0;
p[0].ttime=p[0].btime;

}
printf("enter the arrival time for each process");
for(int i=0;i<n;i++)
{
scanf("%d",&p[i].atime);
}

for(int i=0;i<n;i++)
{
for(int j=0;j<n-1;j++)
if(p[j].atime>p[j+1].atime)
{
temp=p[j].atime;
p[j].atime=p[j+1].atime;
p[j+1].atime=temp;
}
}
printf("process id of each process");
for(int i=0;i<n;i++)
{
printf("process id %d %d",i,p[i].pid);
}







for(int i=0;i<n;i++){
p[i].wtime=p[i-1].wtime+ p[i-1].btime;
p[i].ttime= p[i].wtime+p[i].btime;
totttime += p[i].ttime;
totwtime += p[i].wtime;

} 
for(int i=0;i<n;i++)
{printf("waiting time for process %d" ,p[i].wtime);
printf("turn around time for process %d",p[i].ttime);
printf("\n");
}
printf("\n total waiting time :%d", totwtime );
printf("\n average waiting time :%f",(float)totwtime/n);
printf("\n total turn around time :%d",totttime);
printf("\n average turn around time: :%f",(float)totttime/n);
}

