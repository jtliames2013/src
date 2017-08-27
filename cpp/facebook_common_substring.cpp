49. 找出两个给出两个string, leetcode, codyabc和一个数字k = 3,问两个string里面存不存在连续的common substring大于等于k.比如这个例子，两个string都有cod,所以返回true。楼主用dp建了一个m*n的table秒了，然后写test case,发现有个小corner case,改了,pass

class Solution {
public:
	bool commonSubstring(string a, string b, int k) {
		int m=a.size(), n=b.size();
		if (m==0 || n==0) return false;
		vector<vector<int>> dp(m, vector<int>(n));
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				if (a[i]==b[j]) {
					dp[i][j]=1;
					if (i>0 && j>0) dp[i][j]+=dp[i-1][j-1];
				} else {
					dp[i][j]=0;
				}
				if (dp[i][j]>=k) return true;
			}
		}

		return false;
	}
};

int main()
{
	Solution s;
	//string a="leetcode";
	//string b="codyabc";
	string a="abcdefg";
	string b="hijklmn";

	cout << s.commonSubstring(a, b, 3) << endl;
	return 0;
}

