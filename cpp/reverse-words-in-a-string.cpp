151. Reverse Words in a String  QuestionEditorial Solution  My Submissions
Total Accepted: 112874 Total Submissions: 715351 Difficulty: Medium
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.
Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
Hide Company Tags Microsoft Snapchat Apple Bloomberg Yelp
Hide Tags String
Hide Similar Problems (M) Reverse Words in a String II

class Solution {
public:
    void reverseWords(string &s) {
        int n=s.size();
        reverse(s.begin(), s.end());
        for (int i=0; i<n; i++) {
            if (s[i]!=' ') {
                int j=i+1;
                while (j<n && s[j]!=' ') j++;
                reverse(s.begin()+i, s.begin()+j);
                i=j;
            }
        }
        
        int end=0;
        for (int i=0; i<n; i++) {
            if (s[i]!=' ' || (i>0 && s[i-1]!=' ')) {
                if (i!=end) {
                    s[end]=s[i];
                }
                end++;
            }
        }
        
        // remove last space if there is        
        s.resize(end);
        if (s.back()==' ') s.pop_back();
    }
};

