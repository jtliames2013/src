1. Two Sum 
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.

Hide Company Tags LinkedIn Uber Airbnb Facebook Amazon Microsoft Apple Yahoo Dropbox Bloomberg Yelp Adobe
Hide Tags Array Hash Table
Hide Similar Problems (M) 3Sum (M) 4Sum (M) Two Sum II - Input array is sorted (E) Two Sum III - Data structure design

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>

1. hash table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2,0);
        int n=nums.size();
        if (n==0) return res;
        unordered_map<int,int> table;
        for (int i=0; i<n; i++) {
            if (table.find(target-nums[i])!=table.end()) {
                res[0]=table[target-nums[i]];
                res[1]=i;
                return res;
            }
            table[nums[i]]=i;
        }
        return res;
    }
};

2. two pointers
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2,0);
        int n=nums.size();
        if (n==0) return res;
        vector<pair<int,int>> data(n);
        for (int i=0; i<n; i++) {
            data[i].first=nums[i];
            data[i].second=i;
        }
        sort(data.begin(), data.end(), [](pair<int,int> &a, pair<int,int> &b){ return a.first<b.first; });
        int l=0, r=n-1;
        while (l<r) {
            if (data[l].first+data[r].first==target) {
                res[0]=data[l].second;
                res[1]=data[r].second;
                return res;
            } else if (data[l].first+data[r].first<target) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};

int main()
{
	return 0;
}


