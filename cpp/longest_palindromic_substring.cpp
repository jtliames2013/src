5. Longest Palindromic Substring  QuestionEditorial Solution  My Submissions
Total Accepted: 123340 Total Submissions: 520502 Difficulty: Medium
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Hide Company Tags Amazon Microsoft Bloomberg
Hide Tags String
Hide Similar Problems (H) Shortest Palindrome (E) Palindrome Permutation (H) Palindrome Pairs

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if (n<=1) return s;
        int start, end, longest=0, l, r;
        for (int i=0; i<n-1; ++i) {
            for (int j=0; j<2; ++j) {
                if (j==0) {
                    l=r=i;
                } else {
                    l=i;
                    r=i+1;
                }
                while (l>=0 && r<n) {
                    if (s[l]!=s[r]) break;
                    --l;
                    ++r;
                }
                if (longest<r-l-1) {
                    longest=r-l-1;
                    start=l+1;
                    end=r-1;
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};

