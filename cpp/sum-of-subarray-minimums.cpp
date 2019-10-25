907. Sum of Subarray Minimums
Medium

687

48

Favorite

Share
Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 

Note:

1 <= A.length <= 30000
1 <= A[i] <= 30000

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int res=0, n=A.size();
        vector<int> left(n), right(n);
        stack<pair<int,int>> stkl, stkr;
        for (int i=0; i<n; ++i) {
            int count=1;
            while (!stkl.empty() && stkl.top().first>=A[i]) {
                count+=stkl.top().second;
                stkl.pop();
            }
            stkl.push({A[i], count});
            left[i]=count;
        }

        for (int i=n-1; i>=0; --i) {
            int count=1;
            // in case there are multiple elements of the same value
            // when extend to right, stop at the first element with the same value
            // otherwise it'll overlap with that element extending to left
            while (!stkr.empty() && stkr.top().first>A[i]) {
                count+=stkr.top().second;
                stkr.pop();
            }
            stkr.push({A[i], count});
            right[i]=count;
        }
        
        for (int i=0; i<n; ++i) {
            res=(res+A[i]*left[i]*right[i])%mod;
        }
        
        return res;
    }
private:
    const int mod=1e9+7;
};
