/* 
 *
 * Topic: Mean and Median calculation
 * Language: C++
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
 *
 * Mean of an array = (sum of all elements) / (number of elements)
 * 
 * Time complexity: O(n)
 * 
 */
int find_mean(int arr[], int n)
{
    int sum = 0;
    for (auto i = 0; i < n; i++)
        sum += arr[i];
    return sum / n;
}

/*
 *
 * Median of a sorted array of size n is defined as the middle element
 * when n is odd and average of middle two elements when n is even.
 * 
 * Time Complexity: O(nlogn)
 * 
 */
int find_median(int arr[], int n)
{
    if (n == 0)
        return -1;
    sort(arr, arr + n);
    return n % 2 == 0 ? (arr[n / 2 - 1] + arr[n / 2]) / 2 : arr[n / 2];
}

int main()
{
    // Size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "\nEnter the array elements: ";
    for (auto i = 0; i < n; i++)
        cin >> arr[i];

    int mean = find_mean(arr, n);
    int median = find_median(arr, n);

    cout << "\nMean of the array is: " << mean;
    cout << "\nMedian of the array is: " << median;
    return 0;
}

/*
 *
 * Input:
 * Enter the size of the array: 6
 * Enter the array elements: 22 18 11 14 20 11
 * 
 * Output:
 * Mean of the array is: 16
 * Median of the array is: 16
 * 
 */

