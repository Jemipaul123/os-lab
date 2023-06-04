#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>
 
 int main(){
    int i;
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid= shmget((key_t)2345,1024,0666|IPC_CREAT);
    printf("Key of shared memory is %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("process attached at %p\n",shared_memory);
    printf("enter the some data to write shared memory");
    read(0,buff,100);
    strcpy(shared_memory,buff);
    printf("you wrote %s",(char*)shared_memory);
 }
 #include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>
 
 int main(){
    int i;
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid= shmget((key_t)2345,1024,0666|IPC_CREAT);
    printf("Key of shared memory is %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("process attached at %p\n",shared_memory);
    
    printf("you wrote %s",(char*)shared_memory);
 }
