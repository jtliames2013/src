923. 3Sum With Multiplicity
Medium

241

48

Favorite

Share
Given an integer array A, and an integer target, return the number of tuples i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.

As the answer can be very large, return it modulo 10^9 + 7.

 

Example 1:

Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (A[i], A[j], A[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
Example 2:

Input: A = [1,1,2,2,2,2], target = 5
Output: 12
Explanation: 
A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.
 

Note:

3 <= A.length <= 3000
0 <= A[i] <= 100
0 <= target <= 300

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        long res=0;
        unordered_map<int,long> mp;
        for (auto a:A) mp[a]++;
        for (auto iter1:mp) {
            for (auto iter2:mp) {
                int i=iter1.first, j=iter2.first, k=target-i-j;
                if (mp.find(k)!=mp.end()) {
                    if (i==j && j==k) res+=mp[i]*(mp[i]-1)*(mp[i]-2)/6; //no need to check if mp[i]>=3
                    else if (i==j && j!=k) res+=mp[i]*(mp[i]-1)/2*mp[k];
                    else if (i<j && j<k) res+=mp[i]*mp[j]*mp[k];
                }
            }
        }
        return res%mod;
    }
private:
    const int mod=1e9+7;
};
