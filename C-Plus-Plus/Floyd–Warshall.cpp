typedef long long ll ;
    #include<bits/stdc++.h>
    #define INF 999900001
    using namespace std;
    int main()
    {

    ll n , m ;
    cin >> n >> m ;
    ll Graph[n][n] ;
    ll dist[n][n] ;
    for(ll i = 0 ;i < n ; i++)
    {
        for(ll j =0 ; j<n ; j++)
            Graph[i][j] = INF ;
    }
    for(ll i = 0 ; i < m ;i++)
    {
        ll t1 ,t2 ,t3 ;
        cin >> t1 >>t2 >>t3 ;
        Graph[t1-1][t2-1] =	t3 ;
    }

    for (ll i = 0; i < n; i++)
    {   
        for (ll j = 0; j < n; j++)
            dist[i][j] = Graph[i][j];
    }

    for(ll k = 0; k < n; k++)
    {
        for(ll i = 0; i < n; i++)
        {
                for(ll j = 0; j < n; j++)  
                {	
                    if(i!=j)
                    dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
                }
                    
        }
    }

    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < n ; j++)
        {
            if(i == j) cout << 0 << " " ; 
            else if(dist[i][j] == INF) cout << "infinity " ;  
            else 
                cout << dist[i][j] <<" ";
        }
        cout << endl ; 
    }
  
}



/*
Time complexity:
as there are three loops in nested form the time complexity is O(n^3) where n is the number of vertices

Space complexity:
O(n^2) for storing the graph

Form of sample input: 
first line consists of number of vertices(n) and number of edges(m)
next m lines consist of a , b , weight where there exists an edge from a to b of weight "weight"; 1<= a,b <= n

Form of sample output:
the ith row and jth colomn consists of the smallest path from vertex i to vertex j; and infinity means there exists no path from i to j. 

Sample Input:
4 5             
1 2 10
1 3 24
2 3 2
2 4 15
3 4 7

output: 
0 10 12 19 
infinity 0 2 9 
infinity infinity 0 7 
infinity infinity infinity 0 



*/
