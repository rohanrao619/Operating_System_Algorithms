#include<stdio.h>

void main()
{
    int n,i,j;
    printf("Enter no. of processes:");
    scanf("%d",&n);
    int Arr[n],BT[n],PR[n];
    printf("Arrival times:\n");
    for(i=0;i<n;i++)
    scanf("%d",&Arr[i]);
    printf("Burst times:\n");
    for(i=0;i<n;i++)
    scanf("%d",&BT[i]);
    printf("Priority:\n");
    for(i=0;i<n;i++)
    scanf("%d",&PR[i]);
    int Pr[n],Ct[n];
    for(i=0;i<n;i++)
    Pr[i]=PR[i];
    int count=0,dec=0;
    j=0;
    int choice;
    printf("Option:\n1.Lowest number Highest priority.\n2.Lowest number Lowest priority.\n>>>");
    scanf("%d",&choice);
    
    printf("\nGantt chart:\n|");
    switch(choice)
    {
        case 1:
            while(j<n)
            {
                int min=1000,ind=-1;
                for(i=0;i<n;i++)
                {
                    if(Pr[i]==min)
                    {
                        if(Arr[i]<Arr[ind])
                        ind=i;
                    }
                    
                    else if(Pr[i]<min)
                    {
                        if(Arr[i]<=count)
                        {
                            min=Pr[i];
                            ind=i;
                        }
                    }
                    
                }
                if(ind!=-1)
                {
                    printf("%d-P%d-",count,(ind+1));
                    Ct[ind]=BT[ind]+count;
                    count+=BT[ind];
                    j++;
                    Pr[ind]=1001;
                    dec=0;
                }
                else
                {
                    if(dec==0)
                    printf("%d-Idle-",count);
                    count++;
                    dec=1;
                }
            }
        break;
        case 2:
            while(j<n)
            {
                int max=-1,ind=-1;
                for(i=0;i<n;i++)
                {
                    if(Pr[i]==max)
                    {
                        if(Arr[i]<Arr[ind])
                        ind=i;
                    }
                    
                    else if(Pr[i]>max)
                    {
                        if(Arr[i]<=count)
                        {
                            max=Pr[i];
                            ind=i;
                        }
                    }
                    
                }
                if(ind!=-1)
                {
                    printf("%d-P%d-",count,(ind+1));
                    Ct[ind]=BT[ind]+count;
                    count+=BT[ind];
                    j++;
                    Pr[ind]=-2;
                    dec=0;
                }
                else
                {
                    if(dec==0)
                    printf("%d-Idle-",count);
                    count++;
                    dec=1;
                }
            }
        break;
        default:
            printf("Wrong choice..\n");
        break;
    }
    
    printf("%d|\n",count);
    
    int TAT[n],WT[n];
    
    for(i=0;i<n;i++)
    TAT[i]=Ct[i]-Arr[i];
    
    for(i=0;i<n;i++)
    WT[i]=TAT[i]-BT[i];
    
    printf("\nProcess Table:\nPid\tPr\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),PR[i],Arr[i],BT[i],Ct[i],TAT[i],WT[i]);
    
    float sum=0;
    for(i=0;i<n;i++)
    sum+=(float)TAT[i];
    printf("\nAverage TAT: %f",sum/n);
    sum=0;
    for(i=0;i<n;i++)
    sum+=(float)WT[i];
    printf("\nAverage WT: %f",sum/n);
}

