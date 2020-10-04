// Pigeonhole Sort in C++
#include<bits/stdc++.h>
using namespace std; 

void pigeonhole_sort(int arr[], int n) 
{ 
    int minn = *min_element(arr, arr+ n) ; 
    int maks = *max_element(arr, arr+ n) ; 

    int range = maks - minn + 1; 

    vector<int> holes[range]; 
  
    for (int i = 0; i < n; i++) 
        holes[arr[i]-minn].push_back(arr[i]); 

    int j = 0;  
    for (int i = 0; i < range; i++) 
    { 
        for(int k = 0 ; k < holes[i].size() ; k++)
        {
            arr[j] = holes[i][k] ; 
            j++ ; 
        }
    } 
} 
  
int main() 
{ 
    int n ; cin >> n ; 
    int a[n] ; 
    for(int i = 0 ; i < n ; i ++) cin >> a[i] ; 

    pigeonhole_sort(a , n) ;


    for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;  
} 

/* here n is the number of elements in the array to be sorted and a[0...n-1] is the array.

input example:
5
5 4 3 2 1 
Output:
1 2 3 4 5


Length of the range of possible key values = N; number of elements in the array =n;
Overall time complexity = O(n+N) ; Overall Space complexity = O(N) */





