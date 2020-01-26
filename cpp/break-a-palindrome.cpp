1328. Break a Palindrome
Medium

19

18

Add to List

Share
Given a palindromic string palindrome, replace exactly one character by any lowercase English letter so that the string becomes the lexicographically smallest possible string that isn't a palindrome.

After doing so, return the final string.  If there is no way to do so, return the empty string.

 

Example 1:

Input: palindrome = "abccba"
Output: "aaccba"
Example 2:

Input: palindrome = "a"
Output: ""
 

Constraints:

1 <= palindrome.length <= 1000
palindrome consists of only lowercase English letters.

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size(), mid=n/2;
        for (int i=0; i<mid; ++i) {
            if (palindrome[i]!='a') {
                palindrome[i]='a';
                return palindrome;
            }
        }

        if ((n%2==0 && n>0) || (n%2==1 && n>1)) {
            palindrome[n-1]='b';
            return palindrome;
        }
        return "";
    }
};

