//Fibonacci Series using Recursion 
#include<bits/stdc++.h> 
using namespace std; 

int fib(int n) 
{ 
	if (n <= 1) 
		return n; 
	return fib(n-1) + fib(n-2); 
} 

int main () 
{ 
	int n = 9; 
	cout << fib(n); 
	getchar(); 
	return 0; 
} 

/*
	Time Complexity: T(n) = T(n-1) + T(n-2) which is exponential
	Extra Space: O(n) if we consider the function call stack size, otherwise O(1).
------------------------------------------------------------------------------------------------	
	Given a number n, print n-th Fibonacci Number.
	Examples:
		Input  : n = 2
		Output : 1

		Input  : n = 9
		Output : 34
*/
