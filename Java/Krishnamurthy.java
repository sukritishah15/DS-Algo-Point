import java.util.*;    // Importing package
class Krishnamurthy
{
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        int n,c,s=0;
        System.out.println("Enter Number");
        n=sc.nextInt();    // Taking input
        c=n;               // Making a copy
        while(c>0)
        {
            int d=c%10;        // Extracting digits
            s=s+Factorial(d);  // Adding factorial of all digits
            c=c/10;
        }
        if(s==n)
        System.out.println(n+" is a Krishnamurthy Number.");        // Displaying the final output
        else
        System.out.println(n+" is not a Krishnamurthy Number.");    // Displaying the final output
    }
    // Function to find factorial of a digit
    public static int Factorial(int n)
    {
        int f=1,i;
        for(i=1;i<=n;i++)
        f=f*i;
        return f;         // Returning value
    }
}

/*
Input:145
Output:145 is a Krishnamurthy Number.
Input:252
Output:252 is not a Krishnamurthy Number.
Time Complexity:O(m*r), where m is number of digits and r is value of digits
Space Complexity:O(1)
*/
