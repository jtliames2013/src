一个矩阵斜着走的list例子如下：
123
456
789
输出：{1}{42}{753}{86}{9}

class Solution {
public:
	void printDiag(int row, int col, vector<vector<int>>& matrix, int n) {
		while (row>=0 && col<n) {
			cout << matrix[row--][col++] << " ";
		}
		cout << endl;
	}
	void printMatrix(vector<vector<int>> matrix) {
		int m=matrix.size(), n=matrix[0].size();
		for (int i=0; i<m; i++) {
			printDiag(i, 0, matrix, n);
		}
		for (int i=1; i<n; i++) {
			printDiag(m-1, i, matrix, n);
		}
	}
};

int main()
{
	Solution s;
	vector<vector<int>> v={
			{1,2,3},
			{4,5,6},
			{7,8,9},
			{10,11,12}
	};
	s.printMatrix(v);
	return 0;
}

