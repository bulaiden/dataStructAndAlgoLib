//a prime sieve in O(nloglog(n)) time

vector<int> sieveOfEratosthenes(int n){
	vector<bool> a(n+1);
	vector<int> ret;

	for(int i=2; i<=n; i++){
		if(a[i]) continue;
		ret.push_back(i);
		for(int j=i+i; j<=n; j++) a[j] = true;
	}

	return ret;
}