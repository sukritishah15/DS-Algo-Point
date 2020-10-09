#include<bits/stdc++.h>
using namespace std;
void get_Z(string strf, int Z[])
{
    int left=0, right=0, i, j;
    for(i=1; i<strf.length(); i++)
    {
        if(i>right)
        {
            left = right = i;
            while((strf[right] == strf[right - left]) && (right < strf.length()))
            {
                right++;
            }
            Z[i] = right - left;
            right--;
        }
        else
        {
            j = i - left;
            if(Z[j] < right-i+1)
            {
                Z[i] = Z[j];
            }
            else
            {
                left = i;
                while((strf[right] == strf[right - left]) && (right < strf.length()))
                {
                    right++;
                }
                Z[i] = right - left;
                right--;
            }
            
        }
        
    }
}
int main()
{
    string str, pattern, strf;
    cout<<"Enter string:";
    cin>>str;
    cout<<"Enter pattern to be searched:";
    cin>>pattern;
    strf = pattern+'$'+str;
    int i, Z[strf.length()];
    get_Z(strf, Z);
    for(i=0; i<strf.length(); i++)
    {
        if(Z[i] == pattern.length())
        {
            cout<<pattern<<" found at index "<<(i-pattern.length()-1)<<endl;
        }                       
    }
    return 0;
}

/*
Problem: Fid occurrences of a given pattern in a given string using Z algorithm.

Sample I/O:

Enter string:aabacdaabca
Enter pattern to be searched:aab
aab found at index 0
aab found at index 6

Enter string:aaabaabaaabaa
Enter pattern to be searched:baa
baa found at index 3
baa found at index 6
baa found at index 10

Time Complexity: O(m+n) where m is length of string and n is length of pattern
Space Complexity : O(m+n)

*/
