//Find minimum product subset in an array using Greedy method

//Sample I/O at the end

#include <bits/stdc++.h>
using namespace std;

int calculate(int a[], int n)
{
	if (n == 1)
		return a[0];

	int max_neg = INT_MIN;
	int min_pos = INT_MAX;
	int count_neg = 0, count_zero = 0;
	int prod = 1;
	for (int i = 0; i < n; i++) {


		if (a[i] == 0) {
			count_zero++;
			continue;
		}

		if (a[i] < 0) {
			count_neg++;
			max_neg = max(max_neg, a[i]);
		}

		if (a[i] > 0)
			min_pos = min(min_pos, a[i]);

		prod = prod * a[i];
	}

	if (count_zero == n ||
	(count_neg == 0 && count_zero > 0))
		return 0;

	if (count_neg == 0)
		return min_pos;

	if (!(count_neg & 1) && count_neg != 0) {
		prod = prod / max_neg;
	}

	return prod;
}

int main()
{
	int n;
	cout<<"Enter size of array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter array elements: ";
	for(int i=0;i<n;i++)
	    cin>>a[i];
	cout << "\nAnswer: "<<calculate(a, n);
	return 0;
}

/*
Input : n=5 a[5]={ -1, -1, -2, 4, 3 }
Output : -24

Time complexity = 0(N)
Space complexity = O(1)
*/
