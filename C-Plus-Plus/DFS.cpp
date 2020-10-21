// C++ program to print DFS traversal of a given graph
#include<bits/stdc++.h> 
using namespace std; 
const int MAX = 100001;
vector<int> adj[MAX];
vector<bool> visited(MAX);
DFS(int u) 
{ 
	visited[u] = true;
	cout<<u<<" ";
	for(auto v:adj[u])
		if(!visited[v])
			DFS(v);
} 
int main() 
{ 
	int V,E;
	cin >> V >> E;
	for(int i=0;i<E;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << "Depth First Traversal : "; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 
	DFS(0); 

	return 0; 
} 

/*
Sample Input for V = 4, E = 6: 

4 6
0 1
0 2
1 2
2 0
2 3
3 3 

Sample Output:

Depth First Traversal : 0 1 2 3 

Time complexity: O(V + E)

Space Complexity: O(V)
*/
