#include<iostream>

using namespace std;

int interpolationSearch(int array[], int start, int end, int key) {

    int dist, valRange, indexRange, est;

    float fraction;

    while(start <= end && key >= array[start] && key <= array[end]) {

        dist = key - array[start];
        valRange = array[end] - array[start];
        fraction = dist / valRange;
        indexRange = end - start;
        est = start + (fraction * indexRange);

        if(array[est] == key) {
            return est;
        }
        if(array[est] < key) {
            start = est + 1;
        } else {
            end = est - 1;
        }
    }
    return -1;
}

// INTERPOLATION SEARCH

int main() {
    int n;
    cout << "Enter the number of elements:";
    cin >> n;

    int arr[n];
    cout << "Enter elements:" << endl;
    for(int i = 0; i< n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter element that has to be searched:";
    cin >> key;
    int index = interpolationSearch(arr, 0, n-1, key);

    if(index >= 0) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}

/*
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Sample input 1:
 * Enter the number of elements:15
 * Enter elements:
 * 10 12 13 16 18 19 20 21 22 23 24 33 35 42 47
 * Enter element that has to be searched:13
 *
 * Output:
 * Element found at index 2
 *
 *
 * Sample input 2:
 * Enter the number of elements:15
 * Enter elements:
 * 10 12 13 16 18 19 20 21 22 23 24 33 35 42 47
 * Enter element that has to be searched:15
 *
 * Output:
 * Element not found.
 */
