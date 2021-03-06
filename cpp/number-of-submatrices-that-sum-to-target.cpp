1074. Number of Submatrices That Sum to Target
Hard

187

11

Favorite

Share
Given a matrix, and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

 

Example 1:

Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
 

Note:

1 <= matrix.length <= 300
1 <= matrix[0].length <= 300
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int res=0, m=matrix.size(), n=matrix[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=1; j<n; ++j) matrix[i][j]+=matrix[i][j-1];
        }
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<=i; ++j) {
                unordered_map<int,int> mp;
                mp[0]=1;
                int sum=0;
                for (int k=0; k<m; ++k) {
                    sum+=matrix[k][i]-(j>0?matrix[k][j-1]:0);
                    res+=mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        return res;
    }
};
