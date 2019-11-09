995. Minimum Number of K Consecutive Bit Flips
Hard

174

21

Favorite

Share
In an array A containing only 0s and 1s, a K-bit flip consists of choosing a (contiguous) subarray of length K and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

Return the minimum number of K-bit flips required so that there is no 0 in the array.  If it is not possible, return -1.

 

Example 1:

Input: A = [0,1,0], K = 1
Output: 2
Explanation: Flip A[0], then flip A[2].
Example 2:

Input: A = [1,1,0], K = 2
Output: -1
Explanation: No matter how we flip subarrays of size 2, we can't make the array become [1,1,1].
Example 3:

Input: A = [0,0,0,1,0,1,1,0], K = 3
Output: 3
Explanation:
Flip A[0],A[1],A[2]: A becomes [1,1,1,1,0,1,1,0]
Flip A[4],A[5],A[6]: A becomes [1,1,1,1,1,0,0,0]
Flip A[5],A[6],A[7]: A becomes [1,1,1,1,1,1,1,1]
 

Note:

1 <= A.length <= 30000
1 <= K <= A.length

curr means the number of flips in the current sliding window of size K.
If curr is even and A[i] is 0, we need to flip.
If curr is odd and A[i] is 1, we need to flip.

If we want to flip A[i], we add 2 to it.
The flipped 0 is 2 and flipped 1 is 3 now.
When they go out of the window, we will change them back.
So no worries if we change the input.

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int res=0, n=A.size(), curr=0;
        for (int i=0; i<n; ++i) {
            if (i>=K && A[i-K]>1) {
                curr--;
                A[i-K]-=2;
            }
            if (curr%2==A[i]) {
                if (i+K>n) return -1;
                curr++;
                A[i]+=2;
                res++;
            }
        }
        return res;
    }
};

