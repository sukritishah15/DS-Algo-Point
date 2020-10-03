#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define V 200005
#define pb push_back


vector<int> adj[V];

void DFS(int u,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<bool>& arti_point)
{
    static int time = 0;
    disc[u]=low[u]=time;
    time++;
    int children = 0;

    for(int v : adj[u]) {
        if(disc[v]==-1) {
            children +=1;
            parent[v]=u;
            DFS(v,disc,low,parent,arti_point);
            low[u] = min(low[u],low[v]);

            if(parent[u]==-1 && children >1)
                arti_point[u]=true;

            if(parent[u]!=-1 && low[v] >= disc[u])
                arti_point[u]=true;
        }
        else if(v != parent[u])
            low[u]=min(low[u],disc[v]);
    }
}

void findAPs(int num)
{
    vector<int> disc(V,-1),low(V,-1),parent(V,-1);
    vector<bool> arti_point(V,false);

    for(int i=1;i<=num;i++) {
        if(disc[i]==-1) {
            DFS(i,disc,low,parent,arti_point);
        }
    }
    cout<<"Articulation Points are : ";
    for(int i=1;i<=num;i++) {
        if(arti_point[i]==true){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}


int main()
{
    int n,m;
    cin>>n>>m;
    int a,b;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].pb(b);
        swap(a,b);
        adj[a].pb(b);
    }
    findAPs(n);

    return 0;
}

/*
Explanation:
    Tarjan Algorithm is used to check whether is graph is strongly connected or not
    it also find its uses to check the articulation points ,
    articulation points are those points whose removal increase in the number of connected components
    of graph , it also find its use in finding bridges , bridges are those edge whose removal increase in the
    number of connected components.
    Here we have implemented Tarjan's Algorithm to find articulation points.

Program Features:
    In this program first user will give the number of vertices the graph has
    then they will give the input for the number of edges of the graph
    then they will give the details of the edge that is they will provide two inputs for
    the number of edge lines. This two inputs will connect two vertices with an edge.
    Then at the last output will be the articulation points the graph has.

Time Complexity : O(V+E)        where (V,E) = number of vertices,number of edges

Space Complexity: O(V)          where V = number of vertices


Input :
        5 5
        1 2
        1 3
        3 2
        1 4
        4 5
Output :
        Articulation Points are : 1 4
*/
