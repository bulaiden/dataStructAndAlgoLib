//returns the rank of each element

vector<int> coordinateCompression(const vector<long>& a){
    int n = a.size();
    vector<pair<long, int>> p;

    for(int i=0; i<n; i++)
        p.push_back({a[i], i});

    sort(p.begin(), p.end());

    vector<int> ret(n);
    for(int i=1, r=0; i<n; i++)
        ret[p[i].second] = p[i-1].first < p[i].first ? ++r : r;
    return ret;
}