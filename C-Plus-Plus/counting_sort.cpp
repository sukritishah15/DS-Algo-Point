//Counting Sort Algorithm from scratch
//This is a sorting technique based on keys between a specific range and works by counting the number of objects having distinct key values

#include<bits/stdc++.h>
using namespace std;

//Here, we're taking the range to be 0 to 9 (both included)
#define RANGE_MAX 9

vector<int> counting_sort(vector<int>& v1)
{
    vector<int> count(RANGE_MAX+1,0);

    //Storing count of each character
    for(int i=0; i<v1.size(); i++)
        count[v1[i]]++;

    //count[i] will contain the position of the character in the answer array
    for(int i=1; i<count.size(); i++)
        count[i]=count[i]+count[i-1];

    vector<int> answer(v1.size());

    //Building answer array
    for(int i=0; i<v1.size(); i++)
    {
        answer[count[v1[i]]-1]=v1[i];
        count[v1[i]]--;
    }
    
    return answer;

}

int main()
{
    //Taking Input from the user
    cout<<"Enter the number of elements you want to sort: ";
    int num;
    cin>>num;
    
    vector<int> v1(num);

    for(int i=0; i<num; i++)
        cin>>v1[i];

    //Printing before sorting
    cout<<"Printing the elements before sorting: ";
    for(int i=0; i<v1.size(); i++)
    {
        cout<<v1[i]<<" ";
    }

    //Applying counting sort
    vector<int> answer = counting_sort(v1);

    //Printing elements after sorting
    cout<<"Printing the elements after sorting: ";
    for(int i=0; i<answer.size(); i++)
    {
        cout<<answer[i]<<" ";
    }

    return 0;
}

/*
Sample Input 1:
6
9   0   6   6   4   5

Sample Output 1:
Printing the elements before sorting: 9  0   6   6   4   5
Printing the elements after sorting:  0  4   5   6   6   9


Sample Input 2:
6
1   0   6   1   4   5

Sample Output 1:
Printing the elements before sorting: 1  0   6   1   4   5
Printing the elements after sorting:  0  1   1   4   5   6
*/

/*
Time Complexity of this solution: O(num+RANGE_MAX)
Space Complexity of this solution: O(num+RANGE_MAX) 
*/