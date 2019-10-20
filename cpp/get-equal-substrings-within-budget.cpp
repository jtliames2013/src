1208. Get Equal Substrings Within Budget
Medium

103

11

Favorite

Share
You are given two strings s and t of the same length. You want to change s to t. Changing the i-th character of s to i-th character of t costs |s[i] - t[i]| that is, the absolute difference between the ASCII values of the characters.

You are also given an integer maxCost.

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of twith a cost less than or equal to maxCost.

If there is no substring from s that can be changed to its corresponding substring from t, return 0.

 

Example 1:

Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum length is 3.
Example 2:

Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1
Explanation: Each character in s costs 2 to change to charactor in t, so the maximum length is 1.
Example 3:

Input: s = "abcd", t = "acde", maxCost = 0
Output: 1
Explanation: You can't make any change, so the maximum length is 1.
 

Constraints:

1 <= s.length, t.length <= 10^5
0 <= maxCost <= 10^6
s and t only contain lower case English letters.

1. sliding window always has cost less than maxCost
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res=0, n=s.size(), l=0, r=0, cost=0;
        for (; r<n; ++r) {
            cost+=abs(s[r]-t[r]);
            while (cost>maxCost) {
                cost-=abs(s[l]-t[l]);
                l++;
            }
            res=max(res, r-l+1);
        }
        return res;
    }
};

2. sliding window size grows whenever cost is less than maxCost
sliding window size remains the same if the condition violates
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size(), l=0, r=0, cost=0;
        for (; r<n; ++r) {
            cost+=abs(s[r]-t[r]);
            if (cost>maxCost) {
                cost-=abs(s[l]-t[l]);
                l++;
            }            
        }
        return r-l;
    }
};
