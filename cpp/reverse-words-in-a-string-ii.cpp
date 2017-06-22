186. Reverse Words in a String II
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

Related problem: Rotate Array

class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty()) return;
        reverse(s.begin(), s.end());
        
        for (int i=0; i<s.size();) {
            if (s[i]!=' ') {
                int j=i;
                while (j<s.size() && s[j]!=' ') j++;
                reverse(s.begin()+i, s.begin()+j);
                i=j;
            } else {
                i++;
            }
        }
    }
};

