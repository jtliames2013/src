120. Triangle  QuestionEditorial Solution  My Submissions
Total Accepted: 76992 Total Submissions: 247542 Difficulty: Medium
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

Show Tags
Have you met this question in a real interview? Yes  No

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if (n==0) return 0;
        vector<int> dp=triangle[n-1];
        
        for (int i=n-2; i>=0; i--) {
            for (int j=0; j<=i; j++) {
                dp[j]=triangle[i][j]+min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};

