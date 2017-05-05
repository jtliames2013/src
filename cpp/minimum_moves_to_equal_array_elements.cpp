453. Minimum Moves to Equal Array Elements Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 22793
Total Submissions: 48669
Difficulty: Easy
Contributors:
amehrotra2610
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
Subscribe to see which companies asked this question.

Show Tags
Hide Similar Problems (M) Minimum Moves to Equal Array Elements II

Adding 1 to n - 1 elements is the same as subtracting 1 from one element, w.r.t goal of making the elements in the array equal.
So, best way to do this is make all the elements in the array equal to the min element.

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res=0, minval=INT_MAX;
        for (auto n:nums) minval=min(minval, n);
        for (auto n:nums) res+=n-minval;
        return res;
    }
};

