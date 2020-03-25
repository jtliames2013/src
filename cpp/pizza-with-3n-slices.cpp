1388. Pizza With 3n Slices
Hard

105

2

Add to List

Share
There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick next slice in anti clockwise direction of your pick. 
Your friend Bob will pick next slice in clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Sizes of Pizza slices is represented by circular array slices in clockwise direction.

Return the maximum possible sum of slice sizes which you can have.

 

Example 1:



Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
Example 2:



Input: slices = [8,9,8,6,1,1]
Output: 16
Output: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.
Example 3:

Input: slices = [4,1,2,5,8,3,1,9,7]
Output: 21
Example 4:

Input: slices = [3,1,2]
Output: 3
 

Constraints:

1 <= slices.length <= 500
slices.length % 3 == 0
1 <= slices[i] <= 1000

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int m=slices.size(), n=m/3;
        return max(linear(slices, 0, m-1,  n), linear(slices, 1, m-1, n));
    }
private:
    int linear(vector<int>& slices, int start, int len, int n) {
        int res=INT_MIN;
        vector<vector<int>> dp(len+1, vector<int>(n+1, INT_MIN));
        for (int i=0; i<=len; ++i) dp[i][0]=0;
        for (int i=1; i<=len; ++i) {
            for (int j=1; j<=n; ++j) {
                dp[i][j]=max(dp[i-1][j], (i>=2?dp[i-2][j-1]:0)+slices[i-1+start]);
            }
            res=max(res, dp[i][n]);
        }
        return res;
    }
};

