487. Max Consecutive Ones II
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

Example 1:
Input: [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
    After flipping, the maximum number of consecutive 1s is 4.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
Follow up:
What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?

Google
|
2

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0, zeroCnt=0, zeroIdx, start=0, n=nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i]==0) {
                zeroCnt++;                
                if (zeroCnt>1) {
                    res=max(res, i-start);
                    start=zeroIdx+1;
                }
                zeroIdx=i;
            }          
        }
        res=max(res, n-start);
        
        return res;
    }
};

2. sliding window
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0, zeroCnt=0, n=nums.size();
        for (int l=0, r=0; r<n; r++) {
            if (nums[r]==0) zeroCnt++;
            while (zeroCnt>1) {
                if (nums[l]==0) zeroCnt--;
                l++;
            }
            res=max(res, r-l+1);
        }        
        
        return res;
    }
};

