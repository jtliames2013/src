输入一个matrix，每个cell的值是当前cell的硬币数目，负值代表当前cell是blockage。问从左下角走到右上角最多可以collect多少硬币，并且输出collect最多硬币的路径（这个比较麻烦，不用输出路径的简单dp就搞定了）
比如：[[2,4,6], [1,-1,100]], 最大值是13 （1+2+4+6）

class Solution {
public:
	int getMaximumCoins(vector<vector<int> > &grid) {
		path.clear();
		int m=grid.size();
		if (m==0) return 0;
		int n=grid[0].size();
		if (n==0) return 0;
		vector<vector<int> > dp(m+1, vector<int>(n+1, -1));
		vector<vector<pair<int,int>>> route(m+1, vector<pair<int,int>>(n+1));

		if (grid[0][0]>=0) dp[1][1]=grid[0][0];
		for (int i=1; i<=m; i++) {
			for (int j=1; j<=n; j++) {
				if (grid[i-1][j-1]>=0) {
					if (dp[i-1][j]>dp[i][j-1]) {
						route[i][j]={i-1, j};
						dp[i][j]=dp[i-1][j]+grid[i-1][j-1];
					} else {
						if (dp[i][j-1]>=0) {
							route[i][j]={i, j-1};
							dp[i][j]=dp[i][j-1]+grid[i-1][j-1];
						}
					}
				}
			}
		}

		for (int i=m, j=n; ; ) {
			path.insert(path.begin(), {i-1, j-1});
			if (i==1 && j==1) break;

			pair<int,int> next=route[i][j];
			if (next.first<=0 || next.second<=0) {
				path.clear();
				break;
			}
			i=next.first;
			j=next.second;
		}

		return dp[m][n];
	}

	void printPath() {
		for (int i=0; i<path.size(); i++) {
			cout << path[i].first << " " << path[i].second << endl;
		}
	}
private:
	vector<pair<int,int> > path;
};

int main() {
	Solution s;
	//vector<vector<int> > grid={{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<int> > grid={{1,-1,100},{4,5,6}};
	int res=s.getMaximumCoins(grid);
	cout << res << endl;
	s.printPath();
	return 0;
}

