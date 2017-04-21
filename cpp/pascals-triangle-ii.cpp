119. Pascal's Triangle II Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 109718
Total Submissions: 305625
Difficulty: Easy
Contributor: LeetCode
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

Subscribe to see which companies asked this question.

Hide Tags Array
Hide Similar Problems (E) Pascal's Triangle

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 0);
        res[0]=1;
        for (int i=1; i<=rowIndex; i++) {
            for (int j=i; j>0; j--) {
                res[j]+=res[j-1];
            }
        }
        
        return res;
    }
};

