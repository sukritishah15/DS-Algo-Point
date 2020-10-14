#include<iostream>
#include<stdlib.h>

using namespace std;

void findWaitingTime(int p[], int n, int bt[], int wt[], int q)
{
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] =  bt[i];
    int t = 0;
    while (1)
    {
        bool done = true;
        for (int i = 0 ; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false;
                if (rem_bt[i] > q)
                {
                    t += q;
                    rem_bt[i] -= q;
                }
                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == true)
          break;
    }
}
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int p[], int n, int bt[], int q)
{
    int wt[20], tat[20], total_wt = 0, total_tat = 0;
    float Awt,Atat;
    findWaitingTime(p, n, bt, wt, q);
    findTurnAroundTime(p, n, bt, wt, tat);
    cout << "Processes\tBurst time\tWaiting time\tTurn around time" << endl;
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << i+1 << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] <<endl;
    }
    Awt = (float)total_wt / (float)n;
    Atat = (float)total_tat / (float)n;
    cout << "Average waiting time : " << Awt << endl << "Average turn around time : " << Atat;
}


int main()
{
    int q,n,i,p[20],bt[100];
    cout << "The time quantum : ";
    cin >> q;
    cout << "Enter the no. of processes : ";
    cin >> n;
    for(i=0;i<n;i++)
    {
        cout << "The process id, burst time : ";
        cin >> p[i] >> bt[i];
    }
    findavgTime(p, n, bt, q);
    return 0;
}
/*SAMPLE INPUT :

The time quantum : 1
Enter the no. of processes : 4
The process id, burst time : 1 6
The process id, burst time : 2 3
The process id, burst time : 3 1
The process id, burst time : 4 7

SAMPLE OUTPUT :

Processes       Burst time      Waiting time    Turn around time
1               6               9               15
2               3               6               9
3               1               2               3
4               7               10              17
Average waiting time : 6.75
Average turn around time : 11

TIME COMPLEXITY : O(n^2)
SPACE COMPLEXITY : O(n)
*/
