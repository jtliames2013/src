317. Shortest Distance from All Buildings  
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.

Google
|
4

Mathworks
|
4

Facebook
|
3

Snapchat
|
2

Amazon
|
2

Uber
|
2

Microsoft
|
3

Splunk
|
2

ByteDance
|
2

Zenefits
|
LeetCode

// NOTE: 0 may not connect to all 1s, such as
// 1 1
// 0 1
// so need to record the count of buildings each 0 can connect to

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> count(m, vector<int>(n));
        int numBuildings=0, cnt;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==1) numBuildings++;
            }
        }
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]!=1) continue;
                // record number of buildings this building can connect to so we can bail out early
                cnt=1;
                // BFS                
                vector<vector<bool>> visited(m, vector<bool>(n));
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j]=true;                
                int d=0;
                
                while (!q.empty()) {
                    int size=q.size();
                    d++;    
                    for (int l=0; l<size; l++) {
                        pair<int,int> f=q.front();
                        q.pop();
                        
                        for (int k=0; k<4; k++) {
                            int nr=f.first+delta[k][0];
                            int nc=f.second+delta[k][1];
                            if (nr>=0 && nr<m && nc>=0 && nc<n && visited[nr][nc]==false) {
                                if (grid[nr][nc]==0) {
                                    dist[nr][nc]+=d;
                                    count[nr][nc]++;
                                    q.push({nr,nc});                                    
                                } else if (grid[nr][nc]==1) {
                                    cnt++;
                                }
                                visited[nr][nc]=true;
                            }
                        }
                    }                    
                }
                if (cnt<numBuildings) return -1;
            }
        }
        
        int res=INT_MAX;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==0 && count[i][j]==numBuildings) {
                    res=min(res, dist[i][j]);
                }
            }
        }
        
        return res==INT_MAX?-1:res;
    }    
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

