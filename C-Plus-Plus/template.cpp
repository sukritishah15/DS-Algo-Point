
#include<bits/stdc++.h> 

#define ll                   long long int 
#define forp(i,a,b)          for(int i=(int)a;i<(int)b;++i) 
#define forpe(i,a,b)         for(int i=(int)a;i<=(int)b;++i) 
#define forpl(i,a,b)         for(ll i=(ll)a;i<(ll)b;++i) 
#define forn(i,a,b)          for(int i=(int)a;i>=(int)b;--i) 
#define count_1(n)            __builtin_popcountll(n) 
#define pb                    push_back 
#define eb                    emplace_back 
#define ab(a)                 (a<0)?(-1*a):a 
#define pc                    putchar_unlocked 
#define gc                    getchar_unlocked 
#define mset(a,b,c)           loop(i,0,b) a[i]=c 
#define F                     first 
#define S                     second 
#define mp                    make_pair 
#define clr(x)                x.clear() 
#define MOD                   1000000007 
#define MAX                   1e9 
#define MIN                   -1e9 
#define itoc(c)               ((char)(((int)'0')+c)) 
#define vi                    vector<int> 
#define vvi                   vector<vi> 
#define pll                   pair<ll,ll> 
#define pii                   pair<int,int> 
#define all(p)                p.begin(),p.end() 
#define max(x,y)              (x>y)?x:y 
#define min(x,y)              (x<y)?x:y 
#define mid(s,e)              (s+(e-s)/2) 
#define mini                  INT_MIN 
const int MX=10010896; 
const int lmt=3164; 
const int N=10000001; 
int flag[MX>>6]; 
#define ifc(i)                (flag[i>>6]&(1<<((i>>1)&31))) 
#define isc(i)                (flag[i>>6]|=(1<<((i>>1)&31))) 
#define chk(n)                (n==2||(n>2&&(n&1)&&!ifc(n))) 
#define test                  int t; scanf("%d",&t)

using namespace std; 

ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}} 
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;} 
void sieve(){ int i,j,k; for(i=3;i<lmt;i+=2) if(!ifc(i)) for(j=i*i,k=i<<1;j<MX;j+=k) isc(j);} 
 
int main() 
{ 
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
    test;
    while(t--){
        //code goes here
    }
    return 0;
}





