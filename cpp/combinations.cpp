77. Combinations  
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Hide Tags Backtracking
Hide Similar Problems (M) Combination Sum (M) Permutations

class Solution {
public:
    void getComb(vector<vector<int>>& res, vector<int>& output, int n, int k, int start) {
        if (k==0) {
            res.push_back(output);
            return;
        }
        for (int i=start; i+k<=n; i++) {
            output.push_back(i+1);
            getComb(res, output, n, k-1, i+1);
            output.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> output;
        getComb(res, output, n, k, 0);
        
        return res;
    }
};

