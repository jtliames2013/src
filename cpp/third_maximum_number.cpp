414. Third Maximum Number   QuestionEditorial Solution  My Submissions
Total Accepted: 3433 Total Submissions: 13201 Difficulty: Easy Contributors: ZengRed , 1337c0d3r
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.

Both numbers with value 2 are both considered as second maximum.
Subscribe to see which companies asked this question

Hide Tags Array
Hide Similar Problems (M) Kth Largest Element in an Array

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1=LLONG_MIN, max2=LLONG_MIN, max3=LLONG_MIN;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]==max1||nums[i]==max2||nums[i]==max3) continue;
            
            if (nums[i]>max1) {
                max3=max2;
                max2=max1;
                max1=nums[i];
            } else if (nums[i]>max2) {
                max3=max2;
                max2=nums[i];
            } else if (nums[i]>max3) {
                max3=nums[i];
            }
        }
        
        if (max3!=LLONG_MIN) return max3;
        else return max1;
    }
};

