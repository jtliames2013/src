1041. Robot Bounded In Circle
Easy

30

27

Favorite

Share
On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degress to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

Example 1:

Input: "GGLLGG"
Output: true
Explanation: 
The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
Example 2:

Input: "GG"
Output: false
Explanation: 
The robot moves north indefinetely.
Example 3:

Input: "GL"
Output: true
Explanation: 
The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 

Note:

1 <= instructions.length <= 100
instructions[i] is in {'G', 'L', 'R'}

There is an circle if
1. if the robot returns to the origin, or
2. the robot finishes not facing north, and can return to origin in another one or three sequences.

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0, y=0, d=0;
        for (int i=0; i<instructions.size(); ++i) {
            if (instructions[i]=='G') {
                x+=delta[d][0];
                y+=delta[d][1];
            } else if (instructions[i]=='L') {
                d=(d+3)%4;
            } else {
                d=(d+1)%4;
            }
        }
        return (x==0 && y==0) || d>0;
    }
private:
    const int delta[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
};
