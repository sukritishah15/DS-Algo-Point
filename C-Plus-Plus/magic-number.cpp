#include <bits/stdc++.h>
using namespace std;

long long n;
long long sum(long long x) {
    long long n = 0; string s = to_string(x);
    for (int i=0;i<s.size();i++) {
        n+=s[i]-'0';
    }
    return n;
} //sum the digits of x
bool fun(long long x) {
    if((int)log10(x)+1==1) return x==1;
    return fun(sum(x));
} //recursive method
int main() {
    cin >> n;
    if(fun(n)) puts("True");
    else puts("False");
}
/*
Sample Input: A single number
100
Sample Output: whether the number satisifies the magic number property
true
Time complexity: at most O(L) where L is the length of the integer
Space complexity: O(1)
*/