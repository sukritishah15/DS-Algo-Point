#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Process
	{
	    int priority;
	    int bt;
	};
  //to sort the process on the basis of priority
bool compare(Process a, Process b) {
   return (a.priority > b.priority);
}

int main() {
    int n;
	cout<<"Enter number of processes required"<<"\n";
	cin>>n;
	struct Process p[n];
	int wt[n],tat[n];
	for(int i=0;i<n;i++)
	{
	    cout<<"enter priority number of process "<<i+1<<"\n";
	    cin>>p[i].priority;
	    cout<<"enter burst time of process "<<i+1<<"\n";
	    cin>>p[i].bt;
	}
	sort(p, p + n, compare);
	int avg_w=0,avg_t=0;
	for(int i=0;i<n;i++)
	{ 
  //when simultaneous arrival time of all processes is 0
  if(i==0)
	    {
	    wt[0]=0;
	    tat[0]=p[i].bt;
	    avg_w+=wt[0];
	    avg_t+=tat[0];
	    continue;
	    }
	    else{
	    wt[i]=tat[i-1];
	    tat[i]=wt[i]+p[i].bt;
	    avg_w+=wt[i];
	    avg_t+=tat[i];
	     }
	}
	cout<<"priority  "<<"B.T  "<<"W.T  "<<"T.A.T  "<<"\n";
	for(int i=0;i<n;i++)
	{
	    cout<<p[i].priority<<"\t\t"<<p[i].bt<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
	    cout<<"\n";
	}
	cout << "Average waiting time = "<< (float)avg_w / (float)n<<"\n";
    cout << "\nAverage turn around time = "<< (float)avg_t / (float)n<<"\n";
	return 0;
}

/*
problem:priority-based Scheduling (non-preemptive)
sample I/O
enter number of processes required : 5
enter priority number of process 1 : 4
enter burst time of process 1 : 2
enter priority number of process 2 : 3
enter burst time of process 2 : 8
enter priority number of process 3 : 1
enter burst time of process 3 : 4
enter priority number of process 4 : 6
enter burst time of process 4 : 10
enter priority number of process 5 : 5
enter burst time of process 5 : 9
priority  B.T  W.T  T.A.T  
6	 10	0	10
5	 9	10   19
4	 2	19   21
3	 8	21   29
1	 4	29   33
Average waiting time = 15.8
Average turn around time = 22.4

space-complexity:O(1)
time-complexity:O(n^n)   (worst)
*/
