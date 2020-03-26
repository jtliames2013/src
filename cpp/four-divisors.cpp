1390. Four Divisors
Medium

31

45

Add to List

Share
Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors.

If there is no such integer in the array, return 0.

 

Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
 

Constraints:

1 <= nums.length <= 10^4
1 <= nums[i] <= 10^5

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size(), res=0;
        for (int i=0; i<n; ++i) {
            vector<int> div=getDiv(nums[i]);
            if (div[0]==4) res+=div[1];
        }
        return res;
    }
private:
    vector<int> getDiv(int n) {
        vector<int> res(2);
        for (int i=1; i*i<=n; ++i) {
            if (n%i==0) {
                res[0]+=2;
                res[1]+=i+n/i;
            }
            if (i*i==n) {
                res[0]--;
                res[1]-=i;
            }
            if (res[0]>4) break;
        }

        return res;
    }
};

