//Checking if a string is palindrome or not

#include<bits/stdc++.h>
using namespace std;

bool palindrome_check(string s1)
{
    int start=0;
    int end=s1.size()-1;

    //Checking the i and string.size()-i+1 character together to check if it's palindrome or not
    while(start<end)
    {
        if(s1[start]!=s1[end])
            return false;
        
        start++;
        end--;
    }

    return true;
}

int main()
{
    //Taking Input from the user
    string s1;
    cout<<"Enter the String: ";
    cin>>s1;

    //Returning answer
    if(palindrome_check(s1))
        cout<<"Yes, the string "<<s1<<" is a palindrome!";
    else
        cout<<"No, the string "<<s1<<" is not a palindrome!";
    
    return 0;
}

/*
Sample Input 1:
aabbaa

Sample Output 1:
Yes, the string aabbaa is a palindrome


Sample Input 2:
abababaaaa

Sample Output 2:
No, the string abababaaaa is not a palindrome
*/

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
