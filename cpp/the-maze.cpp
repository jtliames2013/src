490. The Maze
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

Example 1

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: false
Explanation: There is no way for the ball to stop at the destination.

Note:
There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.

1. BFS
class Solution {
public:
    bool bfs(vector<vector<int>>& maze, vector<int> start, vector<int>& destination, int m, int n) {
        queue<vector<int>> q;
        maze[start[0]][start[1]]=2;
        q.push(start);
        
        while (!q.empty()) {
			vector<int> f=q.front();
            q.pop();
            
            for (int k=0; k<4; k++) {
                vector<int> np=f;
                while (np[0]>=0 && np[0]<m && np[1]>=0 && np[1]<n && maze[np[0]][np[1]]!=1) {
                    np[0]+=delta[k][0];
                    np[1]+=delta[k][1];
                }
                np[0]-=delta[k][0];
                np[1]-=delta[k][1];
                if (maze[np[0]][np[1]]!=0) continue;         
                if (np==destination) return true;
                maze[np[0]][np[1]]=2;
                q.push(np);
            }
        }        

        return false;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m=maze.size();
        if (m==0) return false;
        int n=maze[0].size();
        if (n==0) return false;
                
        return bfs(maze, start, destination, m, n);
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};    
};

2. DFS, TLE
class Solution {
public:
    bool dfs(vector<vector<int>>& maze, vector<int> pos, vector<int>& destination, int m, int n) {
        if (pos[0]==destination[0] && pos[1]==destination[1]) return true;
        maze[pos[0]][pos[1]]=2;
        
        for (int k=0; k<4; k++) {
            vector<int> np=pos;            
            while (np[0]>=0 && np[0]<m && np[1]>=0 && np[1]<n && maze[np[0]][np[1]]!=1) {
                np[0]+=delta[k][0];
                np[1]+=delta[k][1];
            }
            np[0]-=delta[k][0];
            np[1]-=delta[k][1];
			if (maze[np[0]][np[1]]!=0) continue;
            
           	if (dfs(maze, np, destination, m, n)) return true;
        }
        
        maze[pos[0]][pos[1]]=0;
        return false;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m=maze.size();
        if (m==0) return false;
        int n=maze[0].size();
        if (n==0) return false;
                
        return dfs(maze, start, destination, m, n);
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};    
};

