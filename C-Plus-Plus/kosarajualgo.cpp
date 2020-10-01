#include<bits/stdc++.h>
using namespace std;
//defining data structures to store the graph and its reversed counterpart
vector<int> graph[10000],rev_graph[10000];
//data structures to maintain topological sort of the graph and and visit history of vertex;
vector<int> order,component,visited(10000,0);

//depth first traversal to maintain the topological order.

void dfs_order(int v)
{
	if(visited[v]==0)
	visited[v]=1;
	for(auto i: graph[v])
	{if(not visited[i])
		dfs_order(i);
	}
	order.push_back(v);
}
// second topological sort to traverse over reversed graph to find components.
void dfs_comp(int v)
{
	if(visited[v]==0)
	visited[v]=1;
	component.push_back(v);
	for(auto i:rev_graph[v])
	{
		if(not visited[i])
		{
			dfs_comp(i);
		}
	}
	
}
/*
Time complexity: O(n+edges);
n is no. of vertices
Sample Test case:
Input:

5
5
1 0
0 2
2 1
0 3
3 4

Output:
0 1 2 
3 
4 


*/
int main()
{//taking inputs of count of vertices and edges
	int n;
	cin>>n;
	int edges;
	cin>>edges;
	for(int i=0;i<edges;i++)
	{
		int u,v;
		cin>>u>>v;
		//pushing edges and reverse edges into adj. lists of graph and reverse graph;
		graph[u].push_back(v);
		rev_graph[v].push_back(u);
	}
	
	//storing the topological order using first dfs
	for(int i=0;i<n;i++)
	{
		if(not visited[i])
		dfs_order(i);
		
	}
	//reverse to find the original topological order.
	reverse(order.begin(),order.end());
	
	//reusing the visited array;
	for(int i=0;i<n;i++)
	visited[i]=0;
	
	//calling second dfs for each component.
	for(int i=0;i<(int)order.size();i++)
	{
		if( visited[order[i]]==0)
		{
			dfs_comp(order[i]);
			for(int i=0;i<(int)component.size();i++)
			cout<<component[i]<<" ";
			cout<<endl;
			component.clear();
		}
	}
}
