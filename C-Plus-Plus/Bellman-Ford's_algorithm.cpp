#include <bits/stdc++.h>
using namespace std;


const int INF = 1e7;
int n, m, src;
vector <int> dist;
vector <tuple <int,int,int>> g;

void bellmanFord()
{
    dist.assign(n, INF);
    dist[src] = 0;

    for (int i = 1; i < n; ++i)
    {
        // use a bool variable to optimize the second for loop
        bool updates = false;

        for (int j = 0; j < m; ++j)
        {
            int a = get<0>(g[j]);
            int b = get<1>(g[j]);
            int c = get<2>(g[j]);
            int tmp = dist[b];
            dist[b] = min(dist[b], dist[a]+c);
            // if no improvements have been made, exit from these 2 for loops
            if (dist[b] < tmp) updates = true;
        }

        if (!updates) break;
    }

    // check if there is a cycle
    for (int i = 0; i < m; ++i)
    {
        int a = get<0>(g[i]);
        int b = get<1>(g[i]);
        int c = get<2>(g[i]);

        if (dist[b] > dist[a]+c)
        {
            cout << "Graph contains negative cycle!\n";
            return;
        }
    }

    for (int i = 0; i < n; ++i)
        cout << dist[i] << ' ';

    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);


    cin >> n >> m >> src;
    g.resize(m);

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[i] = make_tuple(a,b,c);
    }

    bellmanFord();



    return 0;
}
