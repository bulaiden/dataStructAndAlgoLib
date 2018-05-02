//random shuffle

void fisherYatesShuffle(vector<int>& a){
	for(int i=a.size(); i>0; i--){
		int p = rand() % i;
		swap(a[p], a[i-1]);
	}
}