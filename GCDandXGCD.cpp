
//logic:
//from gcd(a,b) divides both a and b, you can infer that gcd(a,b) divides r, and thus gcd(a,b) <= gcd(b,r)
//from gcd(b,r) divides both b and r, you can infer that gcd(b,r) divides a, and thus gcd(b,r) <= gcd(a,b)
//thus gcd(a,b) == gcd(b,r)
int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

//logic:
//a*b = lcm(a,b)*gcd(a,b)
//because lcm is bag union of prime factors
//and gcd is bag intersection of prime factors
//by sorting and pairing matching instances of prime factors on each side, the proof becomes evident.
int lcm(int a, int b){
	return a / gcd(a,b) * b;
}

//extended gcd
//represents gcd(a,b) as a linear combination of a and b
pair<int, int> xgcd(int a, int b){
	if(a < b){
		auto ret = xgcd(b,a);
		return {ret.second, ret.first};
	}

	if(b == 0) return {1, 0};

	int r = a%b, q = a/b;
	auto ret = xgcd(b, r);
	//xb + yr =
	//zb + ya = zb + y(qb+r) == b + yqb + yr = (yq+z)b + yr
	//yq + z = x
	//z = x - yq
	return {ret.second, ret.first - ret.second*q};
}