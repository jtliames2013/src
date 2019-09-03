205. Isomorphic Strings Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 98419
Total Submissions: 297148
Difficulty: Easy
Contributor: LeetCode
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.

Subscribe to see which companies asked this question.

Hide Tags Hash Table
Hide Similar Problems (E) Word Pattern

note case "ab" -> "aa"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        if (n!=t.size()) return false;
        unordered_map<char,char> mp;
        unordered_set<char> st;
        for (int i=0; i<n; i++) {
            if (mp.find(s[i])!=mp.end()) {
                if (mp[s[i]]!=t[i]) return false;
            } else {
                if (st.find(t[i])!=st.end()) return false;
                mp[s[i]]=t[i];
                st.insert(t[i]);
            }
        }
        
        return true;
    }
};

