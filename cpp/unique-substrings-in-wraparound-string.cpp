467. Unique Substrings in Wraparound String Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 5752
Total Submissions: 18278
Difficulty: Medium
Contributors:
ramanjot
Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s. In particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.

Note: p consists of only lowercase English letters and the size of p might be over 10000.

Example 1:
Input: "a"
Output: 1

Explanation: Only the substring "a" of string "a" is in the string s.
Example 2:
Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.

Example 3:
Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> count(26);
        int len;
        for (int i=0; i<p.size(); i++) {
            if (i>0 && (p[i]==p[i-1]+1 || (p[i]=='a' && p[i-1]=='z'))) {
                len++;
            } else {
                len=1;
            }
            count[p[i]-'a']=max(count[p[i]-'a'], len);
        }
        
        int res=0;
        for (auto c:count) res+=c;
        return res;
    }
};

