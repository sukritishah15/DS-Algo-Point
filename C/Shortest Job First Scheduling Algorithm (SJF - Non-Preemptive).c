#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,wt[20],bt[20],tt[20],j,key;
    float avgtt,avgwt,TotWt=0,TotTt=0;
    printf("enter the number of processes : ");
    scanf("%d",&n);
    printf("Assign the process and burst time\n");
    for(i=0;i<n;i++)
    {
        printf("the burst time for process %d = ",i);
        scanf("%d",&bt[i]);

    }
    for (i=1;i<=n-1;i++)
    {
        j=i;
        while (j>0 && bt[j-1]>bt[j])
        {
            key = bt[j];
            bt[j] = bt[j-1];
            bt[j-1] = key;
            j=j-1;
        }
    }
    printf("Sorted list in ascending order:\n");
    for (i=0;i<=n-1;i++)
    {
        printf("program with burst time %d\n",bt[i]);
    }
    wt[-1]=0;
    bt[-1]=0;
    wt[0]=0;
    tt[0]=bt[0];
    for(i=0;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        printf("waiting time for process %d = %d \n",i,wt[i]);
        tt[i]=wt[i]+bt[i];
        printf("turnout time for process %d = %d \n",i,tt[i]);
    }
    for(i=0;i<n;i++)
    {
        TotWt = TotWt + wt[i];
        TotTt = TotTt + tt[i];
    }
    avgwt = TotWt/n;
    avgtt = TotTt/n;
    for(i=0;i<n;i++)
    {
        printf("program of burst time %d %d %d\n",bt[i],wt[i],tt[i]);
    }
    printf("the average of waiting time is %f and turnout time is %f \n",avgwt,avgtt);
    return 0;
}
