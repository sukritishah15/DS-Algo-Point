#include <iostream>
#include <vector>

/**
 * @brief ternary search on array a in range [l, r]
 * @param a sorted int array
 * @param l lower index of the range within a
 * @param r upper index of the range within a
 * @param x integer to find
 * @return -1 if not found else the index
 */
int ternary_search(int a[], int l, int r, int x)
{
    if (r < l)
        return -1;

    int mid1, mid2;
    mid1 = l + (r - l) / 3;
    mid2 = r - (r - l) / 3;

    if (a[mid1] == x)
        return mid1;
    if (a[mid2] == x)
        return mid2;

    if (x < a[mid1])
        return ternary_search(a, l, mid1 - 1, x);
    else if (x > a[mid2])
        return ternary_search(a, mid2 + 1, r, x);
    else
        return ternary_search(a, mid1 + 1, mid2 - 1, x);
}

/**
 * @brief ternary search on integer vector a in range [l, r]
 * @param a sorted int vector
 * @param l lower index of the range within a
 * @param r upper index of the range within a
 * @param x integer to find
 * @return -1 if not found else the index
 */
int ternary_search(const std::vector<int> &a, int l, int r, int x)
{
    if (r < l)
        return -1;

    int mid1, mid2;
    mid1 = l + (r - l) / 3;
    mid2 = r - (r - l) / 3;

    if (a[mid1] == x)
        return mid1;
    if (a[mid2] == x)
        return mid2;

    if (x < a[mid1])
        return ternary_search(a, l, mid1 - 1, x);
    else if (x > a[mid2])
        return ternary_search(a, mid2 + 1, r, x);
    else
        return ternary_search(a, mid1 + 1, mid2 - 1, x);
}

int main()
{
    int n;
    std::cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    // assuming the input is ascending order sorted

    int s;
    std::cin >> s;

    int find = ternary_search(a, 0, n - 1, s);

    if (find == -1)
        std::cout << s << " not found.\n";
    else
        std::cout << s << " found at index " << find << ".\n";

    return 0;
}

/*
Time complexity: O(log_3 n)
Space complexity: O(n)

User is required to enter the size of array 'n'.
Then user enters n numbers which are ascending sorted.
Then user enters a number s to search in the array.
User gets output according to that.

Input:
5
1 4 6 9 10
6
Output:
6 found at index 2.

Input:
5
1 4 6 9 10
5
Output:
5 not found.
*/