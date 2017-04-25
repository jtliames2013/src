324. Wiggle Sort II  
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Sort
Hide Similar Problems (M) Sort Colors (M) Kth Largest Element in an Array (M) Wiggle Sort

(1) elements smaller than the 'median' are put into the last even slots
(2) elements larger than the 'median' are put into the first odd slots
(3) the medians are put into the remaining slots.

// 1 2 3 3 4 5
// separate middle to two end in case of the same number
// 3 5 2 4 1 3
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return;
        vector<int> sorted=nums;
        sort(sorted.begin(), sorted.end());
        
        int j=n-1;
        for (int i=1; i<n; i+=2) {
            nums[i]=sorted[j--];
        }
        for (int i=0; i<n; i+=2) {
            nums[i]=sorted[j--];
        }
    }
};

