#include<stdio.h>
#include<stdlib.h>
#define INF 1e9

// helper functions:
// finding minimum of two numbers
int MIN(int x,int y){
  return x<y?x:y;
}

// displaying matrix
void display (int * adjmat,int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d ",*(adjmat+(i*n)+j));
    }
    printf("\n");
  }
} 

// if graph is undireccted then making sure all connected nodes share same weight
// in case of collision smaller will be considered 
void undirected(int *adjmat,int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      *(adjmat+(i*n)+j)=MIN(*(adjmat+(i*n)+j),*(adjmat+(j*n)+i));
    }
  }
}


int main(){
  int n,edge,directed,a,b;
  scanf("%d%d%d",&n,&edge,&directed);// user input for node,edges,directed or not
  int *adjmat=(int *)malloc(n*n*sizeof(int));// allocating required memory

  // making all value of matrix to be INF in stead of garbage value 
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        *(adjmat+(i*n)+j)=INF;
    }
  }

  // user input weights
  while(edge){
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    *(adjmat+((u-1)*n)+(v-1))=w;
    edge--;
  }
  if(directed==0) undirected(adjmat,n); // if undirected graph
  scanf("%d%d",&a,&b); // input node1 to node2

  // formatting matrix in required manner
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j) 
        *(adjmat+(i*n)+j)=0;
      else if(*(adjmat+(i*n)+j)==0) 
        *(adjmat+(i*n)+j)=INF;
    }
  }

  // main logic of floyd-warshall algorithm 
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        *(adjmat + (i*n)+j)=MIN(*(adjmat + (i*n)+j),
                            (*(adjmat + (i*n)+k)+*(adjmat + (k*n)+j)));
      }
    }
  }
  
  //output
  printf("\nOutput:\n");
  display(adjmat,n);
  printf("shortest distance between %d and %d is %d",a,b,*(adjmat+(a-1)*n+(b-1)));

  return 0;
}

/*
Folyd-warshall alorithm is a path finding algorithm.It finds shortest path between two nodes.
Implementation:
  Used adjacent matrix to store paths.
  Used dynamic memory allocation for user input length array. 

Input:
  First line consist of a number of nodes (n) and number of edges (edges) and is graph directed or not (directed) (it accepts 0 or 1).
  Followed by edges number of line consisting u v w where
    u: start node
    v: end node
    w: weight of edge
  Followed by a and b:
    a: start node
    b: end node

Output:
  adjacent matrix followed by 
  Shortest distance between a and b.

Sample input-output:
  Directed graph
  Input1:
    4 5 1
    1 2 5
    2 3 7
    2 4 6
    3 4 5
    4 1 2
    3 2

  Output1:
    0 5 12 11
    8 0 7 6
    7 12 0 5
    2 7 14 0
    Shortest distance between 3 and 2 is 12

  Undirected graph
  Input2:
    5 6 0
    1 2 5
    1 4 9
    1 5 1
    2 3 2
    3 4 7
    4 5 2
    5 3

  Output2:
    0 5 7 3 1 
    5 0 2 8 6 
    7 2 0 7 8 
    3 8 7 0 2 
    1 6 8 2 0 
    Shortest distance between 5 and 3 is 8

  Time complexity = O (n^3)
  Space complexity = O (n^2)

  Contributed by: Hitansh K Doshi (github id: Hitansh159)
*/