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
