给一个array，还有一个windows size。 滑动window，求最大。 follow up，一样的参数，要求是从array里选3个windows，求所有windows的item sum最大，window 不能相互重合。

这个二维表的行是假设有nn个subarray, nn就是  行index+1

DP(nn, i) = Max(DP(nn-1, i-k)+sum(i-k, i), DP(nn, i-1))
这个是状态转移方程， DP是有subarray的个数下，从0到i的最大值。sum(i-k, i)是元素从i-k到i的累加和

class Solution {
public:
	// m - number of windows, k -size of window
	int maximumNWindowsSum(vector<int> nums, int k, int m) {
        vector<int> res(3);
        int n=nums.size();
        vector<vector<int>> dp(3, vector<int>(n));
        for (int i=0; i<m; i++) {
            int sum=0;            
            for (int j=i*k; j<n; j++) {
                sum+=nums[j];                
                if (j>=(i+1)*k-1) {
                    if (j>=(i+1)*k) sum-=nums[j-k];
                    dp[i][j]=max(dp[i][j-1], (i>0?dp[i-1][j-k]:0)+sum);
                }
            }
        }
                
        for (int i=m; i>=0; i--) {
            for (int j=(i==2?n:res[i+1])-1; j>0; j--) {
                if (dp[i][j]!=dp[i][j-1]) {
                    res[i]=j-k+1;
                    break;
                }
            }
        }

        return dp[2][n-1];
	}
};

int main()
{
	Solution s;
	vector<int> nums={1,2,1,2,6,7,5,1};
	cout << s.maximumNWindowsSum(nums, 2, 3) << endl;
	return 0;
}

