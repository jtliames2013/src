1036. Escape a Large Maze
Hard

147

84

Favorite

Share
In a 1 million by 1 million grid, the coordinates of each grid square are (x, y) with 0 <= x, y < 10^6.

We start at the source square and want to reach the target square.  Each move, we can walk to a 4-directionally adjacent square in the grid that isn't in the given list of blocked squares.

Return true if and only if it is possible to reach the target square through a sequence of moves.

 

Example 1:

Input: blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
Output: false
Explanation: 
The target square is inaccessible starting from the source square, because we can't walk outside the grid.
Example 2:

Input: blocked = [], source = [0,0], target = [999999,999999]
Output: true
Explanation: 
Because there are no blocked cells, it's possible to reach the target square.
 

Note:

0 <= blocked.length <= 200
blocked[i].length == 2
0 <= blocked[i][j] < 10^6
source.length == target.length == 2
0 <= source[i][j], target[i][j] < 10^6
source != target

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {        
        unordered_set<long long> v1, v2;
        for (auto& b:blocked) {
            v1.insert(((long long)b[0]<<32) | b[1]);
            v2.insert(((long long)b[0]<<32) | b[1]);
        }
        return dfs(v1, source, target) && dfs(v2, target, source);
    }
private:
    bool dfs(unordered_set<long long>& visited, vector<int> source, vector<int>& target) {
        int n=1e6;
        if (source==target) return true;
        visited.insert(((long long)source[0]<<32) | source[1]);        
        if (visited.size()==21000) return true; // 21000 is a rough estimation
        
        for (int k=0; k<4; ++k) {
            int nr=source[0]+delta[k][0];
            int nc=source[1]+delta[k][1];

            if (nr>=0 && nr<n && nc>=0 && nc<n && visited.find(((long long)nr<<32) | nc)==visited.end()) {
                if (dfs(visited, {nr, nc}, target)) return true;
            }
        }
        return false;
    }
    
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

