//This code is solely written by Arnav without any external sources.
// Pancake sort
#include<bits/stdc++.h>
using namespace std; 

void flip(int arr[] , int i){


	for(int j = 0 ; j <= (i / 2) ; j++)
	{
		int temp = arr[i-j] ; 
		arr[i-j] = arr[j] ; 
		arr[j] = temp ; 
	}
}
// time complexity = O(n) ; Space complexity = O(1) 


void sort(int arr[] , int n){
	int curr_size = n ; 
	while(curr_size > 0)
	{
		int max_index = max_element(arr , arr + curr_size) - arr; // time complexity = O(n) ; space complexity = O(1);
		if(max_index !=curr_size -1)
		{
		flip(arr, max_index); 
		flip(arr, curr_size -1) ;}
		curr_size-- ; 
		
	}
}

//time complexity = O(n * max(p, q)) where p is the time complexity of flip() and q is the complexity of max_element(); space complexity = O(1)

int main()
{

	int n ; cin >> n ; 
	int a[n] ; 
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> a[i] ; 
	}


	sort(a , n); 
	for(int i = 0 ; i < n ; i ++)
	{
		cout << a[i] << " " ; 
	}


}
/* here n is the number of elements in the array to be sorted and a[0...n-1] is the array.

input example:
5
5 4 3 2 1 
Output:
1 2 3 4 5

Overall time complexity = O(n*n) ; Overall Space complexity = O(1) */





