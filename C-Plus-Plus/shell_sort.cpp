#include <bits/stdc++.h>

using namespace std;

void shellSort(int n, vector<int> arr) {
    for (int dif = n/2; dif > 0; dif /= 2) {
        for (int i = dif; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= dif && arr[j - dif] > temp; j -= dif) {
                arr[j] = arr[j - dif];
            }
            arr[j] = temp;
        }
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    
}

int main() {
    int n;
    cout << "Enter the number of elements in array:";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    shellSort(n, arr);
    
    return 0;
}

/*
 * Sample input:
 * Enter the number of elements in array:5
 * Enter the elements:
 * 12 34 54 2 3
 * Output:
 * Sorted array: 2 3 12 34 54
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */

