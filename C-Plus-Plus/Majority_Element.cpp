/*
Here the term Majority element means the frequency of array element has to be greater than N/2;
This can be easily done in O(n) space and O(n) time. But the Challenge is to do it in O(1) space & linear Time
For that we use Moore's Voting Algorithm where we select a candidate(the tricky part of the algorithm is selecting candidate element) & check its count
Base idea of the Moore's Voting technique is if each occurrence of an element a[i] can be cancelled with all the other elements that are different from a[i] then a[i] will exist till end if it is a majority element
Input:
    2
    5
    3 1 3 3 2
    3
    1 2 3
Output:
    3
    -1
The Overall time Complexity will be O(n) and space taken is O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int selectCandidate(vector<int>& a,int n);
int majorityElement(vector<int>& a,int n);
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(auto &i:a)cin>>i;
        cout<<majorityElement(a,n)<<endl; // returns -1 if there's no such element with count greater than n/2;
    }
}
int selectCandidate(vector<int>& a,int n){
    int index(0),frequency(1);
    for(int i=1;i<n;i++){
        if(a[index]==a[i]){
            frequency++;
        }
        else{
            frequency--;
        }
        if(!frequency){
            index=i;
            frequency=1;
        }
    }
    return a[index];
}
int majorityElement(vector<int>& a,int n){
    int requiredCandidate(selectCandidate(a,n));
    int count(0);
    for(auto &i:a){
        if(i==requiredCandidate)count++;
    }
    return (count>n/2) ? requiredCandidate:-1;
}
