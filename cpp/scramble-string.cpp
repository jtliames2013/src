87. Scramble String  QuestionEditorial Solution  My Submissions
Total Accepted: 50846 Total Submissions: 185846 Difficulty: Hard
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Hide Tags Dynamic Programming String

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size()!=s2.size()) return false;
        int count[26]={0};
        for (auto c:s1) count[c-'a']++;
        for (auto c:s2) count[c-'a']--;
        for (int i=0; i<26; i++) {
            if (count[i]!=0) return false;
        }
        
        int n=s1.size();
        if (n==1) return s1==s2;
        for (int i=0; i<n-1; ++i) {
            if (isScramble(s1.substr(0,i+1), s2.substr(0,i+1)) && 
                isScramble(s1.substr(i+1), s2.substr(i+1))) return true;
            if (isScramble(s1.substr(0,i+1), s2.substr(n-i-1)) && 
                isScramble(s1.substr(i+1), s2.substr(0,n-i-1))) return true;
        }
        return false;
    }
};

