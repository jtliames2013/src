1048. Longest String Chain
Medium

226

15

Favorite

Share
Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
 

Note:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of English lowercase letters.

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int res=0, mx;
        unordered_map<string, int> mp;
        sort(words.begin(), words.end(), [](string& a, string& b){ return a.size()<b.size(); });
        
        for (auto& w:words) {
            mx=0;
            for (int i=0; i<w.size(); ++i) {
                string str=w.substr(0, i)+w.substr(i+1);
                mx=max(mx, mp[str]+1);
            }
            mp[w]=mx;
            res=max(res, mx);
        }
        return res;
    }
};
