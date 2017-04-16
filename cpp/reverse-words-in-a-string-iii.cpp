557. Reverse Words in a String III Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 6763
Total Submissions: 10670
Difficulty: Easy
Contributors:
joshpowell
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

Subscribe to see which companies asked this question.

Hide Tags String
Hide Similar Problems (E) Reverse String II

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        for (int i=0; i<n; i++) {
            if (s[i]!=' ') {
                int j=i+1;
                while (j<n && s[j]!=' ') j++;
                reverse(s.begin()+i, s.begin()+j);
                i=j;
            }
        }    
        return s;
    }
};
