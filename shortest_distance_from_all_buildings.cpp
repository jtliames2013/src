// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

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
