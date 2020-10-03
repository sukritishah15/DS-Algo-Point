#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,W;
    cin>>n>>W;
    int value[n],weight[n];

    for(int i=0;i<n;i++){
        cin>>value[i];
    }

    for(int i=0;i<n;i++){
        cin>>weight[i];
    }

    int dp[n+1][W+1];
    //initialize dp to base case
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==j){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            //if weight of the item is less or equal to weight of knapsack
            if(weight[i] <= j){
                //choose maximum profitable item
                dp[i][j] = max((value[i]+dp[i-1][j-weight[i]]),dp[i-1][j]);
            }
            //if weight of the iteam is not less then or equal to weight of knapsack we consider on other item.//
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    //print maximum profit
    cout<<dp[n][W]<<endl;
}
/*
Consider an example of a thief who wants to steal jewelry from a jewelry shop but he has a constraint with the bag he carries which can only 
hold some specific weight. Help him picking up the jewelry such that he gets maximum profit without violating the bag's constraint.

Time complexity : O(n*W)
space compexity : O(n*W)
For example-

Input-
n = 3(no. of item)
W = 50 (weight of knapsack)
value[] = {60,100,120}
weight[] = {10,20,30}

Output-
Profit = 220
*/