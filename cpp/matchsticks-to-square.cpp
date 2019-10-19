473. Matchsticks to Square Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 7063
Total Submissions: 20508
Difficulty: Medium
Contributors:
weezer
Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.

Note:
The length sum of the given matchsticks is in the range of 0 to 10^9.
The length of the given matchstick array will not exceed 15.
Subscribe to see which companies asked this question.

Hide Tags Depth-first Search

https://en.wikipedia.org/wiki/Partition_problem

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n=nums.size(), sum=0;
        if (n<4) return false;
        for (auto& i:nums) sum+=i;
        if (sum%4!=0) return false;
        vector<int> sides(4);

        return dfs(nums, sides, 0, sum/4);
    }
private:
    bool dfs(vector<int>& nums, vector<int>& sides, int start, int len) {
        if (start==nums.size()) return true;

        for (int i=0; i<4; ++i) {
            if (nums[start]+sides[i]<=len) {
                bool cont=false;
                for (int j=0; j<i; ++j) {
                    if (sides[j]==sides[i]) {
                        cont=true;
                        break;
                    }
                }
                if (cont) continue;

                sides[i]+=nums[start];
                if (dfs(nums, sides, start+1, len)==true) return true;
                sides[i]-=nums[start];
            }
        }
        return false;
    }
};
