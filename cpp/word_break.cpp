139. Word Break Add to List
DescriptionSubmissionsSolutions
Total Accepted: 137342
Total Submissions: 473014
Difficulty: Medium
Contributor: LeetCode
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.

Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming
Hide Similar Problems (H) Word Break II

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        if (n==0) return false;
        unordered_set<string> dict;
        for (auto w:wordDict) dict.insert(w);
        
        vector<bool> dp(n+1, false);
        dp[0]=true;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<i; j++) {
                if (dp[j] && dict.find(s.substr(j, i-j))!=dict.end()) {
                    dp[i]=true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};

