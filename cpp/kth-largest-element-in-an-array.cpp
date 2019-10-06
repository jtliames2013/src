215. Kth Largest Element in an Array 
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Hide Company Tags Facebook Amazon Microsoft Apple Bloomberg Pocket Gems
Hide Tags Heap Divide and Conquer
Hide Similar Problems

O(n)解法：快速选择（QuickSelect）算法，参考耶鲁大学关于QuickSelect算法的介绍
https://en.wikipedia.org/wiki/Quickselect

class Solution {
public:
    int partition(vector<int>& nums, int l, int r, int pivotIndex) {
        swap(nums[r], nums[pivotIndex]);
        int end=l;
        for (int i=l; i<r; i++) {
            if (nums[i]>nums[r]) {
                if (end!=i) swap(nums[end], nums[i]);
                end++;
            }
        }
        swap(nums[r], nums[end]);
        return end;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        if (n==0) return 0;
        int l=0, r=n-1;
        while (1) {
            int pivotIndex=rand()%(r-l+1)+l;
            pivotIndex=partition(nums, l, r, pivotIndex);
            if (pivotIndex==k-1) return nums[k-1];
            else if (pivotIndex<k-1) l=pivotIndex+1;
            else r=pivotIndex-1;
        }
    }
};

