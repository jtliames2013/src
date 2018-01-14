2-d array of "sharpness" values： Fine the path from left to right which has the highest minimum sharpness. 路径必须是从左往右，先有个起始点，然后每次要往右上，正右或右下跳一步。也就是说，路径长度是列数n，假设路径为(i1,1),(i2,2),...,(in,n)，路径必须满足每对i_k与i_{k-1}的距离不能大于1.
.5 .7 .2
.7 .5 .8
.9 .1 .5
在这个例子中，理想路径是.7->.7->.8因为这条路径中的最小值.7在所有路径中最大。只需要返回这个值，不需要返回路径。

从最左一列中的任意一个出发，到达最右一列的任意一个，要求：
1）当前格子要想往右走，只能往右上、右边、右下三个格子移动；
2）一条path中最小的那个值才是这条path的合格value
3）在所有path中找到合格value最大的那一条，输出它的value。

class Solution {
public:
	int highestMinSharpness(vector<vector<int>>& board) {
		int m=board.size();
		if(m==0) return 0;
		int n=board[0].size();
		if (n==0) return 0;

		vector<int> dp(m);
		for (int i=0; i<m; i++) dp[i]=board[i][0];
		for (int i=1; i<n; i++) {
			vector<int> next(m);
			for (int j=0; j<m; j++) {
				int val=dp[j];
				if (j>0) val=max(val, dp[j-1]);
				if (j<m-1) val=max(val, dp[j+1]);
				next[j]=min(board[j][i], val);
			}
			dp=next;
		}

		int res=INT_MIN;
		for (int i=0; i<m; i++) res=max(res, dp[i]);
		return res;
	}
};

int main() {
	Solution s;
	vector<vector<int>> board1={
		{5, 7, 2},
		{7, 5, 8},
		{9, 1, 5}
	};
	int res1=s.highestMinSharpness(board1);
	cout << res1 << endl;

	vector<vector<int>> board2={
		{4, 5, 4, 0, 1, 2},
		{5, 6, 5, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{1, 3, 1, 2, 3, 3},
		{3, 0, 3, 0, 0, 0}
	};
	int res2=s.highestMinSharpness(board2);
	cout << res2 << endl;

	return 0;
}

