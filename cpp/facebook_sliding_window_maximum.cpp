给一个array，还有一个windows size。 滑动window，求最大。 follow up，一样的参数，要求是从array里选3个windows，求所有windows的item sum最大，window 不能相互重合。

这个二维表的行是假设有nn个subarray, nn就是  行index+1

DP(nn, i) = Max(DP(nn-1, i-k)+sum(i-k, i), DP(nn, i-1))
这个是状态转移方程， DP是有subarray的个数下，从0到i的最大值。sum(i-k, i)是元素从i-k到i的累加和

class Solution {
public:
	// n - number of windows, k -size of window
	int maximumNWindowsSum(vector<int> nums, int k, int n) {
		int m=nums.size();
		vector<int> dp(m), prev(m), idx(m);
		for (int i=0; i<n; i++) {
			int sum=0;
			for (int j=i*k; j<m; j++) {
				sum+=nums[j];
				if (j==(i+1)*k-1) dp[j]=sum;
				if (j>=(i+1)*k) {
					sum-=nums[j-k];
					//dp[j]=max(dp[j-1], prev[j-k]+sum);
					if (prev[j-k]+sum>=dp[j-1]) {
						dp[j]=prev[j-k]+sum;
						idx[j]=1;
					} else {
						dp[j]=dp[j-1];
					}
				}
			}
			prev=dp;
		}
		for (int i=m-1; i>=0;) {
			if (idx[i]==0) i--;
			else {
				cout << i-k+1 << " " << i << endl;
				i-=2;
			}
		}
		return prev[m-1];
	}
};

int main()
{
	Solution s;
	vector<int> nums={1,2,1,2,6,7,5,1};
	cout << s.maximumNWindowsSum(nums, 2, 3) << endl;
	return 0;
}

