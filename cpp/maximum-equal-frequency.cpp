1224. Maximum Equal Frequency
Hard

105

16

Favorite

Share
Given an array nums of positive integers, return the longest possible length of an array prefix of nums, such that it is possible to remove exactly one element from this prefix so that every number that has appeared in it will have the same number of occurrences.

If after removing one element there are no remaining elements, it's still considered that every appeared number has the same number of ocurrences (0).

 

Example 1:

Input: nums = [2,2,1,1,5,3,3,5]
Output: 7
Explanation: For the subarray [2,2,1,1,5,3,3] of length 7, if we remove nums[4]=5, we will get [2,2,1,1,3,3], so that each number will appear exactly twice.
Example 2:

Input: nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
Output: 13
Example 3:

Input: nums = [1,1,1,2,2,2]
Output: 5
Example 4:

Input: nums = [10,2,8,9,3,8,1,5,2,3,7,6]
Output: 8
 

Constraints:

2 <= nums.length <= 10^5
1 <= nums[i] <= 10^5

There are three cases which satify the condition:

all elements appear exact once.
all elements appear maxCnt times, except one appears once.
all elements appear maxCnt-1 times, except one appears maxCnt.

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n=nums.size(), maxCnt=0, res;
        unordered_map<int, int> count, freq;
        for (int i=0; i<n; ++i) {
            count[nums[i]]++;
            freq[count[nums[i]]-1]--;
            freq[count[nums[i]]]++;
            maxCnt=max(maxCnt, count[nums[i]]);
            if (maxCnt*freq[maxCnt]+1==i+1 || (maxCnt-1)*freq[maxCnt-1]+maxCnt==i+1 || maxCnt==1)
                res=i+1;
        }
        return res;
    }
};

