#include<iostream>
using namespace std;

void findWaitingTime(int processes[], int n,
                          int bt[], int wt[])
{
    wt[0] = 0;

    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}

void findTurnAroundTime( int processes[], int n,
                  int bt[], int wt[], int tat[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);

    findTurnAroundTime(processes, n, bt, wt, tat);

    cout << "Processes  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n";

    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<endl;
    }

    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}


int main()
{
    int n;
    cout<<"Enter No of Process: ";
    cin>>n;
    cout<<"\nEnter Process ID and Burst Time: \n";
    int  burst_time[n];
    int processes[n];
    for(int i=0;i<n;i++){
        cin>>processes[i]>>burst_time[i];
    }
    findavgTime(processes, n,  burst_time);
    return 0;
}






/*
Time complexity O(N) and Space Complexity O(1)
Input And Output:
Enter No of Process: 3
Enter Process ID and Burst Time:
1 10
2 5
3 8
Processes  Burst time  Waiting time  Turn around time
 1        10     0         10
 2        5     10         15
 3        8     15         23
Average waiting time = 8.33333
Average turn around time = 16
*/
