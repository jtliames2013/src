647. Palindromic Substrings
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(), res=0;        
        for (int i=0; i<n; i++) {
            int l, r;
            for (int j=0; j<2; j++) {
                if (j==0) {
                    l=r=i;
                } else {
                    l=i;
                    r=i+1;
                }
                while (l>=0 && r<n) {                    
                    if (s[l]!=s[r]) break;
                    res++;
                    l--;
                    r++;
                }
            }
        }
        return res;
    }
};

