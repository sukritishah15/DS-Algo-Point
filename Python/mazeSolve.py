#This Code Solve Maze Problem using Backtracking.

#import sys
#sys.setrecursionlimit(10**5)

def printSolution(sol): 	
	for i in sol: 
		for j in i: 
			print(str(j) + " ", end ="") 
		print("") 

def isSafe(maze, x, y): 	
	if x >= 0 and x < N and y >= 0 and y < N and maze[x][y] == 1: 
		return True
	return False

def solveMaze(maze): 
	sol = [ [ 0 for j in range(N) ] for i in range(N) ] 
	if solveMazeUtil(maze, 0, 0, sol) == False: 
		print("Solution doesn't exist"); 
		return False
	printSolution(sol) 
	return True

def solveMazeUtil(maze,x,y,sol):
    if x == N-1 and y == N-1 and maze[x][y] == 1:
        sol[x][y] = 1
        return True
    if isSafe(maze,x,y) == True:
            sol[x][y] = 1
            if solveMazeUtil(maze,x+1,y,sol) == True:
                return True
            if solveMazeUtil(maze,x,y+1,sol) == True:
                return True
            #if solveMazeUtil(maze,x-1,y,sol) == True:
            #    return True
            if solveMazeUtil(maze,x,y-1,sol) == True:
                return True
            sol[x][y] = 0
            return False 

N = 5
maze = [[1,0,0,1,1],
        [1,1,0,1,1],
        [1,1,1,0,1],
        [1,0,1,1,0],
        [0,1,1,1,1]]

solveMaze(maze) 
