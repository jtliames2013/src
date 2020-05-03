1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
Medium

35

1

Add to List

Share
Given an array of integers nums and an integer limit, return the size of the longest continuous subarray such that the absolute difference between any two elements is less than or equal to limit.

In case there is no subarray satisfying the given condition return 0.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= limit <= 10^9

1. deque
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res=0, n=nums.size();
        deque<int> mx, mn;
        for (int l=0, r=0; r<n; ++r) {
            while (!mx.empty() && nums[mx.back()]<nums[r]) mx.pop_back();
            mx.push_back(r);
            while (!mn.empty() && nums[mn.back()]>nums[r]) mn.pop_back();
            mn.push_back(r);
            while (l<r && nums[mx.front()]-nums[mn.front()]>limit) {
                if (mx.front()==l) mx.pop_front();
                if (mn.front()==l) mn.pop_front();
                l++;
            }
            res=max(res, r-l+1);
        }

        return res;
    }
};

2. multiset
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res=0, n=nums.size();
        multiset<int> st;
        for (int l=0, r=0; r<n; ++r) {
            st.insert(nums[r]);
            while (*st.rbegin() - *st.begin()>limit) {
                st.erase(st.find(nums[l]));
                l++;
            }
            res=max(res, r-l+1);
        }

        return res;
    }
};

