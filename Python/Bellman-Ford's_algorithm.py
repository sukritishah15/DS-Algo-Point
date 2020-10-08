import math

class Algorithms.Edge:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c


edge = []

def bellmanFord(n, m, src):
    dist = [math.inf for i in range(n)]
    dist[src] = 0

    for _ in range(1, n):
        # use a bool variable to optimize the second for loop
        updates = False

        for j in range(m):
            a = edge[j].a
            b = edge[j].b
            c = edge[j].c
            tmp = dist[b]
            dist[b] = min(dist[b], dist[a] + c)
            # if no improvements have been made, exit from these 2 loops
            if dist[b] < tmp: updates = True

        if not updates: break

    # check if there is a cycle
    for i in range(m):
        a = edge[i].a
        b = edge[i].b
        c = edge[i].c

        if dist[b] > dist[a] + c:
            print("Graph contains negative cycle!\n")
            return

    print(dist)


n, m, src = map(int, input().split())

for i in range(m):
    a, b, c = map(int, input().split())
    edge.append(Algorithms.Edge(a, b, c))

bellmanFord(n, m, src)
