package Java.Algorithms;/*Java program to find the longest length path in a matrix*/

import java.util.*;
import java.io.*;

class longest_length_path
{ 
	public static int n=0; 

	//This function will return longest length from a particular cell 
	
    static int findLongestFromACell(int i, int j, int mat[][], int dp[][]) 
	{ 
		if (i < 0 || i >= n || j < 0 || j >= n) 
			return 0; 

		if (dp[i][j] != -1) 
			return dp[i][j]; 
 
		int x = Integer.MIN_VALUE, y = Integer.MIN_VALUE, z = Integer.MIN_VALUE, w = Integer.MIN_VALUE; 
        
		// Search for possible direction of the longest path from any cell 
		if (j < n - 1 && ((mat[i][j] + 1) == mat[i][j + 1])) 
			x = dp[i][j] = 1 + findLongestFromACell(i, j + 1, mat, dp); 

		if (j > 0 && (mat[i][j] + 1 == mat[i][j - 1])) 
			y = dp[i][j] = 1 + findLongestFromACell(i, j - 1, mat, dp); 

		if (i > 0 && (mat[i][j] + 1 == mat[i - 1][j])) 
			z = dp[i][j] = 1 + findLongestFromACell(i - 1, j, mat, dp); 

		if (i < n - 1 && (mat[i][j] + 1 == mat[i + 1][j])) 
			w = dp[i][j] = 1 + findLongestFromACell(i + 1, j, mat, dp); 

		/* Since the criteria is that the difference between each consecutive element present in the path must be same for all the elements present in the path 
        Hence we check this criteria in the four directions of each cell.
        If no cell element match with the criteria we will take 1 otherwise we will pick maximum element from all the four directions.*/
		return dp[i][j] = Math.max(x, Math.max(y, Math.max(z, Math.max(w, 1)))); 
	} 

	static int findlongest(int mat[][]) 
	{ 
		int result = 1; 

		int[][] dp = new int[n][n]; 
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				dp[i][j] = -1; 

		//Calculate the longest path beginning from all cells 
		for (int i = 0; i < n; i++) { 
			for (int j = 0; j < n; j++) { 
				if (dp[i][j] == -1) 
					findLongestFromACell(i, j, mat, dp); 

				//Result needs to be updated when we get a better solution 
				result = Math.max(result, dp[i][j]); 
			} 
		} 

		return result; 
	} 

	//main function
	public static void main(String[] args)throws IOException
	{
        BufferedReader b=new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the size of the matrix (Please note that it is a square matrix): ");
        n=Integer.parseInt(b.readLine());
        int matrix[][]=new int [n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.print("Enter element at position ("+i+","+j+") : ");
                matrix[i][j]=Integer.parseInt(b.readLine());
            }
        }
        
        System.out.println(">>>>End of Input>>>> \nThe inputed matrix is:\n");
        for(int i=0;i<n;i++)
        {
            System.out.print("[");
            for(int j=0;j<n;j++)
            {
                System.out.print(matrix[i][j]+", ");
            }
            System.out.print("\b\b]");
            System.out.println();
        }
		System.out.println("The longest length path found in which the difference between each consecutive element is same is: " + findlongest(matrix)); 
	}
}

/* 
## SAMPLE INPUT AND OUTPUT ##

Input: {{1, 2, 3, 6} 
        {13, 14, 6, 7} 
        {5, 19, 0, 8} 
        {12, 11, 10, 9}}
        
Output:

~/2020-10-01-024519$ javac longest_length_path.java 
Picked up _JAVA_OPTIONS: -Djava.io.tmpdir=/home/user/tmp/ -Xms64m
~/2020-10-01-024519$ java longest_length_path 
Picked up _JAVA_OPTIONS: -Djava.io.tmpdir=/home/user/tmp/ -Xms64m
Enter the size of the matrix (Please note that it is a square matrix): 4
Enter element at position (0,0) : 1
Enter element at position (0,1) : 2
Enter element at position (0,2) : 3
Enter element at position (0,3) : 6
Enter element at position (1,0) : 13
Enter element at position (1,1) : 14
Enter element at position (1,2) : 6
Enter element at position (1,3) : 7
Enter element at position (2,0) : 5
Enter element at position (2,1) : 19
Enter element at position (2,2) : 0
Enter element at position (2,3) : 8
Enter element at position (3,0) : 12
Enter element at position (3,1) : 11
Enter element at position (3,2) : 10
Enter element at position (3,3) : 9
>>>>End of Input>>>> 
The inputed matrix is:

[1, 2, 3, 6] 
[13, 14, 6, 7] 
[5, 19, 0, 8] 
[12, 11, 10, 9] 
The longest length path found in which the difference between each consecutive element is same is: 7

## EXPLANATION ## 
In the inputed matrix the longest length path found is 6-7-8-9-10-11-12

## TIME AND SPACE COMPLEXITY ##
Time complexity for the above solution is O(n^2). 
Space complexity is O(n^2). 
 */

