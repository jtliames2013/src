459. Repeated Substring Pattern   QuestionEditorial Solution  My Submissions
Total Accepted: 1537
Total Submissions: 3839
Difficulty: Easy
Contributors: YuhanXu
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

Subscribe to see which companies asked this question

Hide Tags String
Hide Similar Problems (E) Implement strStr()

class Solution {
public:
    bool canRepeat(string& s, int len) {
        for (int i=0; i<s.size(); i+=len) {
            for (int j=0; j<len; j++) {
                if (s[i+j]!=s[j]) return false;
            }
        }    
        return true;
    }
    
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for (int i=n/2; i>0; i--) {
            if (n%i==0) {
                if (canRepeat(s, i)) return true;
            }
        }
        return false;
    }
};

