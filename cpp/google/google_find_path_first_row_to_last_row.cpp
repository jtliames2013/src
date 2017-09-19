没记错的话应该是一道面经题，输入是一个矩阵，只有0和1，路径只能上下左右包含1，判断这个矩阵是否有一条路径从这个矩阵的第一行到这个矩阵的最后一行
Follow up： 返回任意一条这样的路径
我还特意问了一下是不是返回最短的路径，妹子看了看题说就返回任意的一条。。dfs或者bfs，分析了一下矩阵会长什么样子和tradeoff，哪种情况下用哪种方法更好

class Solution {
public:
	bool dfs(vector<pair<int,int>>& res, vector<vector<int>>& grid, int row, int col, int m, int n) {
		if (row==m-1) return true;
		res.push_back({row, col});
		grid[row][col]=2;

		for (int k=0; k<4; k++) {
			int nr=row+delta[k][0];
			int nc=col+delta[k][1];
			if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==0) {
				if (dfs(res, grid, nr, nc, m, n)) return true;
			}
		}
		res.pop_back();
		return false;
	}

	vector<pair<int,int>> findPath(vector<vector<int>> grid) {
		vector<pair<int,int>> res;
		int m=grid.size();
		if (m==0) return res;
		int n=grid[0].size();
		if (n==0) return res;

		for (int i=0; i<n; i++) {
			if (grid[0][i]==0) {
				if (dfs(res, grid, 0, i, m, n)) break;
			}
		}

		return res;
	}
private:
	const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

2. shortest path
class Solution {
public:
	void getPath(vector<pair<int,int>>& res, unordered_map<int, int>& parent, int row, int col, int n) {
		res.push_back({row, col});
		int idx=row*n+col;
		while (parent.find(idx)!=parent.end()) {
			idx=parent[idx];
			res.push_back({idx/n, idx%n});
		}
	}

	vector<pair<int,int>> findPath(vector<vector<int>> grid) {
		vector<pair<int,int>> res;
		int m=grid.size();
		if (m==0) return res;
		int n=grid[0].size();
		if (n==0) return res;

		for (int i=0; i<n; i++) {
			if (grid[0][i]==0) {
				queue<pair<int,int>> q;
				unordered_map<int, int> parent;
				q.push({0, i});
				grid[0][i]=2;
				if (m==1) {
					res.push_back({0,i});
					return res;
				}

				while (!q.empty()) {
					int size=q.size();
					for (int j=0; j<size; j++) {
						pair<int,int> f=q.front();
						q.pop();
						for (int k=0; k<4; k++) {
							int nr=f.first+delta[k][0];
							int nc=f.second+delta[k][1];

							if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==0) {
								if (nr==m-1) {
									getPath(res, parent, nr, nc, n);
									return res;
								}
								parent[nr*n+nc]=f.first*n+f.second;
								q.push({nr, nc});
								grid[nr][nc]=2;
							}
						}
					}
				}
			}
		}
	}
private:
	const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

