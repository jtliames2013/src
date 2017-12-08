micable pair，要求pair中第一个数小于第二个数

 int sumDivisor(int num) {
	 int sum=1;
	 int end=(int)sqrt(num);
	 for (int i=2; i<=end; i++) {
		 if (num%i==0) {
			 sum+=i;
			 sum+=num/i;
		 }
	 }
	 return sum;
 }

 vector<pair<int, int>> findAmicable(int n) {
	 vector<pair<int, int>> res;
	 vector<int> sum(n, 0);
	 for (int i=0; i<n; i++) {
		 sum[i]=sumDivisor(i+1);
	 }
	 for (int i=0; i<n; i++) {
		 if (sum[i]<=n && sum[sum[i]-1]==i+1 && sum[i]>i+1) {
			 res.push_back({i+1, sum[i]});
		 }
	 }

	 return res;
 }

int main() {
	vector<pair<int, int>> res=findAmicable(1300);
	return 0;
}

