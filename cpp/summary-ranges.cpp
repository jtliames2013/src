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
        int n=nums.size();
        if (n==0) return res;
        int start=0;
        for (int i=1; i<n; i++) {
            if ((long long)nums[i]-(long long)nums[i-1]>1) {
                res.push_back(i-1==start?to_string(nums[start]):to_string(nums[start])+"->"+to_string(nums[i-1]));
                start=i;
            }
        }
        res.push_back(n-1==start?to_string(nums[start]):to_string(nums[start])+"->"+to_string(nums[n-1]));
        return res;
    }
};

2.
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n=nums.size();
        if (n==0) return res;
        int start;
        for (int i=0; i<n; i++) {
            start=i;
            while (i+1<n && nums[i+1]-nums[i]==1) i++;
            res.push_back(i==start?to_string(nums[start]):to_string(nums[start])+"->"+to_string(nums[i]));
        }
        
        return res;
    }
};
