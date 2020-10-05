//TSP implementation in C++
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Constant denoting number of cities
const int N = 4; 

int TSP(int n,int start,int graph[N][N]){
    int min_cost;
    int arr[n-1];
    int path[n-1];
    
    //This is a brute force approach
    //We're creating an aray of all cities expect start city
    //We're then finding different permutations 
    //For each permutation we check if the path has min cost
    //We do this for all possible permutations and finally get minimum cost path
    
    for(int i=1;i<n;i++){
        arr[i-1] = i;    
    }
    
    int flag=0;
    do{
        int current_cost = 0;
        for(int i=0;i<n-1;i++){
            current_cost+=graph[start][arr[i]];
            start = arr[i];
        }
        //This is to consider the edge from the last city to start city
        current_cost+=graph[start][0];
        
        if(min_cost>current_cost || flag==0){
            min_cost = current_cost;
            for(int i=0;i<n-1;i++){
                path[i] = arr[i];
            }
        }
        flag = 1;
    }while(next_permutation(arr, arr+n-1));
    
        cout<<"The min cost path is:";
        cout<<"0-->";
        for(int i=0;i<n-1;i++){
                cout<<path[i]<<"-->";
            }
            cout<<"\n";
    
    return min_cost;    
}

int main() {
    
    int graph[N][N];
    
    cout<<"Enter the cost matrix:"<<"\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>graph[i][j]; 
        }
    }
	
	//Assumed city 0 to always be the starting point.
	cout<<"The shortest path is:"<<TSP(N,0,graph)<<"\n";
	
	return 0;
}

/*
Travelling Salesman Problem (TSP) is an NP Hard problem.There is set of cities with some distance between each
of them, the task is to find the shortest path where every city is visted exactly once and we return back to the
starting city.There are many approaches like Branch and Bound, Backtracking etc.In this solution the brute force
approach is used.

Time complexity : O(n!)
Space complexity : O(n2)

Sample I/O:
Enter the cost matrix:
0
10
15
20
10
0
35
25
15
35
0
30
20
25
30
0

The min cost path is:0-->2-->1-->3-->
The shortest path is:80
*/
