1504. Count Submatrices With All Ones
Medium

237

10

Add to List

Share
Given a rows * columns matrix mat of ones and zeros, return how many submatrices have all ones.

 

Example 1:

Input: mat = [[1,0,1],
              [1,1,0],
              [1,1,0]]
Output: 13
Explanation:
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
Example 2:

Input: mat = [[0,1,1,0],
              [0,1,1,1],
              [1,1,1,0]]
Output: 24
Explanation:
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3. 
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2. 
There are 2 rectangles of side 3x1. 
There is 1 rectangle of side 3x2. 
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
Example 3:

Input: mat = [[1,1,1,1,1,1]]
Output: 21
Example 4:

Input: mat = [[1,0,1],[0,1,0],[1,0,1]]
Output: 5
 

Constraints:

1 <= rows <= 150
1 <= columns <= 150
0 <= mat[i][j] <= 1

1.
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int res=0, m=mat.size(), n=mat[0].size();
        for (int i=0; i<m; ++i) {
            vector<int> mask(n, 1);
            for (int j=i; j>=0; --j) {
                for (int k=0; k<n; ++k) {
                    mask[k]&=mat[j][k];
                }
                res+=countOne(mask);
            }
        }
        return res;
    }
private:
    int countOne(vector<int>& mask) {
        int res=0, n=mask.size();
        for (int i=0, len=0; i<n; ++i) {
            len=mask[i]==1?len+1:0;
            res+=len;
        }

        return res;
    }
};

2.
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int res=0, m=mat.size(), n=mat[0].size();
        vector<int> count(n);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                count[j]=mat[i][j]==1?count[j]+1:0;
            }
            res+=countOne(count) ;
        }
        return res;
    }
private:
    int countOne(vector<int>& count) {
        int res=0, n=count.size();
        vector<int> sums(n), stk;
        for (int i=0; i<n; ++i) {
            while (!stk.empty() && count[i]<=count[stk.back()]) {
                stk.pop_back();
            }
            if (stk.empty()) sums[i]=count[i]*(i+1);
            else sums[i]=sums[stk.back()]+count[i]*(i-stk.back());
            stk.push_back(i);
        }

        for (auto& i:sums) res+=i;
        return res;
    }
};
