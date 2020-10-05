//Two Pointer Algorithm From Scratch in C++

/*
Two Pointer Algorithm is an effective technique which is used for searching pairs in a sorted array.
This technique can be used to solve a number of problems, however the following code demonstrates how to use it to solve the following question:

Question: Given an array A having N integers, sorted in ascending order, return true if there is any pair of element (A[i],A[j]) such that the sum equals K. 
*/

#include<bits/stdc++.h>
using namespace std;

bool two_pointer_algo(int* A, int N, int K)
{
    int start = 0;
    int end = N-1;

    //We will start from the sum of extreme values i.e. start and end of array (as array is sorted) and move both variables conditionally
    while(start<end)
    {
        //if sum=K, then a pair exists, thus return true
        if(A[start]+A[end]==K)
            return true;
        
        //if sum<K, then we will increase the start variable to increase our sum
        else if(A[start]+A[end]<K)
            start++;

        //if sum>K, we will decrease the end variable to decrease our sum
        else
            end--;
    }

    return false;
}

int main()
{
    //Taking inputs from the user
    cout<<"Enter the Size of Array(N):";
    int N;
    cin>>N;

    int* A = new int[N];

    cout<<"Enter the elements of the Array:"<<endl;
    
    for(int i=0; i<N; i++)
        cin>>A[i];

    cout<<"Enter the value for which you want to check if a pair with that sum exists or not: ";
    int K;
    cin>>K;

    //IF a pair exists, if part will get executed
    //ELSE, else part will get executed
    if(two_pointer_algo(A,N,K))
        cout<<"Yes, there exists a pair in the array with sum equal to "<<K<<endl;
    else
        cout<<"No pair exists in the array with sum equal to "<<K<<endl;
    return 0;
}

/*
Space Complexity for this problem: O(1)
Time Complexity for this problem: O(N)
*/

/*
Sample Input 1:
5
1   2   3   4   5
8

Output 1:
Yes, there exists a pair in the array with sum equal to 8


Sample Input 2:
5
1   2   3   4   5
10

Output 2:
No pair exists in the array with sum equal to 10
*/


/*
Other Problems that can be solved using Two Pointer Technique are:

1. 3 Sum Problem
2. Intersection of Sorted Arrays
3. Remove Duplicates from Array
4. Container with most Water

*/