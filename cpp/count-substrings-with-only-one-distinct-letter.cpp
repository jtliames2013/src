1180. Count Substrings with Only One Distinct Letter
Easy

15

3

Favorite

Share
Given a string S, return the number of substrings that have only one distinct letter.

 

Example 1:

Input: S = "aaaba"
Output: 8
Explanation: The substrings with one distinct letter are "aaa", "aa", "a", "b".
"aaa" occurs 1 time.
"aa" occurs 2 times.
"a" occurs 4 times.
"b" occurs 1 time.
So the answer is 1 + 2 + 4 + 1 = 8.
Example 2:

Input: S = "aaaaaaaaaa"
Output: 55
 

Constraints:

1 <= S.length <= 1000
S[i] consists of only lowercase English letters.

class Solution {
public:
    int countLetters(string S) {
        long res=0;
        int i=0, j, n=S.size();
        while (i<n) {
            j=i;
            while (j<n && S[j]==S[i]) j++;
            res+=(j-i)*(j-i+1)/2;
            i=j;
        }
        
        return res;
    }
};
