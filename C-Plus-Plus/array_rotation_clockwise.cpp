#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  int n,d;
  cin>>n>>d;
  d%=n;
  int arr[n],temp[d];
  for(int i=0;i<n;i++){
  	if(i<d){
  		cin>>temp[i];
  		continue;
  	}
    cin>>arr[i-d];
  }

  for(int i=0;i<d;i++){
  	arr[i+n-d]=temp[i];
  }


  for(int i=0;i<n;i++){
  	cout<<arr[i]<<' ';
  }


  return 0;
}
/*
rotate array clockwise by specific number 

Implimentation:
  taking input of elemnets to be roated in to seprate array
  shifting from second array to main array 

Input:
  n: number of elements d:number of elements to be rotated
  n number of integers		

output:
  rotated array

Sample Input-Output:
  Input1:
	5 2
	1 2 3 4 5
  Output1:
  	3 4 5 1 2

  Input2:
    5 5
    1 2 3 4 5
  Output2:
	  1 2 3 4 5

Time Complexity= O(n)
space Complexity= O(n+d)

Contributed by : Hitansh K Doshi(github id: Hitansh159)
*/