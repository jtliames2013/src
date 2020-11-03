1631. Path With Minimum Effort
Medium

274

13

Add to List

Share
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0]=0;
        auto comp=[](vector<int>& a, vector<int>& b){ return a[2]>b[2]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        pq.push({0, 0, 0});
        
        while (!pq.empty()) {
            auto t=pq.top();
            pq.pop();
            if (t[0]==m-1 && t[1]==n-1) return dist[m-1][n-1];
            if (dist[t[0]][t[1]]<t[2]) continue;
            for (int k=0; k<4; ++k) {
                int nr=t[0]+delta[k][0];
                int nc=t[1]+delta[k][1];
                if (nr>=0 && nr<m && nc>=0 && nc<n) {
                    int nd=max(dist[t[0]][t[1]], abs(heights[nr][nc]-heights[t[0]][t[1]]));
                    if (nd<dist[nr][nc]) {
                        dist[nr][nc]=nd;
                        pq.push({nr, nc, nd});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

