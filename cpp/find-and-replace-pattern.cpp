890. Find and Replace Pattern
Medium

439

45

Favorite

Share
You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern. 

You may return the answer in any order.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
 

Note:

1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (auto& w:words) {
            if (match(w, pattern)) res.push_back(w);
        }
        return res;
    }
private:
    bool match(string& word, string& pattern) {
        if (word.size()!=pattern.size()) return false;
        vector<int> w(26), p(26);
        for (int i=0; i<word.size(); ++i) {
            if (w[word[i]-'a']!=p[pattern[i]-'a']) return false;
            else w[word[i]-'a']=p[pattern[i]-'a']=i+1;
        }
        return true;
    }
};
