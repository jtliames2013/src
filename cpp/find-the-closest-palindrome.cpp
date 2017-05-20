564. Find the Closest Palindrome Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 1390
Total Submissions: 8724
Difficulty: Hard
Contributors:
anvesh2
Given an integer n, find the closest integer (not including itself), which is a palindrome.

The 'closest' is defined as absolute difference minimized between two integers.

Example 1:
Input: "123"
Output: "121"
Note:
The input n is a positive integer represented by string, whose length will not exceed 18.
If there is a tie, return the smaller one as answer.
Subscribe to see which companies asked this question.

Hide Tags String

Let's build a list of candidate answers for which the final answer must be one of those candidates. Afterwards, choosing from these candidates is straightforward.

If the final answer has the same number of digits as the input string S, then the answer must be the middle digits + (-1, 0, or 1) flipped into a palindrome. For example, 23456 had middle part 234, and 233, 234, 235 flipped into a palindrome yields 23332, 23432, 23532. Given that we know the number of digits, the prefix 235 (for example) uniquely determines the corresponding palindrome 23532, so all palindromes with larger prefix like 23732 are strictly farther away from S than 23532 >= S.

If the final answer has a different number of digits, it must be of the form 999....999 or 1000...0001, as any palindrome smaller than 99....99 or bigger than 100....001 will be farther away from S.

class Solution {
public:
    string nearestPalindromic(string s) {
        if (s.empty()) return s;
        unordered_set<long> cand;
        int n=s.size();
        cand.insert(long(pow(10,n))+1);
        cand.insert(long(pow(10,n-1))-1);
        long prefix=stol(s.substr(0, (n+1)/2));
        
        for (long i=-1; i<=1; i++) {
            string num=to_string(prefix+i);
            string w=num+string(num.rbegin()+(n&1), num.rend());
            cand.insert(stol(w));
        }
        long val=stol(s), minVal, diff, minDiff=LONG_MAX;
        cand.erase(val);
        for (auto c:cand) {
            diff=abs(c-val);
            if (diff<minDiff) {
                minDiff=diff;
                minVal=c;
            } else if (diff==minDiff) {
                minVal=min(minVal, c);
            }
        }
        
        return to_string(minVal);
    }
};

