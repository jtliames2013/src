1584. Min Cost to Connect All Points
Medium

140

18

Add to List

Share
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:



Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
Example 3:

Input: points = [[0,0],[1,1],[1,0],[-1,1]]
Output: 4
Example 4:

Input: points = [[-1000000,-1000000],[1000000,1000000]]
Output: 4000000
Example 5:

Input: points = [[0,0]]
Output: 0
 

Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.


struct Edge {
public:
    Edge(int u, int v, int d):u(u), v(v), d(d) {} 
    int u;
    int v;
    int d;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res=0, cnt=0, n=points.size();
        vector<int> root(n);
        for (int i=0; i<n; ++i) root[i]=i;
        vector<Edge> conn;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                conn.push_back(Edge(i, j, abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])));
            }
        }
        sort(conn.begin(), conn.end(), [](Edge& a, Edge& b){ return a.d<b.d; });
        for (auto c:conn) {
            int p1=find(root, c.u);
            int p2=find(root, c.v);
            if (p1!=p2) {
                cnt++;
                res+=c.d;
                root[p1]=p2;
            }
            if (cnt==n-1) break;
        }
        return res;
    }
private:
    int find(vector<int>& root, int i) {
        while (i!=root[i]) {
            root[i]=root[root[i]];
            i=root[i];
        }
        return i;
    }
};
