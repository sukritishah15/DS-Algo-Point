//Find minimum product subset in an array using Greedy method

//Sample I/O at the end

#include <bits/stdc++.h>
using namespace std;

int calculate(int a[], int n)
{
	if (n == 1)
		return a[0];

    // Find count of negative numbers, count
    // of zeros, maximum valued negative number,
    // minimum valued positive number and product
    // of non-zero numbers

	int max_neg = INT_MIN;
	int min_pos = INT_MAX;
	int count_neg = 0, count_zero = 0;
	int prod = 1;
	for (int i = 0; i < n; i++) {

        //Don't multiply by 0
		if (a[i] == 0) {
			count_zero++;
			continue;
		}

        // Count negatives and keep
        // track of maximum valued negative.
		if (a[i] < 0) {
			count_neg++;
			max_neg = max(max_neg, a[i]);
		}

        // Track minimum positive
        // number of array
		if (a[i] > 0)
			min_pos = min(min_pos, a[i]);

		prod = prod * a[i];
	}

    // If there are all zeros
    // or no negative number present
	if (count_zero == n ||
	(count_neg == 0 && count_zero > 0))
		return 0;

	// If all are positive
	if (count_neg == 0)
		return min_pos;

	// If there are even number of
    // negative numbers and count_neg not 0
	if (!(count_neg & 1) && count_neg != 0) {
        //divide by maximum valued negative
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

Time complexity = 0(n)
Space complexity = O(1)
*/
