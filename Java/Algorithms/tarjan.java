package Java.Algorithms; /**
Implementation of Tarjan Algorithm in Java
https://github.com/sukritishah15/DS-Algo-Point/issues/112
Contributed by @jhoserpacheco : https://github.com/jhoserpacheco
*/

/*
Given a directed graph find the strongly connected components (SCC).

--- Implementation used in competitive programming competitions

*/


static final int MAX = 100005; //Maximum number of nodes
static ArrayList<Integer> g[] = new ArrayList[MAX]; //Adjacency list
static boolean[] vis = new boolean[MAX]; //Mark the nodes already visited
static Stack<Integer> st = new Stack();
static int[] low = new int[MAX];
static int[] num = new int[MAX];
static int compOf[] = new int[MAX]; //Stores the component to which each node belongs
static int cantSCC; //Quantity of strongly connected components
static int N, M, cont; //Number of nodes and edges

static void tarjan(int u) {
    low[u] = num[u] = cont++;
    st.push(u);
    vis[u] = true;

    for (int v : g[u]) {
        if (num[v] == -1)
            tarjan(v);
        if (vis[v])
            low[u] = Math.min(low[u], low[v]);
    }

    if (low[u] == num[u]) {
        while (true) {
            int v = st.pop();
            vis[v] = false;
            compOf[v] = cantSCC;
            if (u == v) break;
        }
        cantSCC++;
    }
}

static void init() {
    cont = cantSCC = 0;
    for (int i = 0; i <= N; i++) {
        g[i].clear();
        num[i] = -1;
    }
}


/*

Sample I/O-

Input -

3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
Smith, Peter
Brown, Anna

Ouput:the output will be a line containing a
positive integer representing the minimum number of stable groups
of people that can be formed.

2

Time Complexity - O(V + E)
Space Complexity - O(n)

*/
