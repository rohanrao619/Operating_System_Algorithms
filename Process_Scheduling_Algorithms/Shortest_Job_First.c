#include<stdio.h>

void main()
{
    int n,i,j;
    printf("Enter no. of processes:");
    scanf("%d",&n);
    int Arr[n],BT[n];
    printf("Arrival times:\n");
    for(i=0;i<n;i++)
    scanf("%d",&Arr[i]);
    printf("Burst times:\n");
    for(i=0;i<n;i++)
    scanf("%d",&BT[i]);
    int Bt[n],Ct[n];
    for(i=0;i<n;i++)
    Bt[i]=BT[i];
    int count=0;
    j=0;
    while(j<n)
    {
        int min=1000,ind=-1;
        for(i=0;i<n;i++)
        {
            if(Bt[i]==min)
            {
                if(Arr[i]<Arr[ind])
                ind=i;
            }
            
            else if(Bt[i]<min)
            {
                if(Arr[i]<=count)
                {
                    min=Bt[i];
                    ind=i;
                }
            }
            
        }
        if(ind!=-1)
        {
            Ct[ind]=BT[ind]+count;
            count+=BT[ind];
            j++;
            Bt[ind]=1001;
        }
        else
        count++;
    }
    
    int TAT[n],WT[n];
    
    for(i=0;i<n;i++)
    TAT[i]=Ct[i]-Arr[i];
    
    for(i=0;i<n;i++)
    WT[i]=TAT[i]-BT[i];
    
    printf("\nProcess Table:\nPid\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),Arr[i],BT[i],Ct[i],TAT[i],WT[i]);
    
    float sum=0;
    for(i=0;i<n;i++)
    sum+=(float)TAT[i];
    printf("\nAverage TAT: %f",sum/n);
    sum=0;
    for(i=0;i<n;i++)
    sum+=(float)WT[i];
    printf("\nAverage WT: %f",sum/n);
}

