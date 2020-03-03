#include<stdio.h>
int main()
{
    printf("For FCFS Disk Scheduling \n");
    int track,initial;
    printf("Enter the track size\n");
    scanf("%d",&track);
    int n,i;
    printf("Enter the no of Request\n");
        scanf("%d",&n);
        printf("Enter the Request queue\n");
        int arr[n];
        
        for (i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        

    printf("Enter the initial position of R/W head\n");
    scanf("%d",&initial);
    arr[0]=initial;
    
    int seekt=0,diff=0;
    for(i=0;i<n;i++)
    {
        diff=arr[i+1]-arr[i];
        if(diff<0)
        {
            seekt=seekt-diff;
        }
        else
        {
            seekt=seekt+diff;
        }
    }
    
    printf("Toral seek time%d",seekt);

}

