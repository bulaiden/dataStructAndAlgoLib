//maxheap
class heap{

public:
	int n = 0;
	vector<int> a{0};

	heap(){ }

	heap(vector<int> b){
		n = b.size();
		a.insert(a.end(), b.begin(), b.end());
		heapify();
	}

private:
	//O(n) time
	//because in worst case, each element does h work (by being bubbledown to the bottom)
	//but there are exponentially less elements on the higher layers.
	//the summation is a convergent series.
	//sum(i/2^i)
	//so i guess you can prove by induction (showing it can never reach 2 or something)
	void heapify(){
		for(int i=n; i>=1; i--){
			bubbledown(i);
		}
	}
	void bubbleup(int i){
		while(i>>1 >= 1 && a[i] > a[i>>1]){
			swap(a[i], a[i>>1]);
			i>>=1;			
		}
	}
	void bubbledown(int i){
		while(true){
			int x = i;
			if(i<<1 <= n && a[i<<1] > a[x]) x = i<<1;
			if((i<<1)+1 <= n && a[(i<<1)+1] > a[x]) x = (i<<1)+1;
			swap(a[i], a[x]);
			if(i == x) break;
			i = x;
		}
	}

public:
	void push(int v){
		n++;
		a.push_back(v);
		bubbleup(n);
	}

	bool empty(){
		return !n;
	}

	int top(){
		if(empty()) throw runtime_error("heap is empty");
		return a[1];
	}

	void pop(){
		if(empty()) throw runtime_error("heap is empty");
		//safe for n == 1
		a[1] = a[n];
		n--;
		a.pop_back();
		if(!empty()) bubbledown(1);
	}
};
