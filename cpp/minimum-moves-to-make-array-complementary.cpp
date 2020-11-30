1674. Minimum Moves to Make Array Complementary
Medium

84

18

Add to List

Share
You are given an integer array nums of even length n and an integer limit. In one move, you can replace any integer from nums with another integer between 1 and limit, inclusive.

The array nums is complementary if for all indices i (0-indexed), nums[i] + nums[n - 1 - i] equals the same number. For example, the array [1,2,3,4] is complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.

Return the minimum number of moves required to make nums complementary.

 

Example 1:

Input: nums = [1,2,4,3], limit = 4
Output: 1
Explanation: In 1 move, you can change nums to [1,2,2,3] (underlined elements are changed).
nums[0] + nums[3] = 1 + 3 = 4.
nums[1] + nums[2] = 2 + 2 = 4.
nums[2] + nums[1] = 2 + 2 = 4.
nums[3] + nums[0] = 3 + 1 = 4.
Therefore, nums[i] + nums[n-1-i] = 4 for every i, so nums is complementary.
Example 2:

Input: nums = [1,2,2,1], limit = 2
Output: 2
Explanation: In 2 moves, you can change nums to [2,2,2,2]. You cannot change any number to 3 since 3 > limit.
Example 3:

Input: nums = [1,2,1,2], limit = 2
Output: 0
Explanation: nums is already complementary.
 

Constraints:

n == nums.length
2 <= n <= 105
1 <= nums[i] <= limit <= 105
n is even.

For each pair of numbers (at index i and N - 1 - i) l and r:

By 2 moves we can get any number between [2, limit*2] (including move a number to the same number)
After only one move (change one of the numbers to a number between 1 and limit)
The minimum sum we can get is (min(l, r) + 1) (let this be oneMoveMin)
The maximum sum we can get is (max(l, r) + limit) (let this be oneMoveMax)
We need no move to get (l + r) (let this be justGood)
Therefore, to get:

[~, oneMoveMin - 1] - 2 moves
[oneMoveMin, justGood-1] - 1 move
[justGood] - 0 move
[justGood + 1, oneMoveMax] - 1 move
[oneMoveMax + 1, ~] - 2 moves
For each pair of numbers

We start with 2 moves
From oneMoveMin we need 1 less move
From justGood we need another 1 less move
From justGood + 1 we need 1 more move
From oneMoveMax + 1 we need another 1 more move

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int res=INT_MAX, curr=0, n=nums.size();
        unordered_map<int, int> mp;
        for (int i=0; i<n/2; ++i) {
            int a=nums[i], b=nums[n-i-1];
            mp[2]+=2;
            mp[min(a, b)+1]-=1;
            mp[a+b]-=1;
            mp[a+b+1]+=1;
            mp[max(a, b)+limit+1]+=1;
        }
        for (int i=2; i<2*limit+1; ++i) {
            curr+=mp[i];
            res=min(res, curr);
        }
        return res;
    }
};

