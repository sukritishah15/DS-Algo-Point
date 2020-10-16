#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,WaitT[20],BurstT[20],TurnaroundT[20],j,key,Priority[20],ProcessID[20];
    float AverageTT,AvgWT,TotalWt=0,TotalTT=0;
    printf("enter the number of processes : ");
    scanf("%d",&n);
    printf("Assign the process and burst time\n");
    for(i=0;i<n;i++)
    {
        printf("the process id, burst time and priority for process");
        scanf("%d\t%d\t%d",&ProcessID[i],&BurstT[i],&Priority[i]);
    }
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        if(Priority[i]<Priority[j] )
        {
            key = Priority[i];
            Priority[i] = Priority[j];
            Priority[j] = key;
            key = BurstT[i];
            BurstT[i] = BurstT[j];
            BurstT[j] = key;
            key = ProcessID[i];
            ProcessID[i] = ProcessID[j];
            ProcessID[j] = key;

        }
    }
    printf("process_name\tburst_time\tpriority");
    for (i=0;i<n;i++)
    {
        printf("\n%3d\t%13d\t%13d",ProcessID[i],BurstT[i],Priority[i]);
    }
    WaitT[-1]=0;
    BurstT[-1]=0;
    WaitT[0]=0;
    TurnaroundT[0]=BurstT[0];
    for(i=0;i<n;i++)
    {
        WaitT[i]=WaitT[i-1]+BurstT[i-1];
        printf("\nwaiting time for process %d = %d \n",i,WaitT[i]);
        TurnaroundT[i]=WaitT[i]+BurstT[i];
        printf("turnout time for process %d = %d \n",i,TurnaroundT[i]);
    }
    for(i=0;i<n;i++)
    {
        TotalWt = TotalWt + WaitT[i];
        TotalTT = TotalTT + TurnaroundT[i];
    }
    AvgWT = TotalWt/n;
    AverageTT = TotalTT/n;
    for(i=0;i<n;i++)
    {
        printf("program of burst time %d %d %d\n",BurstT[i],WaitT[i],TurnaroundT[i]);
    }
    printf("the average of waiting time is %f and turnout time is %f \n",AvgWT,AverageTT);
    return 0;
}
/*SAMPLE INPUT :

enter the number of processes : 5
Assign the process and burst time
the process id, burst time and priority for process1 10 3
the process id, burst time and priority for process2 1  1
the process id, burst time and priority for process3 2  4
the process id, burst time and priority for process4 1  5
the process id, burst time and priority for process5 5  2

SAMPLE OUTPUT :

process_name    burst_time      priority
  2                 1               1
  5                 5               2
  1                10               3
  3                 2               4
  4                 1               5
waiting time for process 0 = 0
turnout time for process 0 = 1

waiting time for process 1 = 1
turnout time for process 1 = 6

waiting time for process 2 = 6
turnout time for process 2 = 16

waiting time for process 3 = 16
turnout time for process 3 = 18

waiting time for process 4 = 18
turnout time for process 4 = 19
program of burst time 1 0 1
program of burst time 5 1 6
program of burst time 10 6 16
program of burst time 2 16 18
program of burst time 1 18 19
the average of waiting time is 8.200000 and turnout time is 12.000000

TIME COMPLEXITY : O(n^2)
SPACE COMPLEXITY : O(n)
*/
