package Java.Algorithms;

import java.util.*;

public class Automorphic{
    static boolean isAutomorphic(int n){
        int s=n*n; 
        // Start Comparing digits 
        while(n>0){ 
            // Return false, if any digit of n doesn't match with its square
            if (n%10!=s%10) 
                return false; 
            n/=10; 
            s/=10; 
        } 
        return true; 
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number: ");
        int n=sc.nextInt();
        if(isAutomorphic(n))
            System.out.println("Automorphic Number");
        else     
            System.out.println("Not an Automorphic Number");
    }
}

/*
    Input:- 
    Enter number: 25
    Output:-
    Automorphic Number
    Logic:-
    25*25=625 which ends with 25
    
    Input:- 
    Enter number: 7
    Output:-
    Not an Automorphic Number
    Logic:-
    7*7=49 which does not end with 7

    Time complexity: O(log n)
    Space complexity: O(1)
*/