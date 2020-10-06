#include <bits/stdc++.h>
using namespace std;

/*
Input Format: number of vertices of the graph, number of edges of the graph, folloewed by the edges of the directed graph
Output Format: If the graph has cycle then Graph contains cycle else the topological sort of the vertices of the graph
ALgorithm: Kahn's Algorithm
Time Complexity: O(V + E), V = number of vertices of the graph, E = number of edges of the graph
Space Complexity: O(V + E)

Sample Input and Output

**Sample Input 1:**

Enter the number of vertices of the graph: 8

Enter the number of edges of the graph: 9

Enter edges of the graph in the format u v, u has a directed edge to v:
1 4
1 2
4 2
4 3
3 2
5 2
3 5
8 2
8 6

Topological sort of the graph is: 1 4 3 5 7 8 2 6


**Sample Input 2:**

Enter the number of vertices of the graph: 2

Enter the number of edges of the graph: 2

Enter edges of the graph in the format u v, u has a directed edge to v:
1 2
2 1

Graph contains cycle!
*/

int main()
{

  /*
    n is the number of vertices of the graph
    m is the number of edges of the graph
    Note: here graph means a directed graph
    */

  int n, m;
  cout << "\nEnter the number of vertices of the graph: ";
  cin >> n;
  cout << "\nEnter the number of edges of the graph: ";
  cin >> m;
  vector<int> adj[n + 1];      // stores the adjacency list format of the graph
  vector<int> indeg(n + 1, 0); // stores the indegree of all vertices of the graph

  cout << "\nEnter edges of the graph in the format u v, u has a directed edge to v: \n";
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    indeg[v]++;
  }

  /*
    open stores the vertices whose indegrees are zero
    priority queue with min heap will give the lexicographically smallest topological sort of the graph
    if the order of the topological sort doesn't matter, replace
    priority_queue <int, vector <int>, greater<int>> open;
    with queue<int> open;
    and replace top() function with front()
    */
  priority_queue<int, vector<int>, greater<int>> open;
  for (int i = 1; i <= n; i++)
  {
    if (indeg[i] == 0)
    {
      open.push(i);
    }
  }

  vector<int> toposort; // this stores the topological sort of the graph
  while (!open.empty())
  {
    int node = open.top();
    toposort.push_back(node);
    open.pop();
    for (auto u : adj[node])
    {
      indeg[u]--;
      // if after decreasing the indegree the indegree of the vertex becomes zero include in the open
      if (indeg[u] == 0)
      {
        open.push(u);
      }
    }
  }

  // if toposort vector doesnt contain all the vertices of the graph then it contains a cycle
  if ((int)toposort.size() != n)
  {
    cout << "\nGraph contains cycle!" << '\n';
  }
  else
  {
    cout << "\nTopological sort of the graph is: ";
    for (auto u : toposort)
    {
      cout << u << " ";
    }
    cout << '\n';
  }
}