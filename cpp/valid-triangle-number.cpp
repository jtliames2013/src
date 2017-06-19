611. Valid Triangle Number
DescriptionHintsSubmissionsSolutions
Total Accepted: 2525
Total Submissions: 7429
Difficulty: Medium
Contributors:
fallcreek
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].
Subscribe to see which companies asked this question.

Hide Tags Array
Hide Similar Problems (M) 3Sum Smaller

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        if (n<3) return 0;
        sort(nums.begin(), nums.end());
        int res=0;
        
        for (int i=n-1; i>=2; i--) {
            int l=0, r=i-1;
            while (l<r) {
                if (nums[l]+nums[r]>nums[i]) {
                    res+=r-l;
                    r--;
                } else {
                    l++;
                }
            }
        }
        
        return res;
    }
};

