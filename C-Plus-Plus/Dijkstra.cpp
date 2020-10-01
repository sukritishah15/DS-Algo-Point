#include<bits/stdc++.h>
using namespace std;

#define INF 1e14
#define endl "\n"
#define Size 200005
typedef long long ll;

priority_queue<pair<int,int>> q;
vector<ll> dist(Size);
vector<bool> processed(Size);
vector<pair<int,ll>> adj[Size];

void dijkstra(int s)
{
    for(int i=0;i<=Size;i++) {
        dist[i]=INF;
    }
    dist[s]=0;
    q.push({0,s});

    while(!q.empty()) {
        int a = q.top().second;q.pop();
        if(processed[a])
            continue;
        processed[a]=true;
        for(auto u : adj[a]) {
            ll b = u.first;
            int w = u.second;

            if(dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }

}

void displayDistance(int &n) {
    for(int i=1;i<=n;i++) {
        if(dist[i]==INF) cout<<"INF ";
        else
            cout<<dist[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    int n,m;
    cin>>n>>m;

    ll d;
    int u,v;

    for(int i=0;i<m;i++) {
        cin>>u>>v>>d;
        adj[u].push_back(make_pair(v,d));
        adj[v].push_back(make_pair(u,d));
    }
    cout<<endl;
    int source;
    cin>>source;
    dijkstra(source);
    displayDistance(n);

    return 0;

}


/*
    Name of Algorithm : Dijkstra's Algorithm
    Time Complexity : O(n+mlogm)
    Space Complexity : O(n)

    User is required to enter the number of vertices for the graph,
    and also the number of edges for the graph in space separated manner.
    Then for m lines user will provide the input for the source vertex,destination vertex
    and also the weight for that edge  that connects starting vertex to the destination vertex.
    Then User will give the input for the source vertex for that user wants to know the
    distance to all other node.

    Constraints negative input should not be given.

    Input :
    5
    6
    1 2 5
    1 4 9
    1 5 1
    2 3 2
    3 4 6
    4 5 2

    1

    Output :
    0 5 7 3 1
*/
