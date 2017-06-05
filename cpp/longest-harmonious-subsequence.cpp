594. Longest Harmonious Subsequence
DescriptionHintsSubmissionsSolutions
Total Accepted: 4386
Total Submissions: 11266
Difficulty: Easy
Contributors:
love_Fawn
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.

Subscribe to see which companies asked this question.

Hide Tags Hash Table

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<long,int> mp;
        for (auto n:nums) mp[n]++;
        
        long prevKey=LONG_MIN; 
        int prevCnt=0;
        int res=0;
        for (auto i:mp) {
            if (i.first-prevKey==1) {
                res=max(res, i.second+prevCnt);
            }
            prevKey=i.first;
            prevCnt=i.second;
        }
        return res;
    }
};

2.
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<long,int> mp;
        for (auto n:nums) mp[n]++;
        
        int res=0;
        for (auto i:mp) {
            if (mp.find(i.first-1)!=mp.end()) {
                res=max(res, i.second+mp[i.first-1]);
            }
        }
        return res;
    }
};
