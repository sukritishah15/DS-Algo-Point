#include<iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int i,n,WaitT[20],BurstT[20],TurnaroundT[20],j,key;
    float AverageTT,AverageWT,TotalWT=0,TotalTT=0;
    cout << "Enter the number of processes : ";
    cin >> n;
    for(i=0;i<n;i++)
    {
        cout << "The burst time for process " << i << " = ";
        cin >> BurstT[i];
    }
    for (i=1;i<=n-1;i++)
    {
        j=i;
        while (j>0 && BurstT[j-1]>BurstT[j])
        {
            key = BurstT[j];
            BurstT[j] = BurstT[j-1];
            BurstT[j-1] = key;
            j=j-1;
        }
    }
    cout << "Sorted list in ascending order : " << endl;
    for (i=0;i<=n-1;i++)
    {
        cout << "Program with burst time " << BurstT[i] << endl;
    }
    WaitT[-1]=0;
    BurstT[-1]=0;
    WaitT[0]=0;
    TurnaroundT[0]=BurstT[0];
    for(i=0;i<n;i++)
    {
        WaitT[i]=WaitT[i-1]+BurstT[i-1];
        cout << "Waiting time for process " << i << " = " << WaitT[i] <<endl;
        TurnaroundT[i]=WaitT[i]+BurstT[i];
        cout << "Turnaround time for process " << i << " = " << TurnaroundT[i] << endl;
    }
    for(i=0;i<n;i++)
    {
        TotalWT = TotalWT + WaitT[i];
        TotalTT = TotalTT + TurnaroundT[i];
    }
    AverageWT = TotalWT/n;
    AverageTT = TotalTT/n;
    cout << "\t\t\t" << "burst time " <<" Waiting time " << " turnaround time" <<endl;
    for(i=0;i<n;i++)
    {
        cout << "Program of burst time " <<"\t  "<< BurstT[i] << "\t\t" << WaitT[i] << "\t\t" << TurnaroundT[i] <<endl;
    }
    cout << "The average OF waiting time is " << AverageWT << "and turnaround time is " << AverageTT <<endl;
    return 0;
}
/*SAMPLE INPUT :

Enter the number of processes : 4
The burst time for process 0 = 10
The burst time for process 1 = 2
The burst time for process 2 = 3
The burst time for process 3 = 5

SAMPLE OUTPUT :

Sorted list in ascending order :
Program with burst time 2
Program with burst time 3
Program with burst time 5
Program with burst time 10
Waiting time for process 0 = 0
Turnaround time for process 0 = 2
Waiting time for process 1 = 2
Turnaround time for process 1 = 5
Waiting time for process 2 = 5
Turnaround time for process 2 = 10
Waiting time for process 3 = 10
Turnaround time for process 3 = 20
                        burst time  Waiting time  turnaround time
Program of burst time     2             0               2
Program of burst time     3             2               5
Program of burst time     5             5               10
Program of burst time     10            10              20
The average OF waiting time is 4.25and turnaround time is 9.25

TIME COMPLEXITY : O(n^2)
SPACE COMPLEXITY : O(n)
*/
