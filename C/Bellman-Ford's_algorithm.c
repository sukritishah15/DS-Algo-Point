#include <stdio.h>

typedef struct Edge {
    int a, b, c;
};

const int INF = 1e7;
int n, m, src, dist[(int)1e5];
struct Edge g[(int)1e5];

int min(int a, int b) {
    return (a < b) ? a:b;
}

void bellmanFord()
{
    for (int i = 0; i < n; ++i)
        dist[i] = INF;

    dist[src] = 0;

    for (int i = 1; i < n; ++i)
    {
        // use a bool variable to optimize the second for loop
        int updates = 0;

        for (int j = 0; j < m; ++j)
        {
            int a = g[j].a;
            int b = g[j].b;
            int c = g[j].c;
            int tmp = dist[b];
            dist[b] = min(dist[b], dist[a]+c);
            // if no improvements have been made, exit from these 2 for loops
            if (dist[b] < tmp) updates = 1;
        }

        if (updates == 0) break;
    }

    // check if there is a cycle
    for (int i = 0; i < m; ++i)
    {
        int a = g[i].a;
        int b = g[i].b;
        int c = g[i].c;

        if (dist[b] > dist[a]+c)
        {
            printf("Graph contains negative cycle!\n");
            return;
        }
    }

    for (int i = 0; i < n; ++i)
        printf("%d ", dist[i]);

    printf("\n");
}

int main()
{
    scanf("%d %d %d", &n, &m, &src);

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        struct Edge edge;
        edge.a = a, edge.b = b, edge.c = c;
        g[i] = edge;
    }

    bellmanFord();



    return 0;
}
