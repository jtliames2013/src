373. Find K Pairs with Smallest Sums  
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> res;
        if (nums1.empty() || nums2.empty() || k <= 0) return res;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        pq.push({0, 0});
        while(k-- > 0 && pq.size())
        {
            auto idx_pair = pq.top(); 
            pq.pop();
            res.push_back({nums1[idx_pair.first], nums2[idx_pair.second]});
            if (idx_pair.first + 1 < nums1.size())
                pq.push({idx_pair.first + 1, idx_pair.second});
            if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
                pq.push({idx_pair.first, idx_pair.second + 1});
        }
        return res;
    }
};

2.
class Solution {
public:
    struct Point {
        int i1; 
        int i2;
        int val;
        Point(int a, int b, int v): i1(a), i2(b), val(v) {} 
    };
    
    class Compare {
    public:
        bool operator()(Point a, Point b) {
            return a.val>b.val;
        }
    };
    
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> res;
        if (nums1.size()==0 || nums2.size()==0) return res;
        priority_queue<Point, vector<Point>, Compare> pq;
        pq.push(Point(0, 0, nums1[0]+nums2[0]));
        
        while (!pq.empty() && k>0) {
            Point t=pq.top();
            pq.pop();
            k--;
            res.push_back({nums1[t.i1], nums2[t.i2]});
            
            if (t.i1+1<nums1.size()) pq.push(Point(t.i1+1, t.i2, nums1[t.i1+1]+nums2[t.i2]));
            if (t.i1==0 && t.i2+1<nums2.size()) pq.push(Point(t.i1, t.i2+1, nums1[t.i1]+nums2[t.i2+1]));
        }
        return res;
    }
};
