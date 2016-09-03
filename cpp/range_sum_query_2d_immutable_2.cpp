// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

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
        int m=matrix.size();
        if (m==0) return;
        int n=matrix[0].size();
        if (n==0) return;
        sums.resize(m+1, vector<int>(n+1, 0));

        for (int i=0; i<=m; i++) {
            for (int j=0; j<=n; j++) {
                if (i==0 || j==0) sums[i][j]=0;
                else {
                    sums[i][j]=matrix[i-1][j-1]+sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1]-sums[row1][col2+1]-sums[row2+1][col1]+sums[row1][col1];        
    }
private:
    vector<vector<int>> sums;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}