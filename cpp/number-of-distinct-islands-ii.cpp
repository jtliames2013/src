711. Number of Distinct Islands II
Hard

122

130

Add to List

Share
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if they have the same shape, or have the same shape after rotation (90, 180, or 270 degrees only) or reflection (left/right direction or up/down direction).

Example 1:
11000
10000
00001
00011
Given the above grid map, return 1.

Notice that:
11
1
and
 1
11
are considered same island shapes. Because if we make a 180 degrees clockwise rotation on the first island, then two islands will have the same shapes.
Example 2:
11100
10001
01001
01110
Given the above grid map, return 2.

Here are the two distinct islands:
111
1
and
1
1

Notice that:
111
1
and
1
111
are considered same island shapes. Because if we flip the first array in the up/down direction, then they have the same shapes.
Note: The length of each dimension in the given grid does not exceed 50.

Amazon
|
2

After we get coordinates for an island, compute all possible rotations/reflections 
(https://en.wikipedia.org/wiki/Dihedral_group) of it and then sort them using the default comparison. 
The first representation in this order is then the canonical one.

class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        unordered_map<int, vector<vector<int>>> mp;
        set<vector<vector<int>>> st;
        int num=2;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]==1) {
                    dfs(grid, i, j, m, n, mp, num);                    
                    st.insert(norm(mp[num]));
                    num++;
                }
            }
        }                
        
        return st.size();
    }
private:
    void dfs(vector<vector<int>>& grid, int row, int col, int m, int n, unordered_map<int, vector<vector<int>>>& mp, int num) {
        grid[row][col]=num;
        mp[num].push_back({row, col});
        for (int k=0; k<4; ++k) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1) {
                dfs(grid, nr, nc, m, n, mp, num);
            }
        }
    }
    
    vector<vector<int>> norm(vector<vector<int>>& shape) {
        vector<vector<vector<int>>> res(8);
        for (auto& v:shape) {
            int r=v[0], c=v[1];
            res[0].push_back({r, c});
            res[1].push_back({r, -c});
            res[2].push_back({-r, c});
            res[3].push_back({-r, -c});
            res[4].push_back({c, r});
            res[5].push_back({c, -r});
            res[6].push_back({-c, r});
            res[7].push_back({-c, -r});
        }
        for (auto& s:res) sort(s.begin(), s.end());
        for (auto& s:res) {
            for (int i=1; i<s.size(); ++i) {
                s[i]={s[i][0]-s[0][0], s[i][1]-s[0][1]};
            }
            s[0]={0, 0};
        }
        
        sort(res.begin(), res.end());
        return res[0];
    }
    
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

