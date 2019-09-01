31. Next Permutation  
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
Hide Company Tags Google
Hide Tags Array
Hide Similar Problems (M) Permutations (M) Permutations II (M) Permutation Sequence (M) Palindrome Permutation II

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if (n<=1) return;
        
        int i, j;
        for (i=n-1; i>0; --i) {
            if (nums[i-1]<nums[i]) break;
        }
        
        if (i==0) {
            reverse(nums.begin(), nums.end());
            return;
        }
                
        for (j=n-1; j>=i; --j) {
            if (nums[j]>nums[i-1]) break;
        }
        swap(nums[j], nums[i-1]);
        reverse(nums.begin()+i, nums.end());
    }
};
