一个boolean类型的二维矩阵，问是否存在一个矩形区域，它的4个顶点都是True

和第二轮第二题很相似，一个只有1或0的矩阵，求4个顶点都是1的矩形区域的数量

class Solution {
public:
	bool existRectangle(vector<vector<int>> grid) {
		int m=grid.size(), n=grid[0].size();
		vector<bitset<4>> bits(m);
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				if (grid[i][j]==1) bits[i].set(n-1-j);
			}
		}

		for (int i=0; i<m; i++) {
			for (int j=i+1; j<m; j++) {
				bitset<4> bit=bits[i]&bits[j];
				if (bit.count()>=2) return true;
			}
		}
		return false;
	}

	int numRectangle(vector<vector<int>> grid) {
		int res=0;
		int m=grid.size(), n=grid[0].size();
		vector<bitset<4>> bits(m);
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				if (grid[i][j]==1) bits[i].set(n-1-j);
			}
		}

		for (int i=0; i<m; i++) {
			for (int j=i+1; j<m; j++) {
				bitset<4> bit=bits[i]&bits[j];
				int cnt=bit.count();
				if (cnt>=2) res+=cnt*(cnt-1)/2;
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> grid1={{1,0,0,1}, {1,0,0,0}, {0,0,0,1}, {0,1,1,0}};
	vector<vector<int>> grid2={{1,1,1,1}, {1,0,0,0}, {0,0,0,1}, {1,1,1,1}};
	cout << s.existRectangle(grid1) << endl;
	cout << s.existRectangle(grid2) << endl;
	cout << s.numRectangle(grid1) << endl;
	cout << s.numRectangle(grid2) << endl;
	return 0;
}

