
//g = [[(to, cost)]] : adjacency list for nodes numbered 0 to n-1
//output: [(cost, from)]
//requisite: edge costs must be non-negative
vector<pair<int,int>> dijkstra(vector<vector<pair<int,int>>>& g, int src){
    int n = g.size();

    //(cost, to, from)
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<void>> q;
    const pair<int,int> NOTSEEN {-1, -1};
    vector<pair<int,int>> ret(n, NOTSEEN);

    q.push({0,src,src});

    while(!q.empty()){
        auto x = q.top(); q.pop();
        int c = get<0>(x), v = get<1>(x), u = get<2>(x);

        if(ret[v] != NOTSEEN) continue;
        ret[v] = {c, u};
        for(auto p : g[v]) q.push({p.second + c, p.first, v});
    }

    return ret;
}