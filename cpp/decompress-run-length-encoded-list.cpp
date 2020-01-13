1313. Decompress Run-Length Encoded List
Easy

24

104

Add to List

Share
We are given a list nums of integers representing a list compressed with run-length encoding.

Consider each adjacent pair of elements [a, b] = [nums[2*i], nums[2*i+1]] (with i >= 0).  For each such pair, there are a elements with value b in the decompressed list.

Return the decompressed list.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [2,4,4,4]
 

Constraints:

2 <= nums.length <= 100
nums.length % 2 == 0
1 <= nums[i] <= 100

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        for (int i=0; i<n; i+=2) {
            for (int j=0; j<nums[i]; ++j) res.push_back(nums[i+1]);
        }
        return res;
    }
};

