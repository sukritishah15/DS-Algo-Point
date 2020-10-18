/**
 * 2D Binary Indexed Tree = 2D Fenwick Tree
 */
#include <bits/stdc++.h>
using namespace std;

//Variables
const int MAX_X = 1001;
const int MAX_Y = 1001;
int bit[MAX_X][MAX_Y];

/**
 * Updates binary indexed tree by a value
 * Time complexity: O(log((MAX_X)(MAX_Y)))
 * @param indexX = x index to update
 * @param indexY = y index to update
 * @param value = value to update by
 */
void update(int indexX, int indexY, int value) {
    for (int i = indexX; i < MAX_X; i += (i & -i)) {
        for (int j = indexY; j < MAX_Y; j += (j & -j)) {
            bit[i][j] += value;
        }
    }
}

/**
 * Queries sum to index
 * Time complexity: O(log((MAX_X)(MAX_Y)))
 * @param indexX = x index to query to
 * @param indexY = y index to query to
 * @return query to index
 */
int query(int indexX, int indexY) {
    int answer = 0;
    for (int i = indexX; i > 0; i -= (i & -i)) {
        for (int j = indexY; j > 0; j -= (j & -j)) {
            answer += bit[i][j];
        }
    }
    return answer;
}

/**
 * Queries inclusive sum of two sets of indices
 * @param indexX1 = lowerbound x index
 * @param indexY1 = lowerbound y index
 * @param indexX2 = upperbound x index
 * @param indexY2 = upperbound y index
 * @return query of the inclusive sum of the two sets of indices
 */
int query(int indexX1, int indexY1, int indexX2, int indexY2) {
    return (query(indexX2, indexY2) + query(indexX1 - 1, indexY1 - 1) - query(indexX1 - 1, indexY2) - query(indexX2, indexY1 - 1));
}

/**
 * Prints array
 * @param X = upperbound X value
 * @param Y = upperbound Y value
 */
void printA(int X, int Y) {
    cout<<"\n";
    for (int i = 1; i <= X; i++) {
        for (int j = 1; j <= Y; j++) {
            cout<<query(i, j, i, j)<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int main() {
    int X, Y; //must be less than MAX_X, MAX_Y, respectively
    int n;
    cin>>X>>Y;

    //Build 2D binary indexed tree
    for (int i = 1; i <= X; i++) {
        for (int j = 1; j <= Y; j++) {
            cin>>n;
            update(i, j, n);
        }
    }

    //Do stuff with binary indexed tree
    int operation; //-1 = end, 0 = print, 1 = update, 2 = query
    int index_X1, index_Y1, index_X2, index_Y2, value;
    while (true) {
        cin>>operation;
        if (operation == -1) {
            return 0;
        }
        else if (operation == 0) {
            printA(X, Y);
        }
        else if (operation == 1) {
            cin>>index_X1>>index_Y1>>value;
            update(index_X1, index_Y1, value);
        }
        else if (operation == 2) {
            cin>>index_X1>>index_Y1>>index_X2>>index_Y2;
            cout<<query(index_X1, index_Y1, index_X2, index_Y2)<<"\n";
        }
        else {
            cout<<"Invalid operation."<<"\n";
            continue;
        }
    }
    return 0;
}
/*
Sample input:
5 6
3 1 4 1 5 9
2 7 1 8 2 8
6 0 2 2 1 4
1 4 1 4 2 1
1 7 3 2 0 5


Operations:
2
1 1 3 3
1
5 4 7
0
1
1 1 5
2
2 3 4 5
1
5 6 -3
2
1 3 5 6
2
3 3 4 4
0
-1


Output:
26

3 1 4 1 5 9
2 7 1 8 2 8
6 0 2 2 1 4
1 4 1 4 2 1
1 7 3 9 0 5

23
69
9

8 1 4 1 5 9
2 7 1 8 2 8
6 0 2 2 1 4
1 4 1 4 2 1
1 7 3 9 0 2

*/
