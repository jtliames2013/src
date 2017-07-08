string encode(int n) {
	string res;
	vector<int> fib={1,2};
	int i=2;
	for (; fib.back()<=n; i++) {
		fib.push_back(fib[i-1]+fib[i-2]);
	}
	res.resize(i);
	int end=i-1;
	i-=2;

	while (n>0) {
		res[i]='1';
		n-=fib[i];
		i--;
		while (i>=0 && fib[i]>n) {
			res[i]='0';
			i--;
		}
	}
	res[end]='1';
	return res;
}
