// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

 https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/

#include "stdafx.h"
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        m=matrix.size();
        n=0;
        if (m>0) n=matrix[0].size();

        tree.resize(m+1, vector<int>(n+1, 0));
        nums.resize(m+1, vector<int>(n+1, 0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        if (m==0||n==0) return;

        int delta=val-nums[row][col];
        nums[row][col]=val;
        for (int i=row+1; i<=m; i += i & (-i)) {
            for (int j=col+1; j<=n; j += j & (-j)) {
                tree[i][j] += delta;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m==0 || n==0) return 0;
        return sum(row2+1, col2+1)-sum(row2+1, col1)-sum(row1, col2+1)+sum(row1, col1);
    }

    int sum(int row, int col) {
        int sum=0;
        for (int i=row; i>0; i -= i & (-i)) {
            for (int j=col; j>0; j -= j & (-j)) {
                sum+=tree[i][j];
            }
        }
        return sum;
    }
private:
    vector<vector<int>> tree;
    vector<vector<int>> nums;
    int m;
    int n;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}