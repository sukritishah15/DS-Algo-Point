using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class floyd_warshall{
  static void Main(string[] args){
    int n=0;
    n=Console.ReadLine();
    int[][] adjmat=new int[n][n];
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        int x;
        x=Console.ReadLine();
        if(x==0 && i!=j) x=0;
        adjmat[i][j]=x;
      }
    }

    for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          adjmat[i][j]=min(adjmat[i][j],adjmat[i][k]+adjmat[k][j]);
        }
      }
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
        Console.Write("{0} ",adjmat[i][j]);
      Console.WriteLine();
    }

  return 0;
  }
}

/* floyd warshell algorithm:
 The Floyd–Warshall algorithm is an algorithm for finding shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles). 
 A single execution of the algorithm will find the lengths (summed weights) of shortest paths between all pairs of vertices. 
 Although it does not return details of the paths themselves, it is possible to reconstruct the paths with simple modifications to the algorithm. 

 Complexity:
 time complexity :O(n^3)
 space complexity :O(n^2)

 Sample input:
                    {0, 5,  0, 10},
                    {0, 0,  3,  0},
                    {0, 0,  0,  1},
                    {0, 0,  0,  0}
sample output:
     0      5      8      9
     0      0      3      4
     0      0      0      1
     0      0      0      0