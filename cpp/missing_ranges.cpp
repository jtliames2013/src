163. Missing Ranges  QuestionEditorial Solution  My Submissions
Total Accepted: 13045 Total Submissions: 43520 Difficulty: Medium
Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

Hide Company Tags Google
Hide Tags Array
Hide Similar Problems (M) Summary Ranges

class Solution {
public:
    string getRange(int start, int end) {
        return start==end?to_string(start):to_string(start)+"->"+to_string(end);
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long start=lower;
        
        for (long n:nums) {
            if (n-1>=start) res.push_back(getRange(start, n-1));                             
            start=n+1;
        }
        if (upper>=start) res.push_back(getRange(start, upper));
        
        return res;
    }
};

