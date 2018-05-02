
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

template <class T>
class GeneralizedDSU {
public:
	unordered_map<T, T> p;
	unordered_map<T, int> r;
	int n = 0;

    //does nothing if element already contained
	void insert(T x){
		if(p.count(x)) return;
		p[x] = x;
		r[x] = 0; //not necessary
		n++;
	}

	T find(T x){
		if(!p.count(x)) throw -2;
		if(p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	void merge(T x, T y){
		if(!p.count(x) || !p.count(y)) throw -2;
		T a = find(x), b = find(y);
		if(a == b) return;
		if(r[a] < r[b]) p[a] = b;
		else if(r[b] < r[a]) p[b] = a;
		else p[b] = a, r[a]++;
	}

	bool together(T x, T y){
		if(!p.count(x) || !p.count(y)) throw -2;
		return find(x) == find(y);
	}
};