1102. Path With Maximum Minimum Value
Medium

197

22

Add to List

Share
Given a matrix of integers A with R rows and C columns, find the maximum score of a path starting at [0,0] and ending at [R-1,C-1].

The score of a path is the minimum value in that path.  For example, the value of the path 8 →  4 →  5 →  9 is 4.

A path moves some number of times from one visited cell to any neighbouring unvisited cell in one of the 4 cardinal directions (north, east, west, south).

 

Example 1:



Input: [[5,4,5],[1,2,6],[7,4,6]]
Output: 4
Explanation: 
The path with the maximum score is highlighted in yellow. 
Example 2:



Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
Output: 2
Example 3:



Input: [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
Output: 3
 

Note:

1 <= R, C <= 100
0 <= A[i][j] <= 10^9

Amazon
|
9

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int m=A.size(), n=A[0].size(), res=A[0][0];
        priority_queue<vector<int>> pq;
        pq.push({A[0][0], 0, 0});
        A[0][0]=-1;
        
        while (!pq.empty()) {
            auto t=pq.top();
            pq.pop();
            
            res=min(res, t[0]);
            if (t[1]==m-1 && t[2]==n-1) return res;
            
            for (int k=0; k<4; ++k) {
                int nr=t[1]+delta[k][0];
                int nc=t[2]+delta[k][1];
                if (nr>=0 && nr<m && nc>=0 && nc<n && A[nr][nc]>=0) {
                    pq.push({A[nr][nc], nr, nc});
                    A[nr][nc]=-1;
                }
            }
        }
        return res;
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

