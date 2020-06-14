1478. Allocate Mailboxes
Hard

101

2

Add to List

Share
Given the array houses and an integer k. where houses[i] is the location of the ith house along a street, your task is to allocate k mailboxes in the street.

Return the minimum total distance between each house and its nearest mailbox.

The answer is guaranteed to fit in a 32-bit signed integer.

 

Example 1:



Input: houses = [1,4,8,10,20], k = 3
Output: 5
Explanation: Allocate mailboxes in position 3, 9 and 20.
Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 
Example 2:



Input: houses = [2,3,5,12,18], k = 2
Output: 9
Explanation: Allocate mailboxes in position 3 and 14.
Minimum total distance from each houses to nearest mailboxes is |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.
Example 3:

Input: houses = [7,4,6,1], k = 1
Output: 8
Example 4:

Input: houses = [3,6,14,10], k = 4
Output: 0
 

Constraints:

n == houses.length
1 <= n <= 100
1 <= houses[i] <= 10^4
1 <= k <= n
Array houses contain unique integers.

class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n=houses.size();
        sort(houses.begin(), houses.end());
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        vector<vector<int>> costs(n, vector<int>(n));
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                int mid=(i+j)/2;
                for (int h=i; h<=j; ++h) {
                    costs[i][j]+=abs(houses[h]-houses[mid]);
                }
            }
        }
        return dfs(dp, costs, 0, k, n);
    }
private:
    int dfs(vector<vector<int>>& dp, vector<vector<int>>& costs, int start, int k, int n) {
        if (start==n) return 0;
        if (k==0) return INT_MAX;
        if (dp[start][k]!=-1) return dp[start][k];
        int res=INT_MAX;
        for (int i=start; i<n; ++i) {
            int cost=dfs(dp, costs, i+1, k-1, n);
            if (cost!=INT_MAX) res=min(res, costs[start][i]+cost);
        }
        
        dp[start][k]=res;
        return dp[start][k];
    }
};
