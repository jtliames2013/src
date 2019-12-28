1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
Medium

106

2

Add to List

Share
Given a m x n matrix mat and an integer threshold. Return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.

 

Example 1:


Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
Example 2:

Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
Output: 0
Example 3:

Input: mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
Output: 3
Example 4:

Input: mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], threshold = 40184
Output: 2
 

Constraints:

1 <= m, n <= 300
m == mat.length
n == mat[i].length
0 <= mat[i][j] <= 10000
0 <= threshold <= 10^5

Google
|
3

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size(), n=mat[0].size(), len=1;
        vector<vector<int>> sums(m+1, vector<int>(n+1));
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                sums[i][j]=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+mat[i-1][j-1];
                if (i>=len && j>=len && sums[i][j]-sums[i-len][j]-sums[i][j-len]+sums[i-len][j-len]<=threshold) len++;                
            }
        }
        return len-1;
    }
};

