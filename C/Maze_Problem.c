#include <stdio.h> 

// N = size of the Maze
#define N 4 

bool solveMazeUtil( int maze[N][N], int x, int y, int sol[N][N]); 

// A function to print the solution matrix
void printSolution(int sol[N][N]) 
{ 
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) 
			printf(" %d ", sol[i][j]); 
		printf("\n"); 
	} 
} 

// A function to check if (x,y) is valid
bool isSafe(int maze[N][N], int x, int y) 
{ 
	// if (x, y outside maze) return false 
	if ( x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) 
		return true; 

	return false; 
} 

// finding one of the feasible solutions using backtracking
bool solveMaze(int maze[N][N]) 
{ 
	int sol[N][N] = {   { 0, 0, 0, 0 }, 
					    { 0, 0, 0, 0 }, 
					    { 0, 0, 0, 0 }, 
					    { 0, 0, 0, 0 } 
                    }; 

	if (solveMazeUtil( maze, 0, 0, sol) == false) { 
		printf("Solution doesn't exist !!!"); 
		return false; 
	} 

	printSolution(sol); 
	return true; 
} 

// A recursive function to solve the Maze problem
bool solveMazeUtil( int maze[N][N], int x, int y, int sol[N][N]) 
{ 
	// if (x, y is goal) return true 
	if ( x == N - 1 && y == N - 1 && maze[x][y] == 1) { 
		sol[x][y] = 1; 
		return true; 
	} 

	if (isSafe(maze, x, y) == true) { 

		// Mark x, y as part of solution path 
		sol[x][y] = 1; 

		// Move forward in x direction 
		if (solveMazeUtil( maze, x + 1, y, sol) == true) 
			return true; 

		// Else move down in y direction 
		if (solveMazeUtil( maze, x, y + 1, sol) == true) 
			return true; 

		// Unmark (x,y) as part of the solution path
		sol[x][y] = 0; 
		return false; 
	} 

	return false; 
} 

// driver function
int main() 
{ 
	int maze[N][N] = {  { 1, 0, 0, 0 }, 
					    { 1, 1, 0, 1 }, 
					    { 0, 1, 0, 0 }, 
					    { 1, 1, 1, 1 } 
                    }; 

	solveMaze(maze); 
	return 0; 
} 


/*

Sample Input 1 :
{   { 1, 0, 0, 0 }, 
	{ 1, 1, 0, 1 }, 
	{ 0, 1, 0, 0 }, 
	{ 1, 1, 1, 1 } 
}

Sample Output 1 : 
 1  0  0  0 
 1  1  0  0 
 0  1  0  0 
 0  1  1  1 


Time Complexity = O(2^(n^2))
Space Complexity = O(n^2)

*/
