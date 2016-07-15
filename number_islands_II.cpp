305. Number of Islands II
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0

Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0

Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

Challenge:

Can you do it in time complexity O(k log mn), where k is the length of the positions?

Hide Company Tags Google
Hide Tags Union Find
Hide Similar Problems (M) Number of Islands

#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

// https://en.wikipedia.org/wiki/Disjoint-set_data_structure
//This is a basic union-find problem. Given a graph with points being added, we can at least solve:
//
//How many islands in total?
//Which island is pointA belonging to?
//Are pointA and pointB connected?
//The idea is simple. To represent a list of islands, we use trees. i.e., a list of roots. This helps us find the identifier of an island faster. If roots[c] = p means the parent of node c is p, we can climb up the parent chain to find out the identifier of an island, i.e., which island this point belongs to:
//
//Do root[root[roots[c]]]... until root[c] == c;
//To transform the two dimension problem into the classic UF, perform a linear mapping:
//
//int id = n * x + y;
//Initially assume every cell are in non-island set {-1}. When point A is added, we create a new root, i.e., a new island. Then, check if any of its 4 neighbors belong to the same island. If not, union the neighbor by setting the root to be the same. Remember to skip non-island cells.
//
//UNION operation is only changing the root parent so the running time is O(1).
//
//FIND operation is proportional to the depth of the tree. If N is the number of points added, the average running time is O(logN), and a sequence of 4N operations take O(NlogN). If there is no balancing, the worse case could be O(N^2).
//
//Remember that one island could have different roots[node] value for each node. Because roots[node] is the parent of the node, not the highest root of the island. To find the actually root, we have to climb up the tree by calling findIsland function.
//
//Here I've attached my solution. There can be at least two improvements: union by rank & path compression. However I suggest first finish the basis, then discuss the improvements.

class Solution {
public:
    int findRoot(vector<int>& roots, int n) {
        if (n!=roots[n]) {
            roots[n]=findRoot(roots, roots[n]);
        }
        return roots[n];
    }

    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if (m==0 || n==0) return res;
        int num=0;
        int neighbors[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        vector<int> roots(m*n, -1);

        for (auto p:positions) {
            // MakeSet
            int root=n*p.first+p.second;
            roots[root]=root;
            num++;

            for (int i=0; i<4; i++) {
                int x=p.first+neighbors[i][0];
                int y=p.second+neighbors[i][1];
                int neighbor=n*x+y;
                if (x<0 || x>=m || y<0 || y>=n || roots[neighbor]==-1) continue;

                // Union
                int neighborRoot=findRoot(roots, neighbor);  
                if (neighborRoot!=root) {
                    roots[root]=neighborRoot;
                    root=neighborRoot;
                    num--;
                }
            }

            res.push_back(num);
        }

        return res;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
