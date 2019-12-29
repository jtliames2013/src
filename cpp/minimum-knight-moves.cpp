1197. Minimum Knight Moves
Medium

84

34

Add to List

Share
In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.



Return the minimum number of steps needed to move the knight to the square [x, y].  It is guaranteed the answer exists.

 

Example 1:

Input: x = 2, y = 1
Output: 1
Explanation: [0, 0] → [2, 1]
Example 2:

Input: x = 5, y = 5
Output: 4
Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
 

Constraints:

|x| + |y| <= 300

Facebook
|
6

Google
|
5

1. DFS
class Solution {
public:
    int minKnightMoves(int x, int y) {
        unordered_map<int, int> mp;
        return dfs(mp, abs(x), abs(y));        
    }
private:
    int dfs(unordered_map<int, int>& mp, int x, int y) {
        int key=(x<<16) | y;
        if (mp.find(key)!=mp.end()) return mp[key];
        int res=0;
        if (x+y==0) res=0;
        else if (x+y==2) res=2;
        else {
            res=min(dfs(mp, abs(x-1), abs(y-2)), dfs(mp, abs(x-2), abs(y-1)))+1;
        }
        
        mp[key]=res;
        return res;
    }
};

2.
https://stackoverflow.com/questions/2339101/knights-shortest-path-on-chessboard/8778592#8778592
