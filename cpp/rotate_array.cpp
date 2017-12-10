189. Rotate Array Add to List
DescriptionSubmissionsSolutions
Total Accepted: 118166
Total Submissions: 493367
Difficulty: Easy
Contributor: LeetCode
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.

Hide Tags Array
Hide Similar Problems (M) Rotate List (M) Reverse Words in a String II

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if (n==0 || k<=0) return;        
        k%=n;
        if (k==0) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

