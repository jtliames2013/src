第二輪 不相遇的皇后 
給一堆二維座標的皇后和牆, 只要有牆壁擋在Ｑ之間就不會互相攻擊 判斷是否給的Ｑ和Ｗ陣列，
輸出會相遇的Q pairs 

struct Point {
	int r;
	int c;
	Point(int a, int b):r(a), c(b) {}
};

class Solution {
public:
	void add(vector<pair<Point,Point>>& res, vector<Point>& q) {
		for (int i=0; i<q.size(); i++) {
			for (int j=i+1; j<q.size(); j++) {
				res.push_back({q[i], q[j]});
			}
		}
	}

	// (1,0) -> (0,1)
	void antidiag(vector<pair<Point,Point>>& res, vector<vector<char>>& grid, int row, int col) {
		int  n=grid.size();
		vector<Point> queen;
		while (row>=0 && col<n) {
			if (grid[row][col]=='1') {
				if (queen.size()>1) add(res, queen);
				queen.clear();
			} else if (grid[row][col]=='Q') {
				queen.push_back(Point(row, col));
			}
			row--;
			col++;
		}
	}

	// (0,0) -> (1,1)
	void diag(vector<pair<Point,Point>>& res, vector<vector<char>>& grid, int row, int col) {
		int  n=grid.size();
		vector<Point> queen;
		while (row<n && col<n) {
			if (grid[row][col]=='1') {
				if (queen.size()>1) add(res, queen);
				queen.clear();
			} else if (grid[row][col]=='Q') {
				queen.push_back(Point(row, col));
			}
			row++;
			col++;
		}
	}

	vector<pair<Point,Point>> queenMeet(vector<vector<char>> grid) {
		int n=grid.size();
		vector<pair<Point,Point>> res;
		for (int i=0; i<n; i++) {
			vector<Point> queen;
			for (int j=0; j<n; j++) {
				if (grid[i][j]=='1') {
					if (queen.size()>1) add(res, queen);
					queen.clear();
				} else if (grid[i][j]=='Q') {
					queen.push_back(Point(i, j));
				}
			}
		}

		for (int j=0; j<n; j++) {
			vector<Point> queen;
			for (int i=0; i<n; i++) {
				if (grid[i][j]=='1') {
					if (queen.size()>1) add(res, queen);
					queen.clear();
				} else if (grid[i][j]=='Q') {
					queen.push_back(Point(i, j));
				}
			}
		}

		for (int i=0; i<n; i++) {
			int row=i, col=0;
			antidiag(res, grid, row, col);
		}
		for (int i=1; i<n; i++) {
			int row=n-1, col=i;
			antidiag(res, grid, row, col);
		}

		for (int i=n-1; i>=0; i--) {
			int row=i, col=0;
			diag(res, grid, row, col);
		}
		for (int i=1; i<n; i++) {
			int row=0, col=i;
			diag(res, grid, row, col);
		}


		return res;
	}
};

