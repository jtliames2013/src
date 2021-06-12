1886. Determine Whether Matrix Can Be Obtained By Rotation
Easy

122

19

Add to List

Share
Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

 

Example 1:


Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
Example 2:


Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false
Explanation: It is impossible to make mat equal to target by rotating mat.
Example 3:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
 

Constraints:

n == mat.length == target.length
n == mat[i].length == target[i].length
1 <= n <= 10
mat[i][j] and target[i][j] are either 0 or 1.

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<bool> res(4, true);
        int n=mat.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (mat[i][j]!=target[i][j]) res[0]=false;
                if (mat[i][j]!=target[j][n-i-1]) res[1]=false;
                if (mat[i][j]!=target[n-i-1][n-j-1]) res[2]=false;
                if (mat[i][j]!=target[n-j-1][i]) res[3]=false;
            } 
        }
        return res[0] || res[1] || res[2] || res[3];
    }
};

