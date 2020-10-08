//AnkitCode99 (DP)....

/*
The problem statement goes like.

There is a directed graph G with N vertices and M edges. 
The vertices are numbered 1,2,…,N, and for each i (1≤i≤M), 
the i-th directed edge goes from Vertex A to Vertex B.

*/

#include<bits/stdc++.h>
typedef long long int ll;

using namespace std;

const ll sz=1e5+5;
vector<ll> adj[sz];
ll cache[sz];

ll dfs(ll node)
{
    ll &ans=cache[node];
    if(ans!=-1)
        return ans;
    ans=0;//initialise size of curr node as 0
    for(ll child:adj[node])
    {
        ans=max(ans,1+dfs(child));
    }
    return ans;
}

int main()
{
    
    ll n,m;
    cin>>n>>m;
    memset(cache,-1,sizeof cache);
    for(ll i=1;i<=n;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        ans=max(ans,dfs(i));
    }
    cout<<ans;

}//Goodbye...

/*

Sample Input
5 8
5 3
2 3
2 4
5 2
5 1
1 4
4 3
1 3

Sample Output
3

Time Complexity - O(N)
Space Complexity - O(N)
where, N = Number of nodes in the graph 

*/
