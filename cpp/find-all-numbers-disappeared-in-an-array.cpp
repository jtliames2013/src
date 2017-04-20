448. Find All Numbers Disappeared in an Array Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 38027
Total Submissions: 72374
Difficulty: Easy
Contributors:
yuhaowang001
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
Subscribe to see which companies asked this question.

Hide Tags Array
Hide Similar Problems (H) First Missing Positive (M) Find All Duplicates in an Array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (auto n:nums) {
            int i=abs(n)-1;
            if (nums[i]>0) nums[i]=-nums[i];
        }
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]>0) res.push_back(i+1);
        }
        
        return res;
    }
};

