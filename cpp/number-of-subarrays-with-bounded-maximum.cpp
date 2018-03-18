795. Number of Subarrays with Bounded Maximum
DescriptionHintsSubmissionsDiscussSolution
We are given an array A of positive integers, and two positive integers L and R (L <= R).

Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least L and at most R.

Example :
Input: 
A = [2, 1, 4, 3]
L = 2
R = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
Note:

L, R  and A[i] will be an integer in the range [0, 10^9].
The length of A will be in the range of [1, 50000].

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res=0, l=0, r=0, count=0;
        for (; r<A.size(); r++) {
            if (A[r]>=L && A[r]<=R) {
                res+=r-l+1;
                count=r-l+1;
            } else if (A[r]<L) {
                res+=count;
            } else {
                l=r+1;
                count=0;
            }
        }
        return res;
    }
};
