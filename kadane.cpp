//computes the maximum sum subarray in linear time.

//kadane computes the maximum sum suffix for each length prefix.

vector<int> kadane(vector<int> a){
    vector<int> ret(a);
    for(int i=1; i<a.size(); i++)
        ret[i] += max(ret[i-1], 0);
    return ret;
}