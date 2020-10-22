// Check if two strings are anagrams or not

/*
Two strings, a and b, are called anagrams if they contain all the same characters in the same frequencies.
For example, the anagrams of CAT are CAT, ACT, TAC, TCA, ATC, and CTA.
*/

#include<bits/stdc++.h>
using namespace std;

bool check_anagram(string s1, string s2)
{
    //If the size of both strings is not same, frequency of each character can never be same
    if(s1.size()!=s2.size())
        return false;

    map<char,int> m1;

    //Increasing the frequency of character that appeared in s1 by 1
    for(int i=0; i<s1.size(); i++)
        m1[s1[i]]++;

    //Decreasing the frequency of character that appeared in s2 by 1
    for(int i=0; i<s2.size(); i++)
        m1[s2[i]]--;

    //Checking if any frequency is non-zero
    for(auto it=m1.begin(); it!=m1.end(); it++)
    {
        if(it->second!=0)
            return false;
    }

    return true;
}

int main()
{
    string s1,s2;

    //Taking input from user
    cout<<"Enter String 1: ";
    cin>>s1;

    cout<<"Enter String 2: ";
    cin>>s2;

    //Using check_anagram function to know if both strings are anagrams or not
    if(check_anagram(s1,s2))
        cout<<"The Strings "<<s1<<" and "<<s2<<" are anagrams!";
    else
        cout<<"The Strings "<<s1<<" and "<<s2<<" are not anagrams!";

    return 0;
}

/*
Sample Input 1:
aabbbccc
abcabcabc
Sample Output 1:
The Strings aabbbccc and abcabcabc are not anagrams!
Sample Input 2:
aabbbccc
abcabcbc
Sample Output 1:
The Strings aabbbccc and abcabcbc are anagrams!
*/

/*
Time Complexity: O(s1.size())
Space Complexity: O(s1.size())
*/
