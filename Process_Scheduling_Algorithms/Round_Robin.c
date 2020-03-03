#include<stdio.h>

void main()
{
    int n,i,j,tq,len=0;
    printf("Enter no. of processes:");
    scanf("%d",&n);
    int Arr[n],BT[n];
    printf("Arrival times:\n");
    for(i=0;i<n;i++)
    scanf("%d",&Arr[i]);
    printf("Burst times:\n");
    for(i=0;i<n;i++)
    scanf("%d",&BT[i]);
    printf("Enter Time Quanta:");
    scanf("%d",&tq);
    int Bt[n],Ct[n],Rt[n];
    for(i=0;i<n;i++)
    {
        Bt[i]=BT[i];
        len+=BT[i];
        Rt[i]=-1;
    }
    int ready[len];
    int count=0,front=0,rear=-1,dec=0;
    j=0;
    printf("\nGantt chart:\n|");
    while(j<n)
    {
        int found=0;
        if(front>rear)
        {
            for(i=0;i<n;i++)
            if(Arr[i]==count)
            {
                ready[++rear]=i;
                found=1;
            }
            if(found==0)
            {
                if(dec==0)
                {
                    printf("%d-Idle-",count);
                    dec=1;
                }
                count++;
            }
        }
        else
        {
            int k,ind=ready[front++],dec=0;
            
            printf("%d-P%d-",count,(ind+1));
            
            if(Rt[ind]==-1)
            Rt[ind]=count-Arr[ind];
            
            if(Bt[ind]<=tq)
            {
                for(k=0;k<Bt[ind];k++)
                {
                    count++;
                    for(i=0;i<n;i++)
                    {
                        if(Arr[i]==count)
                        ready[++rear]=i;
                    }
                }
                Bt[ind]=0;
                Ct[ind]=count;
                j++;
            }
            else
            {
                for(k=0;k<tq;k++)
                {
                    count++;
                    for(i=0;i<n;i++)
                    {
                        if(Arr[i]==count)
                        ready[++rear]=i;
                    }
                }
                Bt[ind]-=tq;
                ready[++rear]=ind;
            }
        }
    }
    
    printf("%d|\n",count);
    
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

