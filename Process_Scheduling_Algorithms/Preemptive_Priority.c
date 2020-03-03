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
    int Bt[n],Ct[n],Rt[n],Pr[n];
    for(i=0;i<n;i++)
    Bt[i]=BT[i];
    for(i=0;i<n;i++)
    Pr[i]=PR[i];
    for(i=0;i<n;i++)
    Rt[i]=-1;
    int count=0,prev=-1,dec=0;
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
                    if(Pr[i]==min && Bt[i]>0)
                    {
                        if(Arr[i]<Arr[ind])
                        ind=i;
                    }
                    
                    else if(Pr[i]<min && Bt[i]>0)
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
                    Bt[ind]-=1;
                    if(ind!=prev)
                    printf("%d-P%d-",count,(ind+1));
                }
                else
                {
                    if(dec==0)
                    printf("%d-Idle-",count);
                    dec=1;
                }
                
                if(ind!=prev && Rt[ind]==-1)
                Rt[ind]=count-Arr[ind];
                
                count++;
                
                if(Bt[ind]==0 && ind!=-1)
                {
                    Ct[ind]=count;
                    j++;
                    dec=0;
                }
                prev=ind;
            }
        break;
        case 2:
            while(j<n)
            {
                int max=-10,ind=-1;
                for(i=0;i<n;i++)
                {
                    if(Pr[i]==max && Bt[i]>0)
                    {
                        if(Arr[i]<Arr[ind])
                        ind=i;
                    }
                    
                    else if(Pr[i]>max && Bt[i]>0)
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
                    Bt[ind]-=1;
                    if(ind!=prev)
                    printf("%d-P%d-",count,(ind+1));
                }
                else
                {
                    if(dec==0)
                    printf("%d-Idle-",count);
                    dec=1;
                }
                
                
                if(ind!=prev && Rt[ind]==-1)
                Rt[ind]=count-Arr[ind];
                
                count++;
                
                if(Bt[ind]==0 && ind!=-1)
                {
                    Ct[ind]=count;
                    j++;
                    dec=0;
                }
                prev=ind;
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
    sum=0;
    for(i=0;i<n;i++)
    sum+=(float)Rt[i];
    printf("\nAverage RT: %f",sum/n);
}

