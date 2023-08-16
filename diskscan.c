#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,rq[1000],totalheadmom=0,inihead,size,temp,move,index,i,j;
    printf("enter the number of requests");
    scanf("%d",&n);
    printf("enter the request sequence");
    for(int i=0;i<n;i++)
    {
     scanf("%d",&rq[i]);
    }
    printf("enter the initial head position");
    scanf("%d",&inihead);
    printf("enter the total disk size");
    scanf("%d",&size);
    printf("enetr the headmoment direction-1 or 0");
    scanf("%d",&move);
    //sort the array
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(rq[j]>rq[j+1])
            {
                temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(inihead<rq[i])
        {
            index=i;
            break;
        }
    }

    if(move==1){
        for(i=index;i<n;i++){
            totalheadmom=totalheadmom +abs(rq[i]-inihead);
            inihead=rq[i];
        }
        //for last movement
    //rq[i] is the second last request a
    totalheadmom=totalheadmom +abs(size-rq[i-1]-1);
    inihead=size-1;
    //size=200, but only 199

for(i=index-1;i>=0;i--){
    totalheadmom=totalheadmom+abs(rq[i]-inihead);
    inihead=rq[i];
}

    }
    else{
    //towards low
    for(i=index-1;i>=0;i--){
    totalheadmom=totalheadmom+abs(rq[i]-inihead);
    inihead=rq[i];
}
//last movement 
totalheadmom=totalheadmom +abs(rq[i+1]-0);
inihead=0;
 for(i=index;i<n;i++){
            totalheadmom=totalheadmom +abs(rq[i]-inihead);
            inihead=rq[i];
        }
}
printf("totalheadmoment is %d",totalheadmom);
return 0;}
