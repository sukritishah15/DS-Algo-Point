// The time complexity of KMP algorithm is O(n) in the worst case.

// The space complexity of KMP algorithm is O(m), where m = length of the pattern

#include<bits/stdc++.h>
using namespace std;

void computeLPS(string pat, int m, int lps[]){
    int len=0;
    lps[0] =0;

    int i=1;
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i] =len;
            i++;
        }else{
            if(len !=0){
                len =lps[len-1];
            }else{
                lps[i] =0;
                i++;
            }
        }
    }
}

void KMPsearch(string txt, string pat,int n, int m){
    int lps[m];
    computeLPS(pat, m, lps);
    int i=0,j=0;
    while(i<n){
        if(pat[j]==txt[i]){
            i++;
            j++;
        }

        if(j==m){
            cout<<"Pattern found at index "<<(i-j);
            j =lps[j-1];
        }else if(i<n && pat[j] != txt[i]){
            if(j != 0){
                j =lps[j-1];
            }else{
                i++;
            }
        }
    }
}


int main(){
    int n, m;
    cin>>n>>m;
    string txt, pat;
    cin>>txt>>pat;
    KMPsearch(txt, pat, n, m);
    return 0;
}

// Input : 23 4
// Hacktoberfestopensource open

// Output : 13