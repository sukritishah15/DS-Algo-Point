#include<bits/stdc++.h>
using namespace std;
/*
 * input:
 * 4
1 0 0 0 
1 1 0 1
0 1 0 0
1 1 1 1
* 
Output:
1 0 0 0 
1 1 0 0 
0 1 0 0 
0 1 1 1 

 * Time complexity: O(2^n*n);
 * Space Complexity: O(n*n);
 * 
 */
//x and y is current position in the grid
bool func(int x,int y,int n,vector<vector<int>> &a,vector<vector<int>> &vis)
{
	
	//if destination is safely reached return true->path found
	if(x+1==n and y+1==n and a[x][y]==1 )
	{
		vis[x][y]=1;
		return true;
	}
	// or if we are in a reachable  spot right now
	if(x<n and y<n and a[x][y])
	{
		//include it in the path for once
		vis[x][y]=1;
		//try go to right block
		if(func(x+1,y,n,a,vis))
		{
			return true;
		}
		//try going to the down block;
		if(func(x,y+1,n,a,vis))
		{
			return true;
		}
		//path was wrongly include so remove from path
		vis[x][y]=0;
		
		return false;
	}
	
return false;
}
int main()
{int n;

	cin>>n;
	//a stores the map of grid and vis is the path to be visited;
	vector<vector<int>> a(n,vector<int>(n,0));
		vector<vector<int>> vis(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			vis[i][j]=0;
		}
	}
	func(0,0,n,a,vis);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<vis[i][j]<<" ";
		}
		cout<<endl;
	}
}
