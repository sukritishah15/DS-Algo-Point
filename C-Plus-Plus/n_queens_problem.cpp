/*N Queen Problem Solution from Scratch

Problem Statement: The N-Queens Problem is the problem of placing N chess queens on NxN chessboard so that no two queens attack each other.
The following code is the solution fo this problem using BACKTRACKING technique:
*/

#include<bits/stdc++.h>
using namespace std;

//This function checks if a queen can be placed on board[row][col] or not
bool issafe(vector<vector<int>>& board, int row, int col)
{
    //Check the row from top
    for(int i=0; i<row; i++)
    {
        if(board[i][col]==1)
            return false;
    }

    //Check the upper diagonal on the left side
    int i=row;
    int j=col;
    while(i>=0 && j>=0)
    {
        if(board[i][j]==1)
            return false;
        
        i--;
        j--;
    }

    //Check the upper diagonal on the right side
    i=row;
    j=col;

    while(i>=0 && j<board.size())
    {
        if(board[i][j]==1)
            return false;
        
        i--;
        j++;
    }

    return true;
}

//A recursive function to solve the nqueensproblem
bool nqueenproblem(vector<vector<int>>& board, int row)
{
    //Base case i.e. we've put a queen at a right place for row=0,..,v2.size()-1
    if(row==board.size())
        return true;

    //Consider the row and start placing the queen in all the columns one by one
    for(int col=0; col<board.size(); col++)
    {
        //Check if the queen can be placed on board[row][col]
        if(issafe(board,row,col))
        {
            //Place queen on the board
            board[row][col]=1;

            //Placing the rest of the queens using recursion
            bool otherqueens = nqueenproblem(board, row+1);

            //If all other queens are also placed, return true
            if(otherqueens)
                return true;
            
            //If placing a queen at board[row][col] doesn't give a solution, try placing queen on the other columns
            board[row][col]=0;
        }
    }

    //If the queens were not able to place, return false
    return false;
}

int main()
{
    //Taking the input from the user
    cout<<"Enter the size of board: ";
    int N;
    cin>>N;

    //Creating a NxN vector with all the elements to be 0
    vector<int> temp(N,0);
    vector<vector<int>> board;
    for(int i=0; i<N; i++)
        board.push_back(temp);

    /* If a solution exists, if statement executes
    ELSE, else statement executes */
    if(nqueenproblem(board,0))
        cout<<"Yes, you can place "<<N<<" queens on an "<<N<<"x"<<N<<" board without any two crossing each other!";
    else
        cout<<"No, you cannot place "<<N<<" queens on an "<<N<<"x"<<N<<" board without any two crossing each other!";
    
    return 0;
}

/*
Sample Input 1:
4

Output 1:
Yes, you can place 4 queens on an 4x4 board without any two crossing each other!


Sample Input 2:
3

Output 2:
No, you cannot place 3 queens on an 3x3 board without any two crossing each other!
*/

/*
Time Complexity of N-Queen Problem using Backtracking: O(N!)
Space Complexity of N-Queen Problem using Backtracking: O(N^2)
*/