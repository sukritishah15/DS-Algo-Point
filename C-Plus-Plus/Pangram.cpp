#include <bits/stdc++.h>
using namespace std;
bool isPangram(string str)
{
    //converting the string to lowercase
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    int n = str.length();
    int count[26] = {0};
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
        {
            continue; // omitting space
        }
        count[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string str;
    getline(cin, str);
    if (isPangram(str))
    {
        cout << "String is a pangram\n";
    }
    else
    {
        cout << "String is not a pangram\n";
    }
}
/*
Time Complexity: O(n)
Space Complexity: O(1)

Input: The quick brown fox jumps over the lazy dog
Output : String is a pangram

*/
