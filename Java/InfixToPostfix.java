// Java code to convert infix expression to postfix expression
import java.util.*;
import java.util.Stack; 

public class InfixToPostfix{
    // function to find precedence of operator
    static int Precedence(char ch) 
    { 
        switch (ch) 
        { 
        case '+': 
        case '-': 
            return 1; 
       
        case '*': 
        case '/': 
            return 2; 
       
        case '^': 
            return 3; 
        } 
        return -1; 
    }

    // function to convert infix expression to postfix expression
    static String ConvertExp(String exp) 
    { 

        String result = new String(""); 
        
        Stack<Character> stack = new Stack<>(); 
          
        for (int i = 0; i<exp.length(); ++i) 
        { 
            char c = exp.charAt(i); 
              
            if (Character.isLetterOrDigit(c)) 
                result += c; 
            
            else if (c == '(') 
                stack.push(c); 
            
            else if (c == ')') 
            { 
                while (!stack.isEmpty() && stack.peek() != '(') 
                    result += stack.pop(); 
                  
                if (!stack.isEmpty() && stack.peek() != '(') 
                    return "Invalid Expression";               
                else 
                    stack.pop(); 
            } 
            else 
            { 
                while (!stack.isEmpty() && Precedence(c) <= Precedence(stack.peek())){ 
                    if(stack.peek() == '(') 
                        return "Invalid Expression"; 
                    result += stack.pop(); 
             } 
                stack.push(c); 
            } 
       
        } 
        
        while (!stack.isEmpty()){ 
            if(stack.peek() == '(') 
                return "Invalid Expression"; 
            result += stack.pop(); 
         } 
        return result; 
    } 
    
    public static void main(String[] args)  
    { 
        String exp = "a-b+c((d*e)/f)*i"; 
        System.out.println(ConvertExp(exp)); 
    }
}

/*
  Time Complexity - O(N^2)
  Space Complexity - O(N)
  
  Input - Taken in the Code .
  Output - ab-cde*f/i*+
*/