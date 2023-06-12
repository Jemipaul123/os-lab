#include<stdio.h>

int main()
{
int n,m,i,j,k,p,q,c,d,max[30][30],alloc[30][30],avail[0][30];
printf("Enter the number of processes");
scanf("%d",&n);
printf("enter the number of resources");
scanf("%d",&m);

printf("enter the elements of allocation matrix\n");
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
scanf("%d",&alloc[i][j]);

}
}
printf("alloc matrix \n");
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
printf("%d ",alloc[i][j]);

}
}
printf("\n");
printf("enter the elements of the maximum matrix\n");

for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
scanf("%d",&max[i][j]);
}
}
printf("\n");
printf("max matrix \n");
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
printf("%d ",max[i][j]);
}
}
printf("\n");

printf("enter the available matrix\n");

for(int j=0;j<m;j++)
{
scanf("%d",&avail[0][j]);

}
int finish[30],ans[n],ind;
 for (k = 0; k < n; k++)  
    {  
        finish[k] = 0;  
    } 
     int need[30][30];  
     printf("the need matrix is\n");
    for (i = 0; i < n; i++)  
    {  
        for (j = 0; j < m; j++)  
        {    need[i][j] = max[i][j] - alloc[i][j];
            
            
               printf("%d ",need[i][j]); 
               }
             
    } 
    printf("\n");
 
    
    int y = 0;  
    for (k = 0; k < n; k++)  
    {  
        for (i = 0; i < n; i++)  
        {  
            if (finish [i] == 0)  
            {  
                int flag = 0;  
                for (j = 0; j < m; j++)  
                {  
                    if (need[i][j] > avail[0][j])  
                    {  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (flag == 0)  
                {  
                    ans[ind++] = i;  
                    for (y = 0; y < m; y++)  
                        avail[0][y] += alloc[i][y];  
                    finish[i] = 1;  
                }  
            }  
        }  
    }  
    int flag = 1;  
    for (int i = 0; i < n; i++)  
    {  
        if (finish[i] == 0)  
        {  
            flag = 0;  
            printf("The following system is not safe\n");  
            break;  
        }  
    }  
    if (flag == 1)  
    {  
        printf("Following is the SAFE Sequence\n");  
        for (i = 0; i < n - 1; i++)  
            printf(" P%d ->", ans[i]);  
        printf(" P%d\n", ans[n - 1]);  
    }  
    return (0);  
}  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    



