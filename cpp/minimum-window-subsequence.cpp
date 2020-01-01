727. Minimum Window Subsequence
Hard

440

20

Add to List

Share
Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:

Input: 
S = "abcdebdde", T = "bde"
Output: "bcde"
Explanation: 
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.
 

Note:

All the strings in the input will only contain lowercase letters.
The length of S will be in the range [1, 20000].
The length of T will be in the range [1, 100].

Google
|
8

Amazon
|
2

Bloomberg
|
2

Microsoft
|
2

Houzz
|
2

eBay
|
LeetCode

class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size(), n=t.size(), start, end, minLen=INT_MAX, sIdx=0, tIdx=0;
        while (sIdx<m) {
            if (s[sIdx]==t[tIdx]) {
                tIdx++;
                if (tIdx==n) {
                    end=sIdx;
                    tIdx--;
                    while (tIdx>=0) {
                        if (s[sIdx]==t[tIdx]) tIdx--;                        
                        sIdx--;
                    }
                    sIdx++;
                    tIdx++;
                    if (end-sIdx+1<minLen) {
                        start=sIdx;
                        minLen=end-sIdx+1;                        
                    }
                }                
            }
            sIdx++;
        }
        return minLen==INT_MAX?"":s.substr(start, minLen);
    }
};

