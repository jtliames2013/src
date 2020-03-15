1380. Lucky Numbers in a Matrix
Easy

5

0

Add to List

Share
Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5.
All elements in the matrix are distinct.

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size(), n=matrix[0].size();
        vector<int> rowMin(m, INT_MAX), colMax(n, INT_MIN);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                rowMin[i]=min(rowMin[i], matrix[i][j]);
                colMax[j]=max(colMax[j], matrix[i][j]);
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]==rowMin[i] && matrix[i][j]==colMax[j]) res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};

