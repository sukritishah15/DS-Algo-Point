//AnkitCode99 here....

// The problem statement goes like.
// Each node and edge has some weight. For each node you can either
// stay at the same node of visit some other node following a certain 
// path such that the total weight you choose in either of the case
// for each node is minimised.

#include<bits/stdc++.h>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
typedef long long int ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back

using namespace std;

const ll sz=1e5+5;
const ll szz=1e6+6;
const ll mod=1e9+7;

vector<pair<ll,ll>> ar[sz];
ll cost[sz],ans[sz];
ll n,m,w;

void MultiSourceDijkstra()
{
	set<pair<ll,ll>> q;
	for(ll i=1;i<=n;i++)
	{
		ans[i]=cost[i];
		q.insert({i,cost[i]});
	}

	while(!q.empty())
	{
		ll current_node = (q.begin())->first;
		ll current_cost = q.begin()->second;
		q.erase(q.begin());

		for(auto it:ar[current_node])
		{
			ll node = it.first;
			ll costt = it.second;

			if(ans[node] > ans[current_node]+costt)
			{
				q.erase({node,ans[node]});
				ans[node]=ans[current_node]+costt;
				q.insert({node,ans[node]});
			}
		}
	}
}

int main()
{
	cin>>n>>m;

	for(ll i=0;i<m;i++)
	{
		ll a,b,w;
		cin>>a>>b>>w;
		ar[a].pb({b,2*w});
		ar[b].pb({a,2*w});
	}

	for(ll i=1;i<=n;i++)
	{
		cin>>cost[i];
	}

	MultiSourceDijkstra();

	for(ll i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}

	cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

}//Goodbye...

/*
Sample Input
3 3
1 2 1
2 3 1
1 3 1
30 10 20

12 10 12 

Time Coplexity - O(|V|log(|V|))
Space Complexity - O (|V|)

where, |V| denotes the number of nodes
*/
