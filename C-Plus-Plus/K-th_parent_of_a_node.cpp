//AnkitCode99 here....

/*

Given a tree with N nodes rooted at node number 1,
all other nodes are associated with exactly one parent node.
There are 'q' queries of the type - find k'th parent of
node number 'n'.

Constraints - 1 <= N <= 10^5

*/
 
#include<bits/stdc++.h>
#define endl "\n"
#define Ryuga ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
typedef long long int ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
 
using namespace std;
 
const ll sz=(1e5+5)*2;
const ll szz=1e6+6;
const ll mod=1e9+7;
 
vector<ll> adj[sz];
ll par[sz][21];
 
void dfs(ll node, ll parent) 
{
	par[node][0] = parent;
    for(ll i = 1;i<=20;i++) 
    {
    	ll temp=par[node][i-1];
        par[node][i] = par[temp][i-1]; 
    }
    for(auto it: adj[node]) 
    {
        if(it!=parent) 
        {
            dfs(it, node); 
        }
    }
}
 
int main()
{
 
	clock_t startTime=clock();
 
	ll n,q;
	cin>>n;
	rep(i,2,n+1)
	{
		ll ele;
		cin>>ele;
		adj[i].pb(ele);//immediate parent of 
		adj[ele].pb(i);
	}
	
	dfs(1,-1);
 
	cin>>q;
	while(q--)
	{
		ll node, k;
	    cin >> node >> k; 
	    ll cnt = 0;
	    while(k) 
	    {
	        if(k&1) 
	        {
	            node = par[node][cnt]; 
	        }
	        k = k >> 1; 
	        cnt++; 
	    }
	    cout << node<<endl; 
	}
 
	cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
 
}//Goodbye...

/*

Sample Input
10 10
1 2 3 4 5 6 7 8 9
6 1
7 4
6 2
10 4
9 7
8 5
1 1
9 8
4 1
4 3

Sample Output
5
3
4
6
2
3
-1
1
3
1

Time Complexity
Preprocessing Time - O(N)
Per-Query - O(log2(k))

Space Complexity - O(20*N)
where, N = Number of nodes

*/
