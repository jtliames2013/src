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

Hide Company Tags Google Zenefits
Hide Tags Breadth-first Search
Hide Similar Problems (M) Walls and Gates (H) Best Meeting Point

#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>
using namespace std;

// NOTE: 0 may not connect to all 1s, such as
// 1 1
// 0 1
// so need to record the count of buildings each 0 can connect to

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> total(m, vector<int>(n, 0));
        // number of buildings each 0 can connect
        vector<vector<int>> buildings(m, vector<int>(n, 0));
        int mindist=INT_MAX;
        int delta[4][2]= {{0,1},{0,-1},{1,0},{-1,0}};
        int numBuildings=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==1) numBuildings++;
            }
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==1) {
                    vector<vector<int>> dist(m, vector<int>(n,0));
                    vector<vector<bool>> visited(m, vector<bool>(n,false));
                    // record number of buildings this building can connect to so we can bail out early
                    int count=1;

                    // BFS
                    queue<pair<int,int>>q;
                    q.push(make_pair(i,j));
                    visited[i][j]=true;
                    while (!q.empty()) {
                        auto pos=q.front();
                        q.pop();

                        for (int k=0; k<4; k++) {
                            int nx=pos.first+delta[k][0];
                            int ny=pos.second+delta[k][1];
                            if (nx>=0 && nx<m && ny>=0 && ny <n && visited[nx][ny]==false) {
                                if (grid[nx][ny]==0) {
                                    dist[nx][ny]=dist[pos.first][pos.second]+1;
                                    total[nx][ny]+=dist[nx][ny];
                                    q.push(make_pair(nx, ny));
                                    buildings[nx][ny]++;
                                } else if (grid[nx][ny]==1) {
                                    count++;
                                }
                                visited[nx][ny]=true;
                            }
                        }
                    }
                    if (count!=numBuildings) return -1;
                }
            }
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==0 && buildings[i][j]==numBuildings && mindist>total[i][j]) {
                    mindist=total[i][j];
                }
            }
        }
        return (mindist==INT_MAX?-1:mindist);
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
