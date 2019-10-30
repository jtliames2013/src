632. Smallest Range Covering Elements from K Lists
Hard

805

22

Favorite

Share
You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

 

Example 1:

Input: [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
 

Note:

The given list may contain duplicates, so ascending order means >= here.
1 <= k <= 3500
-105 <= value of elements <= 105.

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {        
        int n=nums.size(), mn=INT_MAX, mx=INT_MIN, start, end;
        auto comp=[&](pair<int,int>& a, pair<int,int>& b){ return nums[a.first][a.second]>nums[b.first][b.second]; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        for (int i=0; i<n; ++i) {
            pq.push({i, 0});
            mn=min(mn, nums[i][0]);
            mx=max(mx, nums[i][0]);
        }
        start=mn;
        end=mx;
        
        while (pq.size()==n) {
            auto t=pq.top();
            pq.pop();
            
            if (t.second<nums[t.first].size()-1) {
                pq.push({t.first, t.second+1});
                mn=nums[pq.top().first][pq.top().second];
                mx=max(mx, nums[t.first][t.second+1]);
                if (mx-mn<end-start) {
                    start=mn;
                    end=mx;
                }
            }
        }
        
        return {start, end};
    }
};
