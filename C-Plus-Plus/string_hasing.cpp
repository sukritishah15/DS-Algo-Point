#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 2e5+5, seed = 131; //the maximum length of the string and a prime number as the seed

int fn[26], fh[26]; string n, h; ll hsh[mxn], p[mxn] = {1};
unordered_set<ll> sett; //used to count the freq of needle in haystack
bool check(int fn[], int fh[]) { //checking if freq match (if so, needle exists)
    for (int i=0;i<26;i++) {
        if(fn[i]!=fh[i]) return false;
    } return true;
}
ll substrHash(int l, int r) {
    return hsh[r] - hsh[l-1]*p[r-l+1];
}
int main() {
    cin >> n >> h;
    for (int i=0;i<n.size();i++) {
        fn[n[i]-'a']++;
    } //counting letter frequency
    for (int i=1;i<=h.size();i++) {
        hsh[i] = hsh[i-1]*seed + h[i-1]; //hashing the string
        p[i] = p[i-1]*seed; //precomputing powers of the seed
    }
    for (int i=1;i<=h.size();i++) {
        fh[h[i-1]-'a']++;
        if(i>n.size()) fh[h[i-n.size()-1]-'a']--;
        if(check(fn, fh)) sett.insert(substrHash(i-n.size()+1, i));
    }
    cout << sett.size() << "\n";
}
/*
Description:
- Given a string N, the needle, and a string H, the haystack, find the number
of disctice permutations of which N apperas in H.
Input specification:
- String N, H where N<=H in length and H<=2e5
Output specification:
- The number of distinct permutation s of N which appear as a substring of H
Sample Input:
aab
abacabaa
Sample Output:
2
Time Complextiy: O(n) preprocessing with O(1) queries
Space Complexity: O(n)
*/
