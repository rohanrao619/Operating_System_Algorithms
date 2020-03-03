#include<stdio.h>
int main()
{
    printf("For SSTF Disk Scheduling \n");
    int track,current;
    printf("Enter the track size\n");
    scanf("%d",&track);
    track=track-1;
    
    int n,i;
    printf("Enter the no of Request\n");
        scanf("%d",&n);
        printf("Enter the Request queue\n");
        int arr[n];
        int visited[n];
        for (i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            visited[i]=0;
        }
        

    printf("Enter the current position of R/W head\n");
    scanf("%d",&current);
    
    int min=1000,diff=5000,flag=7,seekt=0;
    int j;
    for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                    if(visited[j]==0)
                    {
                    diff=arr[j]-current;
                    if(diff<0)
                    {
                        diff=-diff;
                    }   

                    if(diff<min)
                        {
                            min=diff;
                            flag=j;
                        }
                    }
        
            }
            
            visited[flag]=1;
            seekt=seekt+min;
            min=1000;
            diff=5000;
            current=arr[flag];
        }
    
    printf("Total Seek Time %d",seekt)    }

