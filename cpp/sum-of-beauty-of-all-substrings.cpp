1781. Sum of Beauty of All Substrings
Medium

134

59

Add to List

Share
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.

class Solution {
public:
    int beautySum(string s) {
        int res=0, n=s.size();
        for (int i=0; i<n; ++i) {
            vector<int> cnt(26);
            for (int j=i; j>=0; --j) {
                cnt[s[j]-'a']++;
                int mn=INT_MAX, mx=0;
                for (int k=0; k<26; ++k) {
                    if (cnt[k]>0) mn=min(mn, cnt[k]);
                    mx=max(mx, cnt[k]);
                }
                res+=mx-mn;
            }
        }
        return res;
    }
};

