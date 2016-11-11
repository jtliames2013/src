453. Minimum Moves to Equal Array Elements   QuestionEditorial Solution  My Submissions
Total Accepted: 2533 Total Submissions: 5808 Difficulty: Easy Contributors: amehrotra2610
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
Subscribe to see which companies asked this question

Hide Tags Math

class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res=0;
        for (int i=1; i<nums.size(); i++) {
            res+=(nums[i]-nums[i-1])*(nums.size()-i);
        }
        return res;
    }
};

2.
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res=0;
        int minval=INT_MAX;
        int n=nums.size();
        for (int i=0; i<n; i++) minval=min(minval, nums[i]);
        for (int i=0; i<n; i++) res+=nums[i]-minval;
        return res;
    }
};

