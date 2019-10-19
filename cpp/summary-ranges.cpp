228. Summary Ranges  QuestionEditorial Solution  My Submissions
Total Accepted: 51019 Total Submissions: 201117 Difficulty: Medium
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Array
Hide Similar Problems (M) Missing Ranges (H) Data Stream as Disjoint Intervals

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int l=0, r=0, n=nums.size();
        if (n==0) return res;

        for (; r<n; ++r) {
            if (r==n-1 || nums[r]+1<nums[r+1]) {
                res.push_back(convert(nums[l], nums[r]));
                l=r+1;
            }
        }
        
        return res;
    }
private:
    string convert(int left, int right) {
        if (left==right) return to_string(left);
        else return to_string(left)+"->"+to_string(right);
    }
};
