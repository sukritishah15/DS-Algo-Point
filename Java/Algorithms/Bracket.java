package Java.Algorithms;

import java.util.*;

public class Bracket {
    public static void main(String[] args)
    {    
         Scanner sc=new Scanner(System.in);
        int flag=0;
        System.out.print("Enter the expression :");
        String S=sc.next();
        Stack<Character> brace=new Stack<Character>();
        for(int i=0;i<S.length();i++)
        {
            if(S.charAt(i)=='{' || S.charAt(i)=='[' || S.charAt(i)=='(')
            { 
                brace.add(S.charAt(i));

            }
            if(brace.isEmpty())
            {
               flag=1;
           
                break;
            }
            if(S.charAt(i)=='}' )
            {
                if(brace.peek()=='{')
                {
                    brace.pop();
                }
                else
                {
                   flag=1;
               
                    break;
                }
            }
            if(S.charAt(i)==']' )
            {
                if(brace.peek()=='[')
                {
                    brace.pop();
                }
                else
                {
                   flag=1;
                
                    break;
                }
            }
            if(S.charAt(i)==')' )
            {
                if(brace.peek()=='(')
                {
                    brace.pop();
                }
                else
                {
                    flag=1;
           
                    break;
                }
            }
            
            
            
        }
          if(!brace.isEmpty())
          {
              flag=1;
          }
          if(flag==1)
          {
              System.out.println("Not Balanced");
          }
          else
          {
              System.out.println("Balanced");
          }

    }
    
}
/*
I/O 
Input
Enter the Expression :

Output
If the expression is Balanced =>"Balanced";
If not  =>"Not Balanced"

Example 1:Expression is :{{{[([][])]}}}
          Output:"Balanced" 
          
Example 2:Expression is ({}{[]{}
          Output:"Not Balanced"          


Time Complexity:O(n) n=length of String
Space Complexity:O(1)
*/