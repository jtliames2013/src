159. Longest Substring with At Most Two Distinct Characters
Medium

695

14

Add to List

Share
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.

Google
|
7

Amazon
|
3

Microsoft
|
2

Adobe
|
2

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res=0, start=0, n=s.size();
        unordered_map<char,int> mp;
        for (int i=0; i<n; i++) {
            mp[s[i]]=i;
            if (mp.size()>2) {
                res=max(res, i-start);
                int idx=INT_MAX;
                char ch;
                for (auto& iter:mp) {
                    if (iter.second<idx) {
                        idx=iter.second;
                        ch=iter.first;
                    }    
                }
                mp.erase(ch);
                start=idx+1;
            }
        }
        res=max(res, n-start);
        
        return res;
    }
};

