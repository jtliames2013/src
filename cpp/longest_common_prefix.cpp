14. Longest Common Prefix  QuestionEditorial Solution  My Submissions
Total Accepted: 114633 Total Submissions: 391271 Difficulty: Easy
Write a function to find the longest common prefix string amongst an array of strings.

Hide Company Tags Yelp
Hide Tags String

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int end=0, n=strs.size();
        if (n==0) return "";
        
        while (1) {
            if (end==strs[0].size()) break;
            int i;
            for (i=1; i<n; i++) {
                if (strs[i][end]!=strs[0][end]) break;
            }
            if (i<n) break;
            end++;
        }
        
        return strs[0].substr(0, end);
    }
};

