930. Binary Subarrays With Sum
Medium

279

14

Favorite

Share
In an array A of 0s and 1s, how many non-empty subarrays have sum S?

 

Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation: 
The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
 

Note:

A.length <= 30000
0 <= S <= A.length
A[i] is either 0 or 1.

1. Use map
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int res=0, sum=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for (auto& a:A) {
            sum+=a;
            if (mp.find(sum-S)!=mp.end()) res+=mp[sum-S];
            mp[sum]++;
        }
        return res;
    }
};

2. Use array
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int res=0, sum=0, n=A.size();
        vector<int> count(n+1);
        count[0]=1;
        for (auto& a:A) {
            sum+=a;
            if (sum>=S) res+=count[sum-S];
            count[sum]++;
        }
        return res;
    }
};
