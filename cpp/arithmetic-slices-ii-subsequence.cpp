446. Arithmetic Slices II - Subsequence Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 4580
Total Submissions: 17935
Difficulty: Hard
Contributors:
Samuri
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A subsequence slice of that array is any sequence of integers (P0, P1, ..., Pk) such that 0 ≤ P0 < P1 < ... < Pk < N.

A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular, this means that k ≥ 2.

The function should return the number of arithmetic subsequence slices in the array A.

The input contains N integers. Every integer is in the range of -231 and 231-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 231-1.


Example:

Input: [2, 4, 6, 8, 10]

Output: 7

Explanation:
All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming
Hide Similar Problems (M) Arithmetic Slices

Base case: T(0, d) = 0 (This is true for any d).
Recurrence relation: T(i, d) = summation of (1 + T(j, d)) as long as 0 <= j < i && d == A[i] - A[j].

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        if (n<3) return 0;
        int res=0;
        vector<unordered_map<long,int>> dp(n);
        
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                long diff=(long)A[i]-(long)A[j];
                if (diff<INT_MIN || diff>INT_MAX) continue;
                dp[i][diff]+=1;
                if (dp[j].find(diff)!=dp[j].end()) {
                    dp[i][diff]+=dp[j][diff];
                    res+=dp[j][diff];
                }
            }
        }
        
        return res;
    }
};

