1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
Hard

77

12

Add to List

Share
Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbours of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighboors if they share one edge.

Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.

Binary matrix is a matrix with all cells equal to 0 or 1 only.

Zero matrix is a matrix with all cells equal to 0.

 

Example 1:


Input: mat = [[0,0],[0,1]]
Output: 3
Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.
Example 2:

Input: mat = [[0]]
Output: 0
Explanation: Given matrix is a zero matrix. We don't need to change it.
Example 3:

Input: mat = [[1,1,1],[1,0,1],[0,0,0]]
Output: 6
Example 4:

Input: mat = [[1,0,0],[1,0,0]]
Output: -1
Explanation: Given matrix can't be a zero matrix
 

Constraints:

m == mat.length
n == mat[0].length
1 <= m <= 3
1 <= n <= 3
mat[i][j] is 0 or 1.

Airbnb
|
LeetCode

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int res=0, m=mat.size(), n=mat[0].size();
        queue<int> q;
        unordered_set<int> visited;
        int s=getState(mat);
        if (s==0) return 0;
        q.push(s);
        visited.insert(s);
        
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();
                
                for (int i=0; i<m; ++i) {
                    for (int j=0; j<n; ++j) {
                        int neighbor=getNeighbor(f, m, n, i, j);
                        if (neighbor==0) return res+1;
                        if (visited.find(neighbor)==visited.end()) {
                            q.push(neighbor);
                            visited.insert(neighbor);
                        }
                    }
                }
            }
            res++;
        }
        
        return -1;
    }
private:    
    int getState(vector<vector<int>>& mat) {
        int res=0, m=mat.size(), n=mat[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                res<<=1;
                res|=mat[i][j];
            }
        }
        return res;
    }
    
    int getNeighbor(int curr, int m, int n, int row, int col) {
        int total=m*n-1;
        curr^=1<<(total-row*n-col);
        for (int k=0; k<4; ++k) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n) curr^=1<<(total-nr*n-nc);            
        }
        return curr;
    }
    
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

