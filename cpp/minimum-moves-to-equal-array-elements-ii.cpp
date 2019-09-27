462. Minimum Moves to Equal Array Elements II Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 12990
Total Submissions: 25372
Difficulty: Medium
Contributors:
andrew56
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
Subscribe to see which companies asked this question.

Hide Tags Math
Hide Similar Problems (H) Best Meeting Point (E) Minimum Moves to Equal Array Elements

This solution relies on the fact that if we increment/decrement each element to the median of all the elements, the optimal number of moves is necessary. The median of all elements can be found in expected O(n) time using QuickSelect (or deterministic O(n) time using Median of Medians).

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        auto iter=nums.begin()+n/2;
        nth_element(nums.begin(), iter, nums.end());
        int median=*iter;
        int res=0;
        for (auto& n:nums) {
            res+=abs(n-median);
        }
        return res;
    }
};

2.
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res=0;
        int l=0, r=nums.size()-1;
        while (l<r) {
            res+=nums[r]-nums[l];
            l++;
            r--;
        }
        return res;
    }
};
