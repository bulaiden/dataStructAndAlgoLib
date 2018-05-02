//sqrt(n) prime factorization.

//logic:
//if x is a prime factor of n, then prime factorization of n reduces to {x} + {prime factorization of n/x}
//if x is the smallest prime factor of n, then the smallest prime factor of n/x is at least x.
//if the prime factorization of n is composed only of numbers which are greater than sqrt(n), then it must be 
// that n is prime.

//requisite: n >= 2
vector<int> primeFactorizationSqrtN(int n){
	vector<int> ret;

	for(int i=2; i*i<=n; i++)
		while(!(n%i)) ret.push_back(i), n /= i;

	ret.push_back(n);
	return ret;
}