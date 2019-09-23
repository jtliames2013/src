1072. Flip Columns For Maximum Number of Equal Rows
Medium

124

12

Favorite

Share
Given a matrix consisting of 0s and 1s, we may choose any number of columns in the matrix and flip every cell in that column.  Flipping a cell changes the value of that cell from 0 to 1 or from 1 to 0.

Return the maximum number of rows that have all values equal after some number of flips.

 

Example 1:

Input: [[0,1],[1,1]]
Output: 1
Explanation: After flipping no values, 1 row has all values equal.
Example 2:

Input: [[0,1],[1,0]]
Output: 2
Explanation: After flipping values in the first column, both rows have equal values.
Example 3:

Input: [[0,0,0],[0,0,1],[1,1,0]]
Output: 2
Explanation: After flipping values in the first two columns, the last two rows have equal values.
 

Note:

1 <= matrix.length <= 300
1 <= matrix[i].length <= 300
All matrix[i].length's are equal
matrix[i][j] is 0 or 1

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int res=0;
        unordered_map<string, int> mp;
        for (auto& row:matrix) {
            int n=row.size();
            string r1(n, '0'),  r2(n, '0');
            for (int i=0; i<n; ++i) {
                r1[i]+=row[i];
                r2[i]+=1-row[i];
            }
            mp[r1]++;
            mp[r2]++;
        }
        
        for (auto iter:mp) res=max(res, iter.second);
        return res;
    }
};
