Given a M X N grid, a random cell in the grid (coordinate for example), find number of ways you can reach top-left corner in k steps, assuming you can move in any direction.

class Solution {
public:
	  int uniquePaths(int m, int n, int s, int startRow, int startCol) {
		  if (m==0||n==0||s<0) return 0;
		  if (startRow<0||startRow>=m||startCol<0||startCol>=n) return 0;
		  int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};

		  vector<vector<vector<int> > > dp(m, vector<vector<int> >(n, vector<int>(s+1, 0)));
		  for (int i=0; i<m; i++) {
			  for (int j=0; j<n; j++) {
				  if (i==startRow && j==startCol) dp[i][j][0]=1;
				  else dp[i][j][0]=0;
			  }
		  }

		  for (int k=1; k<=s; k++) {
			  for (int i=0; i<m; i++) {
				  for (int j=0; j<n; j++) {
					  for (int idx=0; idx<4; idx++) {
						  int neighborRow=i+delta[idx][0];
						  int neighborCol=j+delta[idx][1];
						  if (neighborRow>=0 && neighborRow<m && neighborCol>=0 && neighborCol<n) {
							  dp[i][j][k]+=dp[neighborRow][neighborCol][k-1];
						  }
					  }
				  }
			  }
		  }

		  return dp[0][0][s];
	  }
  };

int main() {
	Solution s;
	int res=s.uniquePaths(2, 2, 2, 1, 1);
	return 0;
}

