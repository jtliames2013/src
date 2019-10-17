967. Numbers With Same Consecutive Differences
Medium

117

39

Favorite

Share
Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Note:

1 <= N <= 9
0 <= K <= 9

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> curr={1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        for (int i=1; i<N; ++i) {
            vector<int> next;
            for (auto x:curr) {
                int y=x%10;
                if (x>0 && y+K<10) next.push_back(x*10+y+K);
                if (x>0 && y-K>=0 && K>0) next.push_back(x*10+y-K);
            }
            curr=next;
        }
        return curr;
    }    
};
