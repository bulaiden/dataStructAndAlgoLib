static long MOD = ???;

//in modular arithmetic, the division operation doesn't exist. So mmi replaces it.
//x only has a mmi if x and MOD are relatively prime.
//It doesn't necessarily suffice for x to be prime. For example x = 5 and MOD = 15.
//a^-1 == a^(m-2) mod m //when a and m are relatively prime
static long mmi(long x){
	return power(x, MOD-2);
}

static long power(long x, long y){ return _power(x % MOD, y); }
static long _power(long x, long y){
	if(y == 0) return 1;
	long p = _power(x, y/2)%MOD;
	p = (p*p)%MOD;
	return (y%2 == 0) ? p : (x*p)%MOD;
}

