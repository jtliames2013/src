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

Microsoft
|
3

Facebook
|
2

Amazon
|
LeetCode

Uber
|
LeetCode

class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n=s.size();
        reverse(s.begin(), s.end());
        for (int i=0; i<n; ) {
            if (s[i]==' ') i++;
            else {
                int j=i+1;
                while (j<n && s[j]!=' ') j++;
                reverse(s.begin()+i, s.begin()+j);
                i=j;
            }
        }
    }
};

