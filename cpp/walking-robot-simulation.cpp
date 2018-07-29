874. Walking Robot Simulation
DescriptionHintsSubmissionsDiscussSolution
A robot on an infinite grid starts at point (0, 0) and faces north.  The robot can receive one of three possible types of commands:

-2: turn left 90 degrees
-1: turn right 90 degrees
1 <= x <= 9: move forward x units
Some of the grid squares are obstacles. 

The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])

If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route.)

Return the square of the maximum Euclidean distance that the robot will be from the origin.

 

Example 1:

Input: commands = [4,-1,3], obstacles = []
Output: 25
Explanation: robot will go to (3, 4)
Example 2:

Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
Output: 65
Explanation: robot will be stuck at (1, 4) before turning left and going to (1, 8)
 

Note:

0 <= commands.length <= 10000
0 <= obstacles.length <= 10000
-30000 <= obstacle[i][0] <= 30000
-30000 <= obstacle[i][1] <= 30000
The answer is guaranteed to be less than 2 ^ 31.

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int res=0;
        unordered_set<string> st;
        for (auto& o:obstacles) st.insert(to_string(o[0])+","+to_string(o[1]));
        int x=0, y=0, dir=0;
        for (auto c:commands) {
            if (c==-1) {
                dir=(dir+1)%4;
            } else if (c==-2) {
                dir--;
                if (dir<0) dir+=4;
            } else {
                while (c-->0) {
                    if (st.find(to_string(x+delta[dir][0])+","+to_string(y+delta[dir][1]))!=st.end()) break;
                    x+=delta[dir][0];
                    y+=delta[dir][1];
                }
            }
            res=max(res, x*x+y*y);            
        }
        
        return res;
    }
private:
    const int delta[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
};
