#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
int p=fork();

if(p=1)
{
printf("child %d  \n",getppid());
}
else if(p>0)
{printf("parent %d \n",getpid());}

else
{
printf("No child process is created");
}
return 0;
}
