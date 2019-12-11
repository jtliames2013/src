280. Wiggle Sort
Medium

490

50

Favorite

Share
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

Example:

Input: nums = [3,5,2,1,6,4]
Output: One possible answer is [3,5,1,6,2,4]

Airbnb
|
2

如果i是奇数，nums[i] >= nums[i - 1]
如果i是偶数，nums[i] <= nums[i - 1]
所以我们只要遍历一遍数组，把不符合的情况交换一下就行了。具体来说，如果nums[i] > nums[i - 1]， 则交换以后肯定有nums[i] <= nums[i - 1]。

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i=1; i<nums.size(); i++) {
            if ((i%2==1 && nums[i]<nums[i-1]) ||
                (i%2==0 && nums[i]>nums[i-1])) {
                    swap(nums[i], nums[i-1]);
                }
        }
    }
};
