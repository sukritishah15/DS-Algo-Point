// A C++ program to implement flood fill algorithm 
#include<iostream> 
using namespace std; 

#define M 8 
#define N 8 


void floodFillUtil(int screen[][N], int row, int col, int oldColor, int newColor) 
{ 
	
	if (row < 0 || row >= M || col < 0 || col >= N) 
		return; 
	if (screen[row][col] != oldColor) 
		return; 
	if (screen[row][col] == newColor) 
		return; 

	screen[row][col] = newColor; 

	floodFillUtil(screen, row+1, col, oldColor, newColor); 
	floodFillUtil(screen, row-1, col, oldColor, newColor); 
	floodFillUtil(screen, row, col+1, oldColor, newColor); 
	floodFillUtil(screen, row, col-1, oldColor, newColor); 
} 


void floodFill(int screen[][N], int row, int col, int newColor) 
{ 
	int oldColor = screen[row][col]; 
	floodFillUtil(screen, row, col, oldColor, newColor); 
} 

int main() 
{ 
	int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1}, 
					{1, 1, 1, 1, 1, 1, 0, 0}, 
					{1, 0, 0, 1, 1, 0, 1, 1}, 
					{1, 2, 2, 2, 2, 0, 1, 0}, 
					{1, 1, 1, 2, 2, 0, 1, 0}, 
					{1, 1, 1, 2, 2, 2, 2, 0}, 
					{1, 1, 1, 1, 1, 2, 1, 1}, 
					{1, 1, 1, 1, 1, 2, 2, 1}, 
					}; 
	
	int row = 4, col = 4, newColor = 3; 
	floodFill(screen, row, col, newColor); 

	cout << "After Applying floodFill : \n"; 
	for (int i=0; i<M; i++) 
	{ 
		for (int j=0; j<N; j++) 
		cout << screen[i][j] << " "; 
		cout << endl; 
	} 

  return 0;
} 

/*

Sample I/O :- 

Screen :- 

1 1 1 1 1 1 1 1
1 1 1 1 1 1 0 0 
1 0 0 1 1 0 1 1 
1 2 2 2 2 0 1 0 
1 1 1 2 2 0 1 0 
1 1 1 2 2 2 2 0 
1 1 1 1 1 2 1 1 
1 1 1 1 1 2 2 1

row = 4
col = 4
newColor = 3


Output :- 

After Applying floodFill : 
1 1 1 1 1 1 1 1 
1 1 1 1 1 1 0 0 
1 0 0 1 1 0 1 1 
1 3 3 3 3 0 1 0 
1 1 1 3 3 0 1 0 
1 1 1 3 3 3 3 0 
1 1 1 1 1 3 1 1 
1 1 1 1 1 3 3 1 

*/
