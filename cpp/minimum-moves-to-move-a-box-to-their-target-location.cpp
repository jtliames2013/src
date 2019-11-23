1263. Minimum Moves to Move a Box to Their Target Location
Hard

68

3

Favorite

Share
Storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.

The game is represented by a grid of size n*m, where each element is a wall, floor, or a box.

Your task is move the box 'B' to the target position 'T' under the following rules:

Player is represented by character 'S' and can move up, down, left, right in the grid if it is a floor (empy cell).
Floor is represented by character '.' that means free cell to walk.
Wall is represented by character '#' that means obstacle  (impossible to walk there). 
There is only one box 'B' and one target cell 'T' in the grid.
The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a push.
The player cannot walk through the box.
Return the minimum number of pushes to move the box to the target. If there is no way to reach the target, return -1.

 

Example 1:



Input: grid = [["#","#","#","#","#","#"],
               ["#","T","#","#","#","#"],
               ["#",".",".","B",".","#"],
               ["#",".","#","#",".","#"],
               ["#",".",".",".","S","#"],
               ["#","#","#","#","#","#"]]
Output: 3
Explanation: We return only the number of times the box is pushed.
Example 2:

Input: grid = [["#","#","#","#","#","#"],
               ["#","T","#","#","#","#"],
               ["#",".",".","B",".","#"],
               ["#","#","#","#",".","#"],
               ["#",".",".",".","S","#"],
               ["#","#","#","#","#","#"]]
Output: -1
Example 3:

Input: grid = [["#","#","#","#","#","#"],
               ["#","T",".",".","#","#"],
               ["#",".","#","B",".","#"],
               ["#",".",".",".",".","#"],
               ["#",".",".",".","S","#"],
               ["#","#","#","#","#","#"]]
Output: 5
Explanation:  push the box down, left, left, up and up.
Example 4:

Input: grid = [["#","#","#","#","#","#","#"],
               ["#","S","#",".","B","T","#"],
               ["#","#","#","#","#","#","#"]]
Output: -1
 

Constraints:

1 <= grid.length <= 20
1 <= grid[i].length <= 20
grid contains only characters '.', '#',  'S' , 'T', or 'B'.
There is only one character 'S', 'B' and 'T' in the grid.

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size(), res=0;
        
        vector<int> person, box, target;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]=='S') person={i, j};
                else if (grid[i][j]=='B') box={i, j};
                else if (grid[i][j]=='T') target={i, j};
            }
        }
        
        queue<pair<vector<int>, vector<int>>> q; // box position, person position
        unordered_set<int> visited;
        q.push({box, person});
        int key=((box[0]<<24) | (box[1]<<16) | (person[0]<<8) | person[1]);
        visited.insert(key) ;
        
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();
                
                for (int k=0; k<4; ++k) {
                    int nr=f.first[0]+delta[k][0], pr=f.first[0]-delta[k][0];
                    int nc=f.first[1]+delta[k][1], pc=f.first[1]-delta[k][1];
                    
                    if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]!='#' &&
                        pr>=0 && pr<m && pc>=0 && pc<n && grid[pr][pc]!='#') {
                        int key=((nr<<24) | (nc<<16) | (pr<<8) | pc);
                        if (visited.find(key)!=visited.end()) continue;
                        if (!canReach(grid, f.second, {pr, pc}, f.first)) continue;
                        if (target[0]==nr && target[1]==nc) return res+1;
                        q.push({{nr, nc}, f.first});
                        visited.insert(key);                        
                    }
                }                
            }
            res++;
        }
        return -1;
    }
private:
    bool canReach(vector<vector<char>>& grid, vector<int>& start, vector<int> end, vector<int>& box) {
        if (start==end) return true;
        int m=grid.size(), n=grid[0].size();
        queue<vector<int>> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert((start[0]<<16) | start[1]);
        
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();
                
                for (int k=0; k<4; ++k) {
                    int nr=f[0]+delta[k][0];
                    int nc=f[1]+delta[k][1];
                    if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]!='#' && visited.find((nr<<16) | nc)==visited.end()) {
                        if (box[0]==nr && box[1]==nc) continue;
                        if (end[0]==nr && end[1]==nc) return true;
                        q.push({nr, nc});
                        visited.insert((nr<<16) | nc);
                    }       
                }
            }            
        }
        return false;        
    }
    
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

