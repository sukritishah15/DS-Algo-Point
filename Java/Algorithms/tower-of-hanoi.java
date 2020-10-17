package Java.Algorithms;/*
   

 Input will be the single digit number which will be representing the Number of rings
 Output will also be single digit telling the number of moves for shifting the rings
 
 Time Complexity is expontial because it takes 2^n time to find the case 
 space complexity is O(1)



*/








public class Solution {
    public static void main(String[] args) {
        
        solve(3, 'A', 'C', 'B');
        

        
    }
    public static void solve(int n,char src,char destination,char helper){
        if(n==1){
            System.out.println("Moved Disk 1 from " +src+" "+ destination );
            return;
        }
        
        solve(n-1,src,helper,destination);
        System.out.println("Moved Disk " + n+" from " + src +" "+ destination);
        solve(n-1, helper, destination, src);
    }
}


