52. N-Queens II
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

Hide Company Tags Zenefits
Hide Tags Backtracking
Hide Similar Problems (H) N-Queens

class Solution {
public:
	bool isValid(int row, int col, vector<int>& pos) {
		for (int i=0; i<pos.size(); i++) {
			if (pos[i]==col || abs(row-i)==abs(pos[i]-col)) {
				return false;
			}
		}
		return true;
	}

	void solve(int n, int row, vector<int>& pos, int& res) {
		if (row==n) {
			res++;
			return;
		}

		for (int col=0; col<n; col++) {
			if (isValid(row, col, pos)) {
				pos.push_back(col);
				solve(n, row+1, pos, res);
				pos.pop_back();
			}
		}
	}

    int totalNQueens(int n) {
    	int res=0;
    	vector<int> pos;
    	solve(n, 0, pos, res);

    	return res;
    }
};

