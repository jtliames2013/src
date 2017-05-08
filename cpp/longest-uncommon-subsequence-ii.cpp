522. Longest Uncommon Subsequence II Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 2738
Total Submissions: 9455
Difficulty: Medium
Contributors:
love_Fawn
Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3
Note:

All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].
Subscribe to see which companies asked this question.

Hide Tags String
Hide Similar Problems (E) Longest Uncommon Subsequence I

class Solution {
public:
    bool isSubseq(string& s1, string& s2) {
        if (s1.size()>s2.size()) return false;
        int i=0;
        for (auto c:s2) {
            if (i==s1.size()) return true;
            if (s1[i]==c) i++;
        }
        return i==s1.size();
    }
    
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](string& a, string& b) { return a.size()>b.size(); } );
        for (int i=0; i<strs.size(); i++) {
            int j;
            for (j=0; j<strs.size(); j++) {
                if (j!=i && isSubseq(strs[i], strs[j])) break;
            }
            if (j==strs.size()) return strs[i].size();
        }
        return -1;
    }
};
