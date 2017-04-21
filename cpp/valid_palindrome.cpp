125. Valid Palindrome  QuestionEditorial Solution  My Submissions
Total Accepted: 123277 Total Submissions: 496004 Difficulty: Easy
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

Subscribe to see which companies asked this question

class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        if (n==0) return true;
        int l=0, r=n-1;
        while (l<r) {
            if (!isalnum(s[l])) l++;
            else if (!isalnum(s[r])) r--;
            else {
                if (tolower(s[l])!=tolower(s[r])) return false;
                l++;
                r--;
            }
        }
        
        return true;
    }
};

