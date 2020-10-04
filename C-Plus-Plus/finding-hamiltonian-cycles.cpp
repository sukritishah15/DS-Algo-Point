/*
Finding Hamiltonian Cycles in a Graph
*/

// ============================================= CODE ============================================
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

void hamiltonian_cycles(vector<vector<int>> graph, vector<int> path, int V, unordered_set<int> visited, int index, vector<vector<int>>& result){

    visited.insert(index); // marking the vertex as visited

    path.push_back(index); // adding the vertex to the path

    if (visited.size() != V ){

        // moving forward
        for(int j=0; j<V; j++){

            if (graph[index][j] == 1 && (visited.find(j) == visited.end()) ){

                hamiltonian_cycles(graph, path, V, visited, j, result); // moving forward

            }

            else continue;
        }
    }

    // all vertices are visited AND you can return back to vertex 0 from the last index
    else if (graph[index][0] == 1){

        path.push_back(0); // push 0th vertex to complete the cycle
        result.push_back(path); // push the cycle in the result
    }

    return;
}


int main(){
    int V; cin>> V; // Number of vertices in the Graph

    vector<vector<int>> graph (V, vector<int> (V, 0)); // setting up the Graph

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            cin>>graph[i][j]; // inputting values
        }
    }

    vector<int> path; // generating path of the cycle

    unordered_set<int> visited; // set of all visited vertices

    vector<vector<int>> result; // storing all possible cycles in the result

    int index = 0; // as we begin with index 0

    hamiltonian_cycles(graph, path, V, visited, index, result); // search for the cycles begins

    for(auto p: result){
        for(auto vertex: p){
            cout<< vertex <<" "; 
        }
        cout<< endl;
    }

    cout << result.size() <<" hamiltonian cycles found in the graph!!"; 
    return 0;
}

/*

TIME COMPLEXITY: For each of the N vertices you have another N-1 vertices to explore, which can lead to possible cycles.

Hence Time Complexity = O(N!)

INPUT

7
0 1 0 1 1 0 0
1 0 1 1 1 1 1
0 1 0 1 0 0 1
1 1 1 0 0 0 0
1 1 0 0 0 1 1
0 1 0 0 1 0 1
0 1 1 0 1 1 0

OUTPUT

0 1 3 2 6 5 4 0
0 1 4 5 6 2 3 0
0 1 5 4 6 2 3 0
0 3 1 2 6 5 4 0
0 3 2 1 5 6 4 0
0 3 2 1 6 5 4 0
0 3 2 6 1 5 4 0
0 3 2 6 4 5 1 0
0 3 2 6 5 1 4 0
0 3 2 6 5 4 1 0
0 4 1 5 6 2 3 0
0 4 5 1 6 2 3 0
0 4 5 6 1 2 3 0
0 4 5 6 2 1 3 0
0 4 5 6 2 3 1 0
0 4 6 5 1 2 3 0
16 hamiltonian cycles found in the graph!!

*/
