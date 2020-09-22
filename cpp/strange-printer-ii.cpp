1591. Strange Printer II
Hard

70

1

Add to List

Share
There is a strange printer with the following two special requirements:

On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
Once the printer has used a color for the above operation, the same color cannot be used again.
You are given a m x n matrix targetGrid, where targetGrid[row][col] is the color in the position (row, col) of the grid.

Return true if it is possible to print the matrix targetGrid, otherwise, return false.

 

Example 1:



Input: targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
Output: true
Example 2:



Input: targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
Output: true
Example 3:

Input: targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
Output: false
Explanation: It is impossible to form targetGrid because it is not allowed to print the same color in different turns.
Example 4:

Input: targetGrid = [[1,1,1],[3,1,3]]
Output: false
 

Constraints:

m == targetGrid.length
n == targetGrid[i].length
1 <= m, n <= 60
1 <= targetGrid[row][col] <= 60

class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int m=targetGrid.size(), n=targetGrid[0].size();
        vector<unordered_set<int>> graph(61);
        vector<int> visited(61);
        
        for (int i=0; i<61; ++i) {
            int rl=61, cl=61, ru=-1, cu=-1;
            for (int j=0; j<m; ++j) {
                for (int k=0; k<n; ++k) {
                    if (targetGrid[j][k]==i) {
                        rl=min(rl, j);
                        ru=max(ru, j);
                        cl=min(cl, k);
                        cu=max(cu, k);
                    }
                }
            }
            
            for (int r=rl; r<=ru; ++r) {
                for (int c=cl; c<=cu; ++c) {
                    if (targetGrid[r][c]!=i) {
                        graph[i].insert(targetGrid[r][c]);
                    }
                }
            }
        }
        
        for (int i=0; i<61; ++i) {
            if (visited[i]==0 && dfs(graph, visited, i)) return false;
        }
        return true;
    }
private:
    bool dfs(vector<unordered_set<int>>& graph, vector<int>& visited, int start) {
        visited[start]=1;
        
        for (auto& neighbor:graph[start]) {
            if (visited[neighbor]==1) return true;
            if (visited[neighbor]==0) {
                if (dfs(graph, visited, neighbor)) return true;
            }
        }
        
        visited[start]=2;
        return false;
    }
};

