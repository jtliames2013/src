982. Triples with Bitwise AND Equal To Zero
Hard

70

94

Favorite

Share
Given an array of integers A, find the number of triples of indices (i, j, k) such that:

0 <= i < A.length
0 <= j < A.length
0 <= k < A.length
A[i] & A[j] & A[k] == 0, where & represents the bitwise-AND operator.
 

Example 1:

Input: [2,1,3]
Output: 12
Explanation: We could choose the following i, j, k triples:
(i=0, j=0, k=1) : 2 & 2 & 1
(i=0, j=1, k=0) : 2 & 1 & 2
(i=0, j=1, k=1) : 2 & 1 & 1
(i=0, j=1, k=2) : 2 & 1 & 3
(i=0, j=2, k=1) : 2 & 3 & 1
(i=1, j=0, k=0) : 1 & 2 & 2
(i=1, j=0, k=1) : 1 & 2 & 1
(i=1, j=0, k=2) : 1 & 2 & 3
(i=1, j=1, k=0) : 1 & 1 & 2
(i=1, j=2, k=0) : 1 & 3 & 2
(i=2, j=0, k=1) : 3 & 2 & 1
(i=2, j=1, k=0) : 3 & 1 & 2
 

Note:

1 <= A.length <= 1000
0 <= A[i] < 2^16

1.
class Solution {
public:
    int countTriplets(vector<int>& A) {
        int res=0;
        vector<int> count(1<<16);
        for (auto a:A) {
            for (auto b:A) count[a&b]++;
        }
        for (auto a:A) {
            for (int i=0; i<count.size(); ++i) {
                if ((i&a)==0) res+=count[i];
            }
        }
        
        return res;
    }
};

2. DP, Time Exceeded
class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n=1<<16;
        int dp[3][1<<16]={};
        for (auto a:A) dp[0][a]++;
        for (int i=1; i<3; ++i) {
            for (int j=0; j<n; ++j) {
                for (auto a:A) dp[i][j&a]+=dp[i-1][j];
            }
        }
        return dp[2][0];
    }
};
