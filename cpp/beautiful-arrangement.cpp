526. Beautiful Arrangement Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 7526
Total Submissions: 13851
Difficulty: Medium
Contributors:
love_Fawn
Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ≤ i ≤ N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

Example 1:
Input: 2
Output: 2
Explanation: 

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
Note:
N is a positive integer and will not exceed 15.
Subscribe to see which companies asked this question.

Hide Tags Backtracking

class Solution {
public:
    void dfs(int& res, vector<int>& nums, int start) {
        if (start==nums.size()) {
            res++;
            return;
        }
        for (int i=start; i<nums.size(); i++) {
            if (nums[i]%(start+1)==0 || (start+1)%nums[i]==0) {
                swap(nums[i], nums[start]);
                dfs(res, nums, start+1);
                swap(nums[i], nums[start]);
            }
        }
    }
    
    int countArrangement(int N) {
        int res=0;
        if (N==0) return 0;
        vector<int> nums(N);
        for (int i=0; i<N; i++) nums[i]=i+1;
        dfs(res, nums, 0);
        return res;
    }
};

