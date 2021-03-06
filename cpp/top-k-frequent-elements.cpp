﻿347. Top K Frequent Elements 
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
Hide Company Tags Pocket Gems Yelp
Hide Tags Hash Table Heap
Hide Similar Problems (M) Word Frequency (M) Kth Largest Element in an Array

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> mp;
        for (auto n:nums) mp[n]++;
        auto comp=[](pair<int,int>& a, pair<int,int>& b){ return a.second>b.second; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        
        for (auto i:mp) {
            if (pq.size()<k) pq.push({i.first, i.second});
            else {
                if (i.second>pq.top().second) {
                    pq.pop();
                    pq.push({i.first, i.second});
                }
            }
        }
        
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();            
        }
        return res;
    }
};

2. bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for (auto n:nums) count[n]++;
        vector<int> res;
        int n=nums.size();
        vector<vector<int>> bucket(n+1);
        for (auto cnt:count) bucket[cnt.second].push_back(cnt.first);
        
        for (int i=n; i>=0; i--) {
            for (int j=0; j<bucket[i].size(); j++) {
                if (res.size()==k) return res;
                res.push_back(bucket[i][j]);
            }
        }
        return res;
    }
};

