680. Valid Palindrome II
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

class Solution {
public:
    bool validPalin(string& s, int start, int end, int del) {
        while (start<end) {
            if (s[start]!=s[end]) {
                if (del==0) return false;
                else {
                    return validPalin(s, start+1, end, del-1) || validPalin(s, start, end-1, del-1);
                }
            } else {
                start++;
                end--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        if (n==0) return true;
        return validPalin(s, 0, n-1, 1);
    }
};

