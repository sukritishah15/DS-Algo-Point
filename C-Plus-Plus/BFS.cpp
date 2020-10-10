//AnkitCode99 here....

// The problem state goes like.
// Given a dense connection of nodes and edges in form of a graph,
// find a simple path between node S and node D, return no possible
// path if no path exist between the mentioned nodes.

#include<bits/stdc++.h>
#define endl "\n"
typedef long long int ll;
using namespace std;

const ll sz=100005;
vector<ll> ar[sz];
bool vis[sz];
ll par[sz];
ll n,m;

void bfs(ll node)
{
	queue<ll> q;
	q.push(node);
	vis[node]=true;
	par[node]=-1;
	cout<<"BFS Traversal of the graph is - ";
	while(!q.empty())
	{
		ll curr=q.front();
		cout<<curr<<" ";
		q.pop();
		for(ll child:ar[curr])
		{
			if(!vis[child])
			{
				vis[child]=true;
				q.push(child);
				par[child]=curr;
			}
		}
	}
}

void path(ll node,ll des)
{
	bfs(node);

	if(!vis[des])
	{
		cout<<"No possible path";
	}
	else
	{
		vector<ll> path;
		for(ll v=des;v!=-1;v=par[v])
		{
			path.push_back(v);
		}
		reverse(path.begin(), path.end());
		cout<<"\nPath from ("<<node<<", "<<des<<") ->";
		for(ll v:path)
		{
			cout<<v<<" ";
		}
	}
}

int main()
{
    cin>>n>>m;


	for(ll i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}


	path(1,6);
	return 0;
}

/*
Sample Input

n=7 m=6
4 6
4 7
4 5
5 3
2 3
2 1

Output

BFS Traversal of the graph is - 1 2 3 5 4 6 7 
Path from (1, 6) ->1 2 3 5 4 6

Space Complexity - O(|n| + |m|)
Time Complexity - O(|n| + |m|)

*/
