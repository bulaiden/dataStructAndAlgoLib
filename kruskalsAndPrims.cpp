class DSU {
public:
	vector<int> p, r;
	int n = 0;

	DSU(int n){
		this->n = n;
		p = r = vector<int>(n);
		for(int i=0; i<n; i++) p[i] = i;
	}

	int find(int x){
		if(p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	void merge(int x, int y){
		int xr = find(x), yr = find(y);
		if(xr == yr) return;
		if(r[xr] < r[yr]) p[xr] = yr;
		else if(r[yr] < r[xr]) p[yr] = xr;
		else p[yr] = xr, r[xr]++;
	}

	bool together(int x, int y){
		return find(x) == find(y);
	}
};

//logic: cut property
//let T be the edges in a connected subset of a MST. Let S be the nodes connected by T.
//let e(u,v) be the cheapest edge that connects S to V-S.
//lets assume that there is a MST Z is formed from T but which doesn't include e.
//if we add e to Z, we would form a cycle. This cycle has at least one edge that isn't e that
//crosses S to V-S. (actually, there is exactly 1 edge, since as soon as the 1 path from u 
//return back to S, it can use edges in T to reach v)
//we can remove this edge, and now we have a new MST which is of less or equal cost.

//only for undirected graphs
//nodes numbered 0 to n-1
//list of edges [{c,u,v}]
int kruskals(vector<tuple<int,int,int>> e, int n){
	sort(e.begin(),e.end());
	DSU dsu(n);

	int tot = 0;
	for(int i=0; i<(int)e.size(); i++){
		auto x = e[i];
		int c = get<0>(x), u = get<1>(x), v = get<2>(x);
		if(!dsu.together(u,v)) dsu.merge(u,v), tot += c;
	}
	return tot;
}

//only for undirected graphs
//nodes numbered 0 to n-1
//slight inefficiency due to adding an edge twice to the priority queue, but big O unchanged.
//adjacency list [[{v, c}]]
int prims(vector<vector<pair<int,int>>> g, int n){
	if(!n) return 0;

	//{c,v}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<void>> q;
	DSU dsu(n);

	for(auto p : g[0])
		q.push({p.second, p.first});

	int tot = 0;
	while(!q.empty()){
		auto x = q.top(); q.pop();
		int c = x.first, v = x.second;
		if(!dsu.together(0,v)){
			dsu.merge(0,v);
			tot += c;
			for(auto p : g[v])
				q.push({p.second, p.first});
		}
	}
	return tot;
}




