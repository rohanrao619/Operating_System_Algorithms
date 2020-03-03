#include<stdio.h>

int main()
{
    int n;
    printf("Enter the no of jobs\n");
    scanf("%d",&n);

    int at[n],bt[n],ct[n],tat[n],wt[n];
    int i,j;

    printf("Enter the jobs with Arrival Time && burst time\n");
    printf("  AT  BT\n");
    for(i=0; i<n; i++)
    {
        printf("P%d-",i+1);
        scanf("%d %d",&at[i],&bt[i]);
    }

    int flag=0,time=0;
    float avgtat=0,avgwt=0;

    for(i=0; i<n; i++)
    {
        if(flag<at[i])
        {
            time=at[i]-flag;
        }

        flag=flag+bt[i]+time;
        time=0;
        ct[i]=flag;
        tat[i]=ct[i]-at[i];
        avgtat=avgtat+tat[i];
        wt[i]=tat[i]-bt[i];
        avgwt=avgwt+wt[i];
    }

    printf("Table\n");
    printf("  AT BT CT TAT WT\n");

    for(i=0; i<n; i++)
    {
        printf("P%d-%d %d %d %d %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("AVGTAT=%f  and AVGWT=%f",avgtat/n,avgwt/n);

    return 0;
}

