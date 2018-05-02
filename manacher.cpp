//computes the longest palindromic substring in linear time

//manacher computes the longest palindrome extending from each center pivot i

string manacher(string a){
    string s = "#";
    for(int i=0; i<a.size(); i++)
        s.push_back(a[i]), s.push_back('#');
    s = '^' + s + '$';

    int n = s.size();
    vector<int> dp(n);

    for(int i=1, j=0; i<n-1; i++){
        if(j+dp[j] >= i) dp[i] = min(j+dp[j]-i, dp[j-i+j]);
        while(s[i+dp[i]+1] == s[i-dp[i]-1]) dp[i]++;
        if(i+dp[i] > j+dp[j]) j = i;
    }
    
    int hi = distance(dp.begin(), max_element(dp.begin(), dp.end()));
    return a.substr((hi-1)/2-dp[hi]/2, dp[hi]);
}