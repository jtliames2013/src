472. Concatenated Words Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 5251
Total Submissions: 17783
Difficulty: Hard
Contributors:
fishercoder
Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.
Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming Trie Depth-first Search
Hide Similar Problems (H) Word Break II

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> st(words.begin(), words.end());
        
        for (auto& w:words) {
            int n=w.size();
            vector<bool> dp(n+1);
            dp[0]=true;
            for (int i=0; i<n; i++) {
                if (dp[i]) {
                    for (int j=i+1; j<=n; j++) {
                        if (j-i<n && st.find(w.substr(i, j-i))!=st.end()) dp[j]=true;
                    }
                    if (dp[n]) {
                        res.push_back(w);
                        break;
                    }
                }
            }
        }
        return res;
    }
};

