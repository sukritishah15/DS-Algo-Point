#include<iostream>
#include<vector> 
using namespace std;
const int maxn = 1e5 + 10;

vector<int> tree[maxn]; 

int findDepth(int root,int pa) {
    int ans = 0; 
    for(int v:tree[root]) {
      if(v != pa) {
        ans = max(ans, findDepth(v,root));
      }
    }
    return 1 + ans; 
}

int findDiameter() {

  if( tree[1].size() == 2)
  {
    return 1 + findDepth(tree[1][0],1) + findDepth(tree[1][1], 1);
  }
  else {
    return 1 + findDepth(tree[1][0], 1);
  }
  
}
int main() {  

  int n;
  int x,y;

  cout<<"Enter the no of nodes \n";
  cin>>n;
  cout<<"Enter the edges \n";
  for(int i=0;i<n-1;i++)
  {
    cin>>x>>y;
    tree[x].push_back(y);
    tree[y].push_back(x); 
  }

  cout<<"Diameter is "<<findDiameter()<<endl; 
  return 0;   
}
/*

Enter the no of nodes 
6
Enter the edges 
1 2 2 4 2 5 1 3 5 6

Diameter is 5
      1
     /  \
    2    3    
   / \
  4   5
      / 
     6


Enter the no of nodes 
5
Enter the edges 
1 2 4 2 5 2 5 6

Diameter is 4

       1
     /  
    2       
   / \
  4   5
      / 
     6
*/
