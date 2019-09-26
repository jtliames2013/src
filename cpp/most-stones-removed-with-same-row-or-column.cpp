947. Most Stones Removed with Same Row or Column
Medium

571

166

Favorite

Share
On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Example 3:

Input: stones = [[0,0]]
Output: 0
 

Note:

1 <= stones.length <= 1000
0 <= stones[i][j] < 10000

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        islands=0;
        for (int i=0; i<stones.size(); ++i) {
            uni(stones[i][0], ~stones[i][1]);
        }
        return stones.size()-islands;
    }
private:
    void uni(int x, int y) {
        int rx=find(x), ry=find(y);
        if (rx!=ry) {
            root[rx]=ry;
            islands--;
        }
    }
    
    int find(int x) {
        if (root.find(x)==root.end()) {
            islands++;
            root[x]=x;
        }
        while (x!=root[x]) x=root[x];
        return x;
    }
    
    unordered_map<int,int> root;
    int islands;
};
