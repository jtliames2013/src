1198. Find Smallest Common Element in All Rows
Medium

53

5

Favorite

Share
Given a matrix mat where every row is sorted in increasing order, return the smallest common element in all rows.

If there is no common element, return -1.

 

Example 1:

Input: mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
Output: 5
 

Constraints:

1 <= mat.length, mat[i].length <= 500
1 <= mat[i][j] <= 10^4
mat[i] is sorted in increasing order.

Microsoft
|
LeetCode

1. binary search
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        for (int i=0; i<n; ++i) {
            bool common=true;
            for (int j=1; j<m; ++j) {
                if (!binary_search(mat[j].begin(), mat[j].end(), mat[0][i])) {
                    common=false;
                    break;
                }
            }
            if (common) return mat[0][i];
        }
        return -1;
    }
};

2.
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        unordered_map<int, int> mp;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                mp[mat[i][j]]++;
                if (mp[mat[i][j]]==m) return mat[i][j];
            }
        }
        return -1;
    }
};

