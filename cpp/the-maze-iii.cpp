499. The Maze III
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up (u), down (d), left (l) or right (r), but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction. There is also a hole in this maze. The ball will drop into the hole if it rolls on to the hole.

Given the ball position, the hole position and the maze, find out how the ball could drop into the hole by moving the shortest distance. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the hole (included). Output the moving directions by using 'u', 'd', 'l' and 'r'. Since there could be several different shortest ways, you should output the lexicographically smallest way. If the ball cannot reach the hole, output "impossible".

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The ball and the hole coordinates are represented by row and column indexes.

Example 1

Input 1: a maze represented by a 2D array

0 0 0 0 0
1 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 1 0 0 0

Input 2: ball coordinate (rowBall, colBall) = (4, 3)
Input 3: hole coordinate (rowHole, colHole) = (0, 1)

Output: "lul"
Explanation: There are two shortest ways for the ball to drop into the hole.
The first way is left -> up -> left, represented by "lul".
The second way is up -> left, represented by 'ul'.
Both ways have shortest distance 6, but the first way is lexicographically smaller because 'l' < 'u'. So the output is "lul".

Example 2

Input 1: a maze represented by a 2D array

0 0 0 0 0
1 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 1 0 0 0

Input 2: ball coordinate (rowBall, colBall) = (4, 3)
Input 3: hole coordinate (rowHole, colHole) = (3, 0)
Output: "impossible"
Explanation: The ball cannot reach the hole.

Note:
There is only one ball and one hole in the maze.
Both the ball and hole exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and the width and the height of the maze won't exceed 30.

class Solution {
public:
    struct Point {
     	int row;
        int col;
        int len;
        string directions;
        Point():row(0), col(0), len(INT_MAX) {}
        Point(int r, int c, int l, string d):row(r), col(c), len(l), directions(d) {}
        bool LessorEqualTo(Point& p) {
            return this->len<p.len || (this->len==p.len && this->directions<=p.directions);
        }
    };
    
    class Compare {
    public:
        bool operator()(Point& a, Point& b) {
            return a.len>b.len || (a.len==b.len && a.directions>b.directions);
        }
    };
    
    string bfs(vector<vector<int>>& maze, vector<int> start, vector<int>& hole, int m, int n) {
        priority_queue<Point, vector<Point>, Compare> pq;
        vector<vector<Point>> Points(m, vector<Point>(n));        
        pq.push(Point(start[0], start[1], 0, ""));
        
        while (!pq.empty()) {
			Point f=pq.top();
            pq.pop();
            if (Points[f.row][f.col].LessorEqualTo(f)) continue;
            Points[f.row][f.col]=f;
            if (f.row==hole[0] && f.col==hole[1]) break;
            
            for (int k=0; k<4; k++) {
                Point np=f;
                while (np.row>=0 && np.row<m && np.col>=0 && np.col<n && maze[np.row][np.col]!=1 && 
                       (np.row!=hole[0] || np.col!=hole[1])) {
                    np.row+=delta[k][0];
                    np.col+=delta[k][1];
                    np.len++;
                }
                if (np.row!=hole[0] || np.col!=hole[1]) {
                    np.row-=delta[k][0];
                    np.col-=delta[k][1];
                    np.len--;
                }
                np.directions+=direction[k];
                pq.push(np);
            }
        }        

        if (Points[hole[0]][hole[1]].len==INT_MAX) {
            return "impossible";
        }
        return Points[hole[0]][hole[1]].directions;
    }
        
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m=maze.size();
        if (m==0) return "";
        int n=maze[0].size();
        if (n==0) return "";
                
        return bfs(maze, ball, hole, m, n);        
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
    const char direction[4]={'u', 'd', 'l', 'r'};
};

