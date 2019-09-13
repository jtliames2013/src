118. Pascal's Triangle Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 124321
Total Submissions: 330472
Difficulty: Easy
Contributor: LeetCode
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
Subscribe to see which companies asked this question.

Hide Tags Array
Hide Similar Problems (E) Pascal's Triangle II

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i=0; i<numRows; ++i) {
            vector<int> v(i+1);
            v[0]=v[i]=1;
            for (int j=1; j<i; ++j) {
                v[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(v);
        }
        return res;
    }
};
