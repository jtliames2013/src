336. Palindrome Pairs  
Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Company Tags Google Airbnb
Hide Tags Hash Table String Trie
Hide Similar Problems (M) Longest Palindromic Substring (H) Shortest Palindrome

use set to avoid the case where two words are revert of each other.

class Solution {
public:
    bool isPalin(string& s) {
        int l=0, r=(int)s.size()-1;    
        while (l<r) {
            if (s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string,int> mp;
        for (int i=0; i<words.size(); i++) mp[words[i]]=i;
        
        for (int i=0; i<words.size(); i++) {
            // skip empty string            
            if (words[i].empty()) continue;

            // abcd
            // left from "" to "abc"
            // right from "abcd" to "d"
            for (int j=0; j<words[i].size(); j++) {
                string left=words[i].substr(0, j);
                string right=words[i].substr(j);
                
                if (isPalin(left)) {
                    string rev=right;
                    reverse(rev.begin(), rev.end());
                    auto iter=mp.find(rev);
                    // note order of index.
                    // if left is empty and if word is palindrome, it'll find the word itself
                    // and we don't want to include it
                    if (iter!=mp.end() && iter->second!=i) res.push_back({iter->second, i});
                }
                
                if (isPalin(right)) {
                    string rev=left;
                    reverse(rev.begin(), rev.end());
                    auto iter=mp.find(rev);
                    // note order of index                    
                    if (iter!=mp.end()) {
                        res.push_back({i, iter->second});
                        // if word is palindrome, "" can be both before or after it                        
                        if (left.empty()) res.push_back({iter->second, i});
                    }
                }
            }
        }
        return res;
    }
};

