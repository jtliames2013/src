254. Factor Combinations
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Examples: 
input: 1
output: 
[]
input: 37
output: 
[]
input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& output, int n, int start) {
        if (output.size()>0) {
            output.push_back(n);
            res.push_back(output);
            output.pop_back();
        }
        
        for (int i=start; i*i<=n; i++) {
            if (n%i==0) {
                output.push_back(i);
                dfs(res, output, n/i, i);
                output.pop_back();
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) {
       vector<vector<int>> res;
       vector<int> output;
       dfs(res, output, n, 2);
       
       return res;
    }
};

