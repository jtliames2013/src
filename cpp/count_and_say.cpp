38. Count and Say
DescriptionHintsSubmissionsSolutions
Total Accepted: 133708
Total Submissions: 394831
Difficulty: Easy
Contributor: LeetCode
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
Subscribe to see which companies asked this question.

Hide Tags String
Hide Similar Problems (M) Encode and Decode Strings

class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        string prev="1", res;
        for (int i=2; i<=n; i++) {
            res.clear();
            for (int start=0, end=0; start<prev.size(); ) {
                while (end<prev.size() && prev[end]==prev[start]) end++;
                res+=to_string(end-start)+prev[start];
                start=end;
            }
            prev=res;
        }
        
        return res;
    }
};

