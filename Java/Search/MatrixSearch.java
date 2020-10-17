package Java.Search;

import java.util.*;

public class MatrixSearch {
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the row: ");
        int r=sc.nextInt();       //rows of the matrix
        System.out.print("Enter the column: ");
        int c=sc.nextInt();      // column of the matrix
        int[][] arr=new int[r][c];
        System.out.println("Enter the elements in matrix in sorted manner: ");
          for(int a=0;a<r;a++)        //indexing zero
             {for(int b=0;b<c;b++)
               {
                arr[a][b]=sc.nextInt();
               }
             }
        System.out.print("Enter the element to search: ");
            int key=sc.nextInt();
    
    
        // Searing the element in matrix
           
         int i;
         int j=0;
         
         int flag=0;
         boolean found=false;
           for( i=0;i<r;i++)
             {
                if(flag==0)    
                 {for(j=c-1;j>=0;j--)
                   { if(key<arr[i][j])
                      { continue;}
                     else if(key>=arr[i][j])
                      {  flag=1;
                          break;}
                   }    
                 }
                else
                  {
                   if(arr[i][j]==key)
                    {
                    System.out.println("Found at index (row,column): "+(i+1)+","+(j+1) ); 
                    found=true;
                    break;
                    }
                }
              }
            if(found==false)
            { System.out.println("Element out found");}
       
       





    
}
}


/*
Sample I/O
Input Format
  Enter the number of rows:
  Enter the number of columns:
  Elements of the matrix in sorted manner:
  Enter the element to search:

Output
if element is found =>Found at index (row,column):r,c
if element is not found =>Element not found
  
Example 1:Suppose a 3X3 sorted matrix is given
                  
matrix => 2 6  14
          4 8  17
          5 12 21
 element to find is 12
 
 Output is =>Found at index(rows,column):3,2

Example 2:Suppose a 4X5 sorted matrix is given
                  
matrix => 10 20 30 40 50
          13 23 33 44 55
          14 27 35 45 57
          16 29 37 47 62

 element to find is 53
 
 Output is =>Element not found



Time complexity:O(r+c)
Space complexity:O(1)
*/
