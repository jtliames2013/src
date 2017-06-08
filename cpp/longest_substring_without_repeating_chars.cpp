3. Longest Substring Without Repeating Characters  
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

Hide Company Tags Amazon Adobe Bloomberg Yelp
Hide Tags Hash Table Two Pointers String
Hide Similar Problems (H) Longest Substring with At Most Two Distinct Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int n=s.size();
        if (n==0) return 0;
        unordered_map<char,int> mp;
        int l=0, r=0;
        for (; r<n; ++r) {
            if (mp.find(s[r])!=mp.end()) {
                res=max(res, r-l);
                for (int i=l; i<mp[s[r]]; ++i) mp.erase(s[i]);
                l=mp[s[r]]+1;
            }
            mp[s[r]]=r;
        }
        
        res=max(res, r-l);
        return res;
    }
};

2. Without hash table
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int n=s.size();
        if (n==0) return 0;
        for (int l=0, r=0; r<n; ++r) {
            for (int i=l; i<r; ++i) {
                if (s[i]==s[r]) {
                    l=i+1;
                    break;
                }
            }
            res=max(res, r-l+1);
        }
        
        return res;
    }
};

