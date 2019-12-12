1057. Campus Bikes
Medium

293

45

Favorite

Share
On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M. Each worker and bike is a 2D coordinate on this grid.

Our goal is to assign a bike to each worker. Among the available bikes and workers, we choose the (worker, bike) pair with the shortest Manhattan distance between each other, and assign the bike to that worker. (If there are multiple (worker, bike) pairs with the same shortest Manhattan distance, we choose the pair with the smallest worker index; if there are multiple ways to do that, we choose the pair with the smallest bike index). We repeat this process until there are no available workers.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

Return a vector ans of length N, where ans[i] is the index (0-indexed) of the bike that the i-th worker is assigned to.

 

Example 1:



Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
Output: [1,0]
Explanation: 
Worker 1 grabs Bike 0 as they are closest (without ties), and Worker 0 is assigned Bike 1. So the output is [1, 0].
Example 2:



Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
Output: [0,2,1]
Explanation: 
Worker 0 grabs Bike 0 at first. Worker 1 and Worker 2 share the same distance to Bike 2, thus Worker 1 is assigned to Bike 2, and Worker 2 will take Bike 1. So the output is [0,2,1].
 

Note:

0 <= workers[i][j], bikes[i][j] < 1000
All worker and bike locations are distinct.
1 <= workers.length <= bikes.length <= 1000

Google
|
22

Amazon
|
2

ByteDance
|
2

1. bucket sort
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m=workers.size(), n=bikes.size();
        vector<int> res(m, -1);
        vector<vector<vector<int>>> bucket(2001); // 0 <= workers[i][j], bikes[i][j] < 1000
        unordered_set<int> st;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int dist=abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
                bucket[dist].push_back({i, j});
            }
        }
        
        for (int i=0; i<=2000; ++i) {
            for (int j=0; j<bucket[i].size(); ++j) {
                if (st.size()==m) return res;
                if (res[bucket[i][j][0]]==-1 && st.find(bucket[i][j][1])==st.end()) {
                    res[bucket[i][j][0]]=bucket[i][j][1];
                    st.insert(bucket[i][j][1]);
                }
            }
        }
        
        return res;
    }
};

2. priority queue (TLE)
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m=workers.size(), n=bikes.size();
        vector<int> res(m, -1);
        auto comp=[](vector<int>& a, vector<int>& b){ return a[0]>b[0] || (a[0]==b[0] && a[1]>b[1]) || (a[0]==b[0] && a[1]==b[1] && a[2]>b[2]); };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        unordered_set<int> st;
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int dist=abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
                pq.push({dist, i, j});
            }
        }
        
        while (!pq.empty()) {
            if (st.size()==m) break;
            auto t=pq.top();
            pq.pop();
            if (res[t[1]]==-1 && st.find(t[2])==st.end()) {
                res[t[1]]=t[2];
                st.insert(t[2]);
            }
        }
        return res;
    }
};

