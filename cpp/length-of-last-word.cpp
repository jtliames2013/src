58. Length of Last Word Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 137547
Total Submissions: 436878
Difficulty: Easy
Contributor: LeetCode
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

Subscribe to see which companies asked this question.

Hide Tags String

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int i, j;
        for (i=n-1; i>=0; i--) {
            if (s[i]!=' ') break;
        }
        for (j=i; j>=0; j--) {
            if (s[j]==' ') break;
        }
        
        return i-j;
    }
};

2.
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size(), i=n-1, j;
        for (; i>=0; --i) {
            if (s[i]!=' ') {
                j=i;
                while (j>=0 && s[j]!=' ') --j;
                return i-j;
            }
        }
        return 0;
    }
};
