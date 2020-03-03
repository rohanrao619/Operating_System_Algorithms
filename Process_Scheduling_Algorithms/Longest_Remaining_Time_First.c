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
    int Bt[n],Ct[n],Rt[n];
    for(i=0;i<n;i++)
    Bt[i]=BT[i];
    for(i=0;i<n;i++)
    Rt[i]=-1;
    int count=0,prev=-1;
    j=0;
    while(j<n)
    {
        int max=-10,ind=-1;
        for(i=0;i<n;i++)
        {
            if(Bt[i]==max && Bt[i]>0)
            {
                if(Arr[i]<Arr[ind])
                ind=i;
            }
            
            else if(Bt[i]>max && Bt[i]>0)
            {
                if(Arr[i]<=count)
                {
                    max=Bt[i];
                    ind=i;
                }
            }
            
        }
        
        if(ind!=-1)
        Bt[ind]-=1;
        
        if(ind!=prev)
        printf("[%d]-%d-",count,(ind+1));
        
        if(ind!=prev && Rt[ind]==-1)
        {
            Rt[ind]=count-Arr[ind];
        }
        
        count++;
        
        if(Bt[ind]==0 && ind!=-1)
        {
            Ct[ind]=count;
            j++;
        }
        prev=ind;
    }
    
    int TAT[n],WT[n];
    
    for(i=0;i<n;i++)
    TAT[i]=Ct[i]-Arr[i];
    
    for(i=0;i<n;i++)
    WT[i]=TAT[i]-BT[i];
    
    printf("\nProcess Table:\nPid\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++)
    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),Arr[i],BT[i],Ct[i],TAT[i],WT[i],Rt[i]);
    
    float sum=0;
    for(i=0;i<n;i++)
    sum+=(float)TAT[i];
    printf("\nAverage TAT: %f",sum/n);
    sum=0;
    for(i=0;i<n;i++)
    sum+=(float)WT[i];
    printf("\nAverage WT: %f",sum/n);
    sum=0;
    for(i=0;i<n;i++)
    sum+=(float)Rt[i];
    printf("\nAverage RT: %f",sum/n);
}

