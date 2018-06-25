842. Split Array into Fibonacci Sequence
DescriptionHintsSubmissionsDiscussSolution
Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
F.length >= 3;
and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

Example 1:

Input: "123456579"
Output: [123,456,579]
Example 2:

Input: "11235813"
Output: [1,1,2,3,5,8,13]
Example 3:

Input: "112358130"
Output: []
Explanation: The task is impossible.
Example 4:

Input: "0123"
Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
Example 5:

Input: "1101111"
Output: [110, 1, 111]
Explanation: The output [11, 0, 11, 11] would also be accepted.
Note:

1 <= S.length <= 200
S contains only digits.

class Solution {
public:
    bool dfs(vector<int>& res, string& S, int start) {
        if (start==S.size()) return res.size()>2;
        for (int i=start; i<S.size() && i-start+1<=maxLen; ++i) {
            if (S[start]=='0' && i>start) break;
            unsigned long long num=stoull(S.substr(start, i-start+1));
            if (num>INT_MAX) break;
            int len=res.size(), sum;
            if (len>=2) sum=res[len-1]+res[len-2];
            if (len<2 || num==sum) {
                res.push_back(num);
                if (dfs(res, S, i+1)) return true;
                res.pop_back();
            } else if (num>sum) {
                break;
            }
        }
        return false;
    }
    
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        dfs(res, S, 0);
        return res;
    }
private:
    int maxLen=10;
};
