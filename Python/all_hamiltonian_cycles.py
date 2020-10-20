class Graph:

    def __init__(self,n):
        self.graph={}
        for i in range(n):
            self.graph[i]=[]
    
    def add_edge(self,u,v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    
    def hamiltonian_paths(self,index,path,paths):

        path.append(index)
        
        
        if len(path)!=len(self.graph):
            for e in self.graph[index]:
                if e not in path:
                    g.hamiltonian_paths(e,path,paths)
            
        elif 0 in self.graph[index]:
            paths.append(path)
        
        return

n=int(input("Enter number of vertices: "))
#print(n)
#print(type(n))
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
the graph in which a node is visited maximum once and it returns to the start node.

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







        
