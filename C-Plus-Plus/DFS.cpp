// C++ program to print DFS traversal of a given graph
#include<bits/stdc++.h> 
using namespace std; 
const int MAX = 100001;
vector<int> adj[MAX]; // array of vector to store edges
vector<bool> visited(MAX); // visited vector
DFS(int u) 
{ 
	visited[u] = true; // mark node visited
	cout<<u<<" "; // print the node value
	for(auto v:adj[u]) // iterate over the directly connected edges
		if(!visited[v]) // check if not visited
			DFS(v); // recursively call DFS function
} 
int main() 
{ 
	int V,E;
	cin >> V >> E; // input number of vertices and edges
	for(int i=0;i<E;i++)
	{
		int u,v;
		cin>>u>>v; // input all edges
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << "Depth First Traversal : "; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; // initialize visited vector
	DFS(0); // call DFS from 1st vertex

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
