632. Smallest Range
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

Example 1:
Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Note:
The given list may contain duplicates, so ascending order means >= here.
1 <= k <= 3500
-105 <= value of elements <= 105.
For Java users, please note that the input type has been changed to List<List<Integer>>. And after you reset the code template, you'll see this point.

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {        
        int minVal=INT_MAX, maxVal=INT_MIN;
        auto cmp=[&nums](pair<int,int>& a, pair<int,int>& b) { return nums[a.first][a.second]>nums[b.first][b.second]; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        for (int i=0; i<nums.size(); i++) {
            if (nums[i].size()>0) {
                minVal=min(minVal, nums[i][0]);
                maxVal=max(maxVal, nums[i][0]);
                pq.push({i,0});
            }
        }
        
        vector<int> res={minVal, maxVal};
        while (!pq.empty()) {
            pair<int,int> t=pq.top();
            pq.pop();            
            t.second++;
            if (t.second==nums[t.first].size()) break;
            pq.push(t);
            
            minVal=nums[pq.top().first][pq.top().second];
            maxVal=max(maxVal, nums[t.first][t.second]);
            
            if (maxVal-minVal<res[1]-res[0]) res={minVal, maxVal};
        }
        
        return res;
    }
};

2. use iterator
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        typedef vector<int>::iterator iter;
        int minVal=INT_MAX, maxVal=INT_MIN;
        auto cmp=[](pair<iter,iter>& a, pair<iter,iter>& b) { return *a.first>*b.first; };
        priority_queue<pair<iter,iter>, vector<pair<iter,iter>>, decltype(cmp)> pq(cmp);
        for (auto& num:nums) {
            if (num.size()>0) {
                minVal=min(minVal, num[0]);
                maxVal=max(maxVal, num[0]);
                pq.push({num.begin(), num.end()});
            }
        }
        
        vector<int> res={minVal, maxVal};
        while (!pq.empty()) {
            pair<iter,iter> t=pq.top();
            pq.pop();            
            t.first++;
            if (t.first==t.second) break;
            pq.push(t);
            
            minVal=*pq.top().first;
            maxVal=max(maxVal, *t.first);
            
            if (maxVal-minVal<res[1]-res[0]) res={minVal, maxVal};
        }
        
        return res;
    }
};

