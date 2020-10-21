class Graph:

    def __init__(self,n):
        """
        initializes dictionary with n vertices
        """
        self.graph={}
        for i in range(n):
            self.graph[i]=[]
    
    def add_edge(self,u,v):
        """
        method adds edge for undirected graph represented as an adjacency list
        """
        self.graph[u].append(v)
        self.graph[v].append(u)

    
    def hamiltonian_paths(self,index,path,paths):
        """
        function for finding paths
        index is the initial vertice
        path is a list of vertices in the current path
        if linked vertice is not in path it is added and made as initial vertice for
        next recursion 
        else if path has all vertices visited once and the first vertice can be 
        reached from the end of path it is a hamiltonian path
        """
        path.append(index)
        
        
        if len(path)!=len(self.graph):
            for e in self.graph[index]:
                if e not in path:
                    g.hamiltonian_paths(e,path,paths)
            
        elif 0 in self.graph[index]:
            paths.append(path)
        
        return


n=int(input("Enter number of vertices: "))
g=Graph(n)
m=int(input("Enter number of edges: "))
for _ in range(m):
    u,v=[int(x) for x in (input("enter vertice1, vertice2 of the edge: ")).split(',')]
    g.add_edge(u,v)

paths=[]
path=[]
index=0
g.hamiltonian_paths(index,path,paths)

print("Paths:")
for p in paths:
    print(p)


"""
Problem: 
Given a graph, we need to find all hamiltonian paths/cycles i.e. a traversal through 
the graph in which a node is visited once and it returns to the start node.

For Example-
Enter number of vertices: 5
Enter number of edges: 7
enter vertice1, vertice2 of the edge: 0,1
enter vertice1, vertice2 of the edge: 1,2
enter vertice1, vertice2 of the edge: 2,3
enter vertice1, vertice2 of the edge: 3,4
enter vertice1, vertice2 of the edge: 4,0
enter vertice1, vertice2 of the edge: 1,4
enter vertice1, vertice2 of the edge: 1,3
Paths:
[0, 1, 2, 3, 4]

V = Number of vertices
E = Number of edges
Time Complexity :- O(V*E)
Space Complexity :- O(V*E)

"""







        
