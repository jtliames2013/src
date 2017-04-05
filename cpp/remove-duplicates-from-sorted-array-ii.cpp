80. Remove Duplicates from Sorted Array II  QuestionEditorial Solution  My Submissions
Total Accepted: 84191 Total Submissions: 249637 Difficulty: Medium
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

Hide Company Tags Facebook
Hide Tags Array Two Pointers

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<=2) return nums.size();
        int end=2;
        for (int i=2; i<nums.size(); i++) {
            if (nums[i]!=nums[i-1] || nums[i]!=nums[i-2] || nums[end-1]!=nums[end-2]) {
                if (end!=i) nums[end]=nums[i];
                end++;
            }
        }
        return end;
    }
};

