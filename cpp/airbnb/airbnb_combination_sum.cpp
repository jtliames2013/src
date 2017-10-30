39. Combination Sum  
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
Hide Company Tags Snapchat Uber
Hide Tags Array Backtracking
Show Similar Problems

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    void getSum(vector<vector<int>>& res, vector<int>& candidates, vector<int>& output, int target, int start) {
        if (target==0) {
            res.push_back(output);
            return;
        }
        
        for (int i=start; i<candidates.size(); i++) {
            if (target>=candidates[i]) {
                output.push_back(candidates[i]);
                getSum(res, candidates, output, target-candidates[i], i);
                output.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> output;
        getSum(res, candidates, output, target, 0);
        
        return res;
    }
};

40. Combination Sum II  QuestionEditorial Solution  My Submissions
Total Accepted: 76680 Total Submissions: 266337 Difficulty: Medium
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

class Solution {
public:
    void getSum(vector<vector<int>>& res, vector<int>& candidates, vector<int>& sum, int target, int start) {
        if (target==0) {
            res.push_back(sum);
            return;
        }
        
        for (int i=start; i<candidates.size(); i++) {
            if (target>=candidates[i] && (i==start || candidates[i]!=candidates[i-1])) {
                sum.push_back(candidates[i]);
                getSum(res, candidates, sum, target-candidates[i], i+1);
                sum.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sum;
        sort(candidates.begin(), candidates.end());
        getSum(res, candidates, sum, target, 0); 
        return res;
    }
};

216. Combination Sum III  QuestionEditorial Solution  My Submissions
Total Accepted: 39133 Total Submissions: 102693 Difficulty: Medium
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

class Solution {
public:
    void getSum(vector<vector<int>>& res, vector<int>& sum, int k, int n, int digit) {
        if (sum.size()==k && n==0) {
            res.push_back(sum);
            return;
        }
        
        for (int i=digit; i<=9; i++) {
            if (sum.size()<k && n>=i) {
                sum.push_back(i);
                getSum(res, sum, k, n-i, i+1);
                sum.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> sum;
        getSum(res, sum, k, n, 1);
        return res;
    }
};


