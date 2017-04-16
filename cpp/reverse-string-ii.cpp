541. Reverse String II Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 8915
Total Submissions: 20394
Difficulty: Easy
Contributors:
Stomach_ache
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
Subscribe to see which companies asked this question.

Hide Tags String
Hide Similar Problems (E) Reverse String (E) Reverse Words in a String III

class Solution {
public:
    string reverseStr(string s, int k) {
        if (k<=0) return s;
        int n=s.size();
        for (int i=0; i<n; i+=2*k) {
            reverse(s.begin()+i, s.begin()+min(i+k, n));
        }
        return s;
    }
};
