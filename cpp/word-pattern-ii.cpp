291. Word Pattern II
Hard

363

24

Add to List

Share
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Example 1:

Input: pattern = "abab", str = "redblueredblue"
Output: true
Example 2:

Input: pattern = pattern = "aaaa", str = "asdasdasdasd"
Output: true
Example 3:

Input: pattern = "aabb", str = "xyzabcxzyabc"
Output: false
Notes:
You may assume both pattern and str contains only lowercase letters.

Uber
|
4

Pony.ai
|
2

Dropbox
|
2

Facebook
|
2

//We can solve this problem using backtracking, we just have to keep trying to use a character in the pattern to match different length of substrings in the input string, keep trying till we go through the input string and the pattern.
//
//For example, input string is "redblueredblue", and the pattern is "abab", first let's use 'a' to match "r", 'b' to match "e", then we find that 'a' does not match "d", so we do backtracking, use 'b' to match "ed", so on and so forth ...
//
//When we do the recursion, if the pattern character exists in the hash map already, we just have to see if we can use it to match the same length of the string. For example, let's say we have the following map:
//
//'a': "red"
//
//'b': "blue"
//
//now when we see 'a' again, we know that it should match "red", the length is 3, then let's see if str[i ... i+3] matches 'a', where i is the current index of the input string. Thanks to StefanPochmann's suggestion, in Java we can elegantly use str.startsWith(s, i) to do the check.
//
//Also thanks to i-tikhonov's suggestion, we can use a hash set to avoid duplicate matches, if character a matches string "red", then character b cannot be used to match "red". In my opinion though, we can say apple (pattern 'a') is "fruit", orange (pattern 'o') is "fruit", so they can match the same string, anyhow, I guess it really depends on how the problem states.
//
//The following code should pass OJ now, if we don't need to worry about the duplicate matches, just remove the code that associates with the hash set.

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> mp;
        unordered_set<string> st;
        return dfs(mp, st, pattern, 0, str, 0);
    }
private:
    bool dfs(unordered_map<char, string>& mp, unordered_set<string>& st, string& pattern, int pIdx, string& str, int sIdx) {
        if (pIdx==pattern.size() && sIdx==str.size()) return true;
        else if (pIdx==pattern.size() || sIdx==str.size()) return false;
        
        if (mp.find(pattern[pIdx])!=mp.end()) {
            string w=mp[pattern[pIdx]];
            if (str.substr(sIdx, w.size())!=w) return false;
            return dfs(mp, st, pattern, pIdx+1, str, sIdx+w.size());
        } else {
            for (int i=sIdx; i<str.size(); ++i) {
                string w=str.substr(sIdx, i-sIdx+1);
                if (st.find(w)!=st.end()) continue;
                mp[pattern[pIdx]]=w;
                st.insert(w);
                if (dfs(mp, st, pattern, pIdx+1, str, sIdx+w.size())) return true;
                mp.erase(pattern[pIdx]);
                st.erase(w);
            }
            return false;
        }
    }
};

