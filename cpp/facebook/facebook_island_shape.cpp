. num of island
很快写完bfs 有个别小bug经提醒改出来了 然后问问复杂度 O(nm) 此时剩23min. more info on 1point3acres.com

2.followup
要求island unique shape，不考虑旋转，答纪录一下bfs的路径，比如用字符串表示，然后用hashset判下重，然后code改出来
又问好像字符串的处理可能不是O(1)，我说那可以用4进制数表示路径

class Solution {
public:
    long long bfs(vector<vector<char>>& grid, int row, int col, int m, int n) {
        long long shape=0;
    	queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col]='2';

        while (!q.empty()) {
            pair<int,int> f=q.front();
            q.pop();
            for (int k=0; k<4; k++) {
                int nr=f.first+delta[k][0];
                int nc=f.second+delta[k][1];
                if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1') {
                    shape<<=2;
                    shape|=(k & 0x3);
                	q.push({nr,nc});
                    grid[nr][nc]='2';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        unordered_set<long long> st;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]=='1') {
                    long long shape=bfs(grid, i, j, m, n);
                    st.insert(shape);
                }
            }
        }
        return st.size();
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

