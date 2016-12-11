3. Longest Substring Without Repeating Characters  
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

Hide Company Tags Amazon Adobe Bloomberg Yelp
Hide Tags Hash Table Two Pointers String
Hide Similar Problems (H) Longest Substring with At Most Two Distinct Characters

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if (n==0) return 0;
        int longest=INT_MIN;
        unordered_map<char,int> table;
        int l, r;
        for (l=0, r=0; r<n; r++) {
            if (table.find(s[r])!=table.end()) {
                longest=max(longest, r-l);
                for (int i=l; i<table[s[r]]; i++) table.erase(s[i]);
                l=table[s[r]]+1;
            }
            table[s[r]]=r;
        }
        longest=max(longest, r-l);
        
        return longest;
    }
};

2. Without hash table
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int size=s.size();
        int start=0, end=0;
        for (end=0; end<size; end++) {
            for (int i=start; i<end; i++) {
                if (s[i]==s[end]) {
                    start=i+1;
                    break;
                }
            }
            res=max(res, end-start+1);
        }

        return res;
    }
};

int main()
{
	return 0;
}

