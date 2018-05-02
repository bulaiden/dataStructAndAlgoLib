//computes all occurences of t in a in linear time.

//Z-Algorithm details:
//for each prefix of s, computes the longest proper prefix-suffix.
//prefix-suffix is a substring which is both a prefix and a suffix.
//longest proper prefix-suffix of a string is the longest prefix-suffix that excludes the string itself.

//logic:
//the longest proper prefix-suffix for length i prefix == the longest proper prefix-suffix for
// length i-1 prefix that can be extended by 1 char
// Or empty string if none of them can be extended
//next longest proper prefix-suffix == longest proper prefix-suffix of longest proper prefix-suffix
//notice that overlap of prefix and suffix does not affect the logic.

vector<int> Z_Algorithm(string a, string t){
    string s = t + "#" + a; //# is some unmatchable char
    int n = s.size(), m = t.size();
    vector<int> z(n), res;

    for(int i=1, w=0; i<n; i++){
        while(w && s[w] != s[i]) w = z[w];
        if(s[w] == s[i]) w++;
        z[i] = w;
    }

    for(int i=m+1; i<n; i++)
        if(z[i] == m) res.push_back(i-m+1-(m+1));
    return res;
}