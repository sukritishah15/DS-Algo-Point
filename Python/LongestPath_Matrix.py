# Python3 program to find the longest path in a matrix

n = 3 # size

def findLongestFromACell(i, j, mat, dp): 
	if (i<0 or i>= n or j<0 or j>= n): 
		return 0
	if (dp[i][j] != -1): 
		return dp[i][j]
	x, y, z, w = -1, -1, -1, -1

	if (j<n-1 and ((mat[i][j] +1) == mat[i][j + 1])): 
		x = 1 + findLongestFromACell(i, j + 1, mat, dp) 

	if (j>0 and (mat[i][j] +1 == mat[i][j-1])): 
		y = 1 + findLongestFromACell(i, j-1, mat, dp) 

	if (i>0 and (mat[i][j] +1 == mat[i-1][j])): 
		z = 1 + findLongestFromACell(i-1, j, mat, dp) 

	if (i<n-1 and (mat[i][j] +1 == mat[i + 1][j])): 
		w = 1 + findLongestFromACell(i + 1, j, mat, dp) 

	dp[i][j] = max(x, max(y, max(z, max(w, 1)))) 
	return dp[i][j] 

def finLongestOverAll(mat): 
	result = 1 # Initialize result 

	dp =[[-1 for i in range(n)]for i in range(n)] 

	for i in range(n): 
		for j in range(n): 
			if (dp[i][j] == -1): 
				findLongestFromACell(i, j, mat, dp) 

			result = max(result, dp[i][j]); 
	return result 

# Given Matrix - SAMPLE INPUT
mat = [[1, 2, 9], 
	[5, 3, 8], 
	[4, 6, 7]] 
print("Length of the longest path is ", finLongestOverAll(mat)) 

# SAMPLE OUTPUT:
# Length of the longest path is 4
