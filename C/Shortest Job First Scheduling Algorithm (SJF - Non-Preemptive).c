#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*
    i = variable used in the for loop
    n = the number of processes
    wt = waiting time
    bt = burst time / execution time
    tt = turnaround time
    j = variable used in the for loop
    key = swapping variable
    */
    int i,n,wt[20],bt[20],tt[20],j,key;
    float avgtt,avgwt,TotWt=0,TotTt=0;
    printf("enter the number of processes : "); // input number of processes
    scanf("%d",&n);
    printf("Assign the process and burst time\n"); 
    for(i=0;i<n;i++)
    {
        printf("the burst time for process %d = ",i); // input burst time
        scanf("%d",&bt[i]);

    }
    for (i=1;i<=n-1;i++)  
    {
        j=i;
        while (j>0 && bt[j-1]>bt[j])  // sort the processes in ascending order
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
        printf("program with burst time %d\n",bt[i]); // print the sorted processes
    }
    wt[-1]=0;
    bt[-1]=0;
    wt[0]=0;
    tt[0]=bt[0];
    for(i=0;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];// calculating the waiting time of each process
        printf("waiting time for process %d = %d \n",i,wt[i]); // printing the waiting time
        tt[i]=wt[i]+bt[i]; // calculating the turnaround time of each process
        printf("turnout time for process %d = %d \n",i,tt[i]); // printing the turnaround time
    }
	/*
    TotWt = total waiting time
    TotTt = total turnaround time
    */
    for(i=0;i<n;i++)
    {
        TotWt = TotWt + wt[i]; // calculating the total waiting time
        TotTt = TotTt + tt[i]; // calculating the total turnaround time
    }
	/*
    avgtt = average turnaround time
    avgwt = average waiting time
    */
    avgwt = TotWt/n; // calculating the average of total waiting time
    avgtt = TotTt/n; // calculating the average of total turnaround time
    for(i=0;i<n;i++)
    {
        printf("program of burst time %d %d %d\n",bt[i],wt[i],tt[i]); // print the burst time, waiting time & turnaround time pf each process
    }
    printf("the average of waiting time is %f and turnout time is %f \n",avgwt,avgtt); // print the calculated the average of waiting time and turnaround time
    return 0;
}

/*SAMPLE INPUT :

enter the number of processes : 4
Assign the process and burst time
the burst time for process 0 = 10
the burst time for process 1 = 2
the burst time for process 2 = 3
the burst time for process 3 = 5

SAMPLE OUTPUT :

Sorted list in ascending order:
program with burst time 2
program with burst time 3
program with burst time 5
program with burst time 10
waiting time for process 0 = 0
turnout time for process 0 = 2
waiting time for process 1 = 2
turnout time for process 1 = 5
waiting time for process 2 = 5
turnout time for process 2 = 10
waiting time for process 3 = 10
turnout time for process 3 = 20
program of burst time 2 0 2
program of burst time 3 2 5
program of burst time 5 5 10
program of burst time 10 10 20
the average of waiting time is 4.250000 and turnout time is 9.250000

time complexity : O(n^2)

space complexity : O(n)
*/
