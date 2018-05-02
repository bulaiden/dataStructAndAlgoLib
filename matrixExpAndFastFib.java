
static long MOD = ???;
//1000000007;

static long[][] identityMatrix(int n){
    long[][] g = new long[n][n];
    for(int i=0; i<n; i++){
        g[i][i] = 1;
    }
    return g;
}

static long[][] matrixExp(long[][] g, long t){
    matrixUnderMod(g);
    return _matrixExp(g, t);
}

//same strategy as integer exponentation
static long[][] _matrixExp(long[][] g, long t){
    if(t == 1) return g;
    int n = g.length;
    if(t == 0) return identityMatrix(n);
    long[][] h = _matrixExp(g, t/2);
    long[][] res = matrixMult(h, h);
    return (t%2 == 0) ? res : matrixMult(res, g);
}

//school textbook matrix multiplication
static long[][] matrixMult(long[][] x, long[][] y){
    matrixUnderMod(x);  matrixUnderMod(y);
    int k = y.length, h = x.length, w = y[0].length;

    long[][] res = new long[h][w];
    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            for(int d=0; d<k; d++)
                res[i][j] = (res[i][j] + x[i][d] * y[d][j]) % MOD;
    return res;
}

//makes all the values nonnegative and under modulo MOD
static void matrixUnderMod(long[][] g){
    int n = g.length;
    int m = g[0].length;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            g[i][j] = ((g[i][j] % MOD) + MOD) % MOD;
}

//using matrix exponentiation to solve fibonacci(t) in log(t) time
static long fastFibonacci(long t){
    long[][] mat = {{1, 1}, {1, 0}};
    long[][] matpow = matrixExp(mat, t);
    long[][] vector = {{1}, {0}};
    long[][] res = matrixMult(matpow, vector);
    return res[1][0];
}