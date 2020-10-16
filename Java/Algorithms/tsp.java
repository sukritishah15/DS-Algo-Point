package Java.Algorithms; /**
* Implementation of TSP
* https://github.com/sukritishah15/DS-Algo-Point/issues/133
* Contributed by @jhoserpacheco : https://github.com/jhoserpacheco
*/

/*
  Algorithm used at my university in competitive programming contests

  travelling salesman problem. Returns the minimum
  route doing a tour visiting all nodes (cities) only once.
*/
static final int MAX = 18;
static int target; // Initialize it for (1 << N) - 1
static int dist[][] = new int [MAX][MAX]; //Distance between each pair of nodes
static int N;
static int dp[][] = new int[( 1 << MAX) + 2][MAX];
static ArrayList<Integer> rb = new ArrayList<>();
static final int INF = (int) (2e9);


// Call for TSP (0, -1) If it does not start from any specific city
// Otherwise call TSP (0, 0)
static int TSP(int mask, int u){
	if(mask == target){
		return 0;
		  /*Or failing that, the extra cost after having visited all
      the cities. Example: Return to the main city
	    */
}
	if(u == -1){
		int ans = INF;
		for(int i = 0; i < N; i++){
			ans = Math.min(ans, TSP(mask | (1 << i), i));
			//Add extra cost from the starting point if necessary
		}
		return ans;

	}
	int ans = dp[mask][u];
	if(ans != -1) return ans;
	ans = INF;
	for(int i = 0; i < N; i++){
		if((mask & (1 << i)) == 0)
			ans = Math.min(ans, TSP(mask | (1 << i), i) + dist[u][i]);
	}
	return ans;
}

static void build(int mask, int u){
	if(mask == target) return; //Finish the tour
	if(u == -1){
		for(int i = 0; i < N; i++){
			if(TSP(mask, u) == TSP(mask | (1 << i), i)){
				rb.add(i);
				build(mask | (1<<i), i);
				return;
			}
		}
	}else{
		for(int i = 0; i < N; i++){
			if((mask & (1 << i)) == 0){
				if(TSP(mask, u) == TSP(mask | (1 << i), i) + dist[u][i]){
					rb.add(i);
					build(mask | (1 << i), i);
					return;
				}
			}
		}
	}
}


/**
Sample I/O-
Complexity NP-hardness
*/
