就一道题，设计一个Ｐrime的class，里面有个方法upＴo返回从１到n的所有质数。
然后再写test　case。
写完test　case就问哪些line　of　code可以不要，之前看有人说square喜欢code的简洁，宁愿牺牲一些些得effiency，果然如此。面试官说除非真的很影响效率，不然真的是code越少越好。。。

class Solution {
public:
	vector<int> getPrimes(int n) {
		vector<int> res;
		if (n<2) return res;
		vector<bool> isPrime(n+1, true);
		for (int i=2; i*i<n+1; i++) {
			if (isPrime[i]) {
				for (int j=i*i; j<n+1; j+=i) {
					isPrime[j]=false;
				}
			}
		}

		for (int i=2; i<n+1; i++) {
			if (isPrime[i]) res.push_back(i);
		}

		return res;
	}
};

int main(int argc, char** argv) {
	Solution s;
	vector<int> res=s.getPrimes(100);
	return 0;
}

