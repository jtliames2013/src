974. Subarray Sums Divisible by K
Medium

437

39

Favorite

Share
Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

 

Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
 

Note:

1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int sum=0, res=0;
        for (auto& a:A) {
            sum=(sum+a)%K;
            if (sum<0) sum+=K;            
            res+=mp[sum];
            mp[sum]++;
        }
        return res;
    }
};
