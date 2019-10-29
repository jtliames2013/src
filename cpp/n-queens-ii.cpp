52. N-Queens II
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

Hide Company Tags Zenefits
Hide Tags Backtracking
Hide Similar Problems (H) N-Queens

class Solution {
public:
    int totalNQueens(int n) {
        int res=0;
        vector<int> pos;
        dfs(res, pos, n, 0);

        return res;
    }
private:
    void dfs(int& res, vector<int>& pos, int n, int start) {
        if (start==n) {
            res++;
            return;
        }

        for (int col=0; col<n; ++col) {
            if (isValid(pos, col)) {
                pos.push_back(col);
                dfs(res, pos, n, start+1);
                pos.pop_back();
            }
        }
    }

    bool isValid(vector<int>& pos, int col) {
        int row=pos.size();
        for (int i=0; i<pos.size(); ++i) {
            if (pos[i]==col || abs(pos[i]-col)==row-i) return false;
        }
        return true;
    }
};
