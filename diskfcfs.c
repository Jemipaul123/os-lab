#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,rq[1000],totalheadmom=0,inihead;
    printf("enter the number of requests");
    scanf("%d",&n);
    printf("enter the request sequence");
    for(int i=0;i<n;i++)
    {
     scanf("%d",&rq[i]);
    }
    printf("enter the initial head position");
    scanf("%d",&inihead);

    for(int i=0;i<n;i++)
    {
        totalheadmom = totalheadmom + abs(rq[i]-inihead);
        inihead=rq[i];
    }
    printf("total head moment is %d",totalheadmom);
}

