// Problem statement:
// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.

#include<iostream>
#include<algorithm>
using namespace std;
struct structure
{
	int first_vertex;
	int second_vertex;
	int weight;
};

int get_parent(int current_vertex, int *parent)
{
	if (current_vertex == parent[current_vertex])
	{
		return current_vertex;
	}
	return get_parent(parent[current_vertex], parent);
}
structure* get_MST(structure* arr, int e, int v)
{
	structure* output = new structure[v - 1];
	int* parent = new int[v];
	for (int i = 0; i < v; i++)
	{
		parent[i] = i;
	}
	int count = 0, i = 0;
	while (count < v - 1 && i<e)
	{
		structure current_edge = arr[i];
		int first_vertex_parent = get_parent(current_edge.first_vertex, parent);
		int second_vertex_parent = get_parent(current_edge.second_vertex, parent);
		if (first_vertex_parent != second_vertex_parent)
		{
			output[count] = current_edge;
			count++;
			parent[first_vertex_parent] = second_vertex_parent;
		}
		i++;
	}
	return output;
}
bool sorter(structure a, structure b)
{
	if (a.weight < b.weight)
	{
		return true;
	}
	return false;
}
int main()
{
	int v, e;
	cin >> v >> e;
	structure* arr = new structure[e];
	for (int i = 0; i < e; i++)
	{
		cin >> arr[i].first_vertex >> arr[i].second_vertex >> arr[i].weight;
	}
	sort(arr, arr + e, sorter);
	structure* output = get_MST(arr, e, v);
	for (int i = 0; i < v - 1; i++)
	{
		if (output[i].first_vertex < output[i].second_vertex)
			cout << output[i].first_vertex << " " << output[i].second_vertex << " " << output[i].weight << endl;
		else
			cout << output[i].second_vertex << " " << output[i].first_vertex << " " << output[i].weight << endl;
	}
}

/*
Sample Input:
4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output:
1 2 1
0 1 3
0 3 5 
*/
// Time complexity : O(ElogE) where E is number of edges
// Space complexity : O(v)    where v is number of vertices