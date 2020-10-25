package Java.Algorithms;

import java.util.Scanner;

public class powerset{
  public static void main (String[] args){
    int n;
    Scanner in= new Scanner(System.in);
    n=in.nextInt();
    int[] set=new int[n];
    for(int i=0;i<n;i++){
      set[i]=in.nextInt();
    } 
    in.close();

    // output
    System.out.println("{");
    //backtracking
    for(int i=0;i<(1<<n);i++){ // intrating 2^n times
      System.out.print("{ ");
      for(int j=0;j<n;j++){
        if((i & (1<<j))!=0) 
          System.out.print(set[j]+" ");        
      }
      System.out.print("},\n");
    }
    System.out.println("}");
  }
}
/*
powerset is a set that contatins all subset of a set.
it is represented as P(A) if it is power set of A.

Implementation:
  used backtracing 
  used bits 

Input:
  number of elements n
  followed by n numbers seprated by space

output:
  power set of input set

Sample Input-output:
  Input #1:
    3
    1 2 3
  Output #1:
    {
    { },
    { 1 },
    { 2 },
    { 1 2 },
    { 3 },
    { 1 3 },
    { 2 3 },
    { 1 2 3 },
    }
  
  Input #2:
    0
  Output #2:
    {
    { },
    }

Time complexity= O(2^n*n)
Space complexity = O(n)

Contributed by: Hitansh K Doshi (github id: Hitansh159)
*/
