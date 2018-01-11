216. Combination Sum III  
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Hide Tags Array Backtracking
Hide Similar Problems (M) Combination Sum

class Solution {
public:
    void getSum(vector<vector<int>>& res, vector<int>& output, int k, int n, int start) {
        if (k==0) {
            if (n==0) res.push_back(output);
            return;
        }    
        
        for (int i=start; i<=9; i++) {
            if (n-i>=0) {
                output.push_back(i);
                getSum(res, output, k-1, n-i, i+1);
                output.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k==0) return res;
        vector<int> output;
        getSum(res, output, k, n, 1);
        
        return res;
    }
};

