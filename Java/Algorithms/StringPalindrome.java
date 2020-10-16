package Java.Algorithms;

public class StringPalindrome
{
    public static void main(String args[])
    {
        String a, b = "";
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the string you want to check:");
        a = s.nextLine();
        int n = a.length();
        for(int i = n - 1; i >= 0; i--)
        {
            b = b + a.charAt(i);
        }
        if(a.equalsIgnoreCase(b))
        {
            System.out.println("The string is palindrome.");
        }
        else
        {
            System.out.println("The string is not palindrome.");
        }
    }
}
/*
Sample Input & Output

Input1: 
Enter the string you want to check:
Adi

Output1:
The string is not palindrome.

Input2: 
Enter the string you want to check:
adda

Output2:
The string is palindrome.

Time Complexity: O(n)
Space complexity: O(n)
*/