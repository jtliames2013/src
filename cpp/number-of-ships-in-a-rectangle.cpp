1274. Number of Ships in a Rectangle
Hard

50

5

Add to List

Share
(This problem is an interactive problem.)

On the sea represented by a cartesian plane, each ship is located at an integer point, and each integer point may contain at most 1 ship.

You have a function Sea.hasShips(topRight, bottomLeft) which takes two points as arguments and returns true if and only if there is at least one ship in the rectangle represented by the two points, including on the boundary.

Given two points, which are the top right and bottom left corners of a rectangle, return the number of ships present in that rectangle.  It is guaranteed that there are at most 10 ships in that rectangle.

Submissions making more than 400 calls to hasShips will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

 

Example :



Input: 
ships = [[1,1],[2,2],[3,3],[5,5]], topRight = [4,4], bottomLeft = [0,0]
Output: 3
Explanation: From [0,0] to [4,4] we can count 3 ships within the range.
 

Constraints:

On the input ships is only given to initialize the map internally. You must solve this problem "blindfolded". In other words, you must find the answer using the given hasShips API, without knowing the ships position.
0 <= bottomLeft[0] <= topRight[0] <= 1000
0 <= bottomLeft[1] <= topRight[1] <= 1000

Bloomberg
|
LeetCode

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        return dfs(sea, topRight[0], topRight[1], bottomLeft[0], bottomLeft[1]);
    }
private:
    int dfs(Sea sea, int tx, int ty, int bx, int by) {
        int res=0;
        if (bx>tx || by>ty || !sea.hasShips({tx, ty}, {bx, by})) return 0;
        if (bx==tx && by==ty) return 1;
        int mx=(bx+tx)/2, my=(by+ty)/2;
        res+=dfs(sea, mx, my, bx, by);
        res+=dfs(sea, mx, ty, bx, my+1);
        res+=dfs(sea, tx, my, mx+1, by);
        res+=dfs(sea, tx, ty, mx+1, my+1);

        return res;
    }
};

