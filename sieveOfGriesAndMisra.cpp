
//linear time prime sieve
//has the bonus effect of computing the prime factorization of each number.
//drawback is that constant factor is worse due to needing to store integers instead of bit flags

//logic:
//let a[i] == the smallest prime factor of i
//each i can be expressed as a[i]*(i/a[i])
//a[i] is at least as small as the smallest prime factor of i/a[i]

//cell i is overwritten before iteration i IFF i is composite.
//if i is prime, then no j<i will write on cell i because j only writes on composites.
//if i is composite, then by induction j = (i/a[i]) will write on a[i] on cell i.
//k != j will not write on cell i because it would need to select larger a[i] (prime factor of i), 
//but that would make it so that i/a[i] has a smaller prime factor than a[i], which contradicts the logic
//of the algorithm.

vector<int> sieveOfGriesAndMisra(int n){
	vector<int> primes;
	vector<int> a(n+1);
	for(int i=2; i<=n; i++){
		if(!a[i]) a[i] = i, primes.push_back(i);
		for(int j=0; j<primes.size() && primes[j] <= a[i] && primes[j]*i <= n; j++)
			a[primes[j]*i] = primes[j];
	}
	return a;
}