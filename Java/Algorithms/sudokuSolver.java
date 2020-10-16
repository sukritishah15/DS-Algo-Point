package Java.Algorithms;//Sudoku SOlver (Issue #274)
//https://github.com/sukritishah15/DS-Algo-Point/issues/274
//Contributed by @mephi007 : https://github.com/mephi007
import java.util.*;
import java.util.stream.Collectors;

public class sudokuSolver {
	static int r;
	static int c;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char[][] board = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
				{ '6', '.', '.', '1', '9', '5', '.', '.', '.' }, { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
				{ '8', '.', '.', '.', '6', '.', '.', '.', '3' }, { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
				{ '7', '.', '.', '.', '2', '.', '.', '.', '6' }, { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
				{ '.', '.', '.', '4', '1', '9', '.', '.', '5' }, { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };

		r = board.length;
		c = board[0].length;
		System.out.println("--Suduko board---");
		for(char[] b : board) {
			System.out.println(Arrays.toString(b));
		}
		System.out.println();
		System.out.println("---solving suduko---");
		if(validSudoku(board, 0, 0) != true) {
			System.out.println("Solving Sudoku not possible");
		}else {
			for(char[] b : board) {
				System.out.println(Arrays.toString(b));
			}
		}
	}
	
	 public static boolean validSudoku(char[][] board, int row, int col){
	        if(col >= c){
	            row++;
	            col = 0;
	        }
	        if(row >= r) return true;
	        
	        if(Character.isDigit(board[row][col])){
	           return validSudoku(board, row, col+1);
	        }
	        
	        for(int i=1; i<=9; i++){
	            char c = (char)(i+'0');
	            board[row][col] = c;
	            if(isValid(board, row, col) && validSudoku(board,row, col+1)){
	                return true;
	            }
	            board[row][col] = '.';
	        }
	        return false;
	    }
	    
	    public static boolean isValid(char[][] board, int row, int col){
	        char ele = board[row][col];
	        
	        for(int i = 0; i<c; i++){
	            if(i != col && Character.isDigit(board[row][i]) && board[row][i] == ele){
	                return false;
	            }
	        }
	        
	        for(int i=0; i<r; i++){
	            if(i != row && Character.isDigit(board[i][col]) && board[i][col] == ele){
	                return false;
	            }
	        }
	        
	        int startRow = row/(int)Math.sqrt(r)*(int)Math.sqrt(r);
	        int endRow = startRow+(int)Math.sqrt(r);
	        int startCol = col/(int)Math.sqrt(c)*(int)Math.sqrt(c);
	        int endCol = startCol+(int)Math.sqrt(c);
	        for(int i=startRow; i<endRow; i++){
	            for(int j=startCol; j<endCol; j++){
	                if(i != row && j != col && Character.isDigit(board[i][j]) && board[i][j] == ele){
	                    return false;
	                }
	            }
	        }
	        
	        return true;

}
}

/*
 * ---Input and Output---
 * --Suduko board---
[5, 3, ., ., 7, ., ., ., .]
[6, ., ., 1, 9, 5, ., ., .]
[., 9, 8, ., ., ., ., 6, .]
[8, ., ., ., 6, ., ., ., 3]
[4, ., ., 8, ., 3, ., ., 1]
[7, ., ., ., 2, ., ., ., 6]
[., 6, ., ., ., ., 2, 8, .]
[., ., ., 4, 1, 9, ., ., 5]
[., ., ., ., 8, ., ., 7, 9]

---solving suduko---
[5, 3, 4, 6, 7, 8, 9, 1, 2]
[6, 7, 2, 1, 9, 5, 3, 4, 8]
[1, 9, 8, 3, 4, 2, 5, 6, 7]
[8, 5, 9, 7, 6, 1, 4, 2, 3]
[4, 2, 6, 8, 5, 3, 7, 9, 1]
[7, 1, 3, 9, 2, 4, 8, 5, 6]
[9, 6, 1, 5, 3, 7, 2, 8, 4]
[2, 8, 7, 4, 1, 9, 6, 3, 5]
[3, 4, 5, 2, 8, 6, 1, 7, 9]
 *
 * Time Complexity  = O(9^(n*n))
 * Space Complexity =  O(n*n)
 * */
