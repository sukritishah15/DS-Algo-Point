import java.util.Scanner;
import java.util.Arrays;
 
/**Flood Fill Class**/
public class FFill
{
   /**Fill Grid Function**/
    private void fGrid(char[][] a, int x, int y) 
    {
        if (a[x][y] == 'X')
        {
            a[x][y] = 'W';
            output(a);
 
            fGrid(a, x + 1, y);
            fGrid(a, x - 1, y);
            fGrid(a, x, y + 1);
            fGrid(a, x, y - 1);
        }
    }
    /**Display Output of the program**/
    private void output(char[][] a)
    {
        System.out.println("\nGrid : ");
        for (int i = 1; i < a.length - 1; i++)
        {
            for (int j = 1; j < a[i].length - 1; j++)
                System.out.print(a[i][j] +" ");
            System.out.println();
        }
    }
 
   /**Main Class Begain**/ 
    public static void main(String[] args) 
    {
        Scanner scan = new Scanner( System.in );        
        /**Input Dimensions**/
        System.out.println("Enter dimensions: ");
        int M = scan.nextInt();
        int N = scan.nextInt();
 
        
        char[][] array = new char[M + 2][N + 2];
        for (int i = 0; i < M + 2; i++)
            Arrays.fill(array[i], 'O');
 
        
        System.out.println("Enter grid with 'X'=passage and 'Y'=obstacle");
 
        for (int i = 1; i < M + 1; i++)
            for (int j = 1; j < N + 1; j++)
                array[i][j] = scan.next().charAt(0);    
 
        System.out.println("Enter coordinates: ");
        int sx = scan.nextInt();
        int sy = scan.nextInt();
 
        if (array[sx][sy] != 'X')
        {
            System.out.println("Invalid coordinates!");
            System.exit(0);
        }
 
        FFill ff = new FFill();
        ff.fGrid(array, sx, sy);    
 
    }  
    /**End Main Function**/  
}

/**
Sample Input output
Enter dimensions:
5 5
Enter grid with 'X'=passage and 'Y'=obstacle
X X X X X
Y X Y X Y
Y Y X X Y
X Y Y Y Y
X Y Y Y Y
Enter coordinates: 
3 3
OUTPUT
Grid : 
X X X X X 
Y X Y X Y 
Y Y W X Y 
X Y Y Y Y 
X Y Y Y Y 
Grid : 
X X X X X 
Y X Y X Y 
Y Y W W Y 
X Y Y Y Y 
X Y Y Y Y 
Grid : 
X X X X X 
Y X Y W Y 
Y Y W W Y 
X Y Y Y Y 
X Y Y Y Y 
Grid : 
X X X W X 
Y X Y W Y 
Y Y W W Y 
X Y Y Y Y 
X Y Y Y Y 
Grid : 
X X X W W 
Y X Y W Y 
Y Y W W Y 
X Y Y Y Y 
X Y Y Y Y 
Grid : 
X X W W W 
Y X Y W Y 
Y Y W W Y 
X Y Y Y Y 
X Y Y Y Y 
Grid : 
X W W W W 
Y X Y W Y 
Y Y W W Y 
X Y Y Y Y 
X Y Y Y Y 
Grid : 
X W W W W 
Y W Y W Y 
Y Y W W Y 
X Y Y Y Y 
X Y Y Y Y 
Grid : 
W W W W W 
Y W Y W Y 
Y Y W W Y 
X Y Y Y Y 
X Y Y Y Y 
Time Complexity= O(N^2)
Space Complexity= O(N)
**/
