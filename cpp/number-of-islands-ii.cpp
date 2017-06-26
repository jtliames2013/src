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

The second optimization to naive method is Path Compression. The idea is to flatten the tree when find() is called. When find() is called for an element x, root of the tree is returned. The find() operation traverses up from x to find root. The idea of path compression is to make the found root as parent of x so that we don’t have to traverse all intermediate nodes again. If x is root of a subtree, then path (to root) from all nodes under x also compresses.

     
Let the subset {0, 1, .. 9} be represented as below and find() is called
for element 3.
              9
         /    |    \  
        4     5      6
     /     \        /  \
    0        3     7    8
            /  \
           1    2  

When find() is called for 3, we traverse up and find 9 as representative
of this subset. With path compression, we also make 3 as child of 9 so 
that when find() is called next time for 1, 2 or 3, the path to root is 
reduced.

               9
         /    /  \    \
        4    5    6     3 
     /           /  \   /  \
    0           7    8  1   2           

class Solution {
public:
    int find(vector<int>& root, int i) {
        while (i!=root[i]) i=root[i];
        /*while (i!=root[i]) {
            root[i]=root[root[i]];
            i=root[i];
        } */
        return i;
    }
    
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if (m==0 || n==0) return res;
        vector<int> root(m*n, -1);
        int num=0;
        
        for (auto& p:positions) {
            int i=p.first*n+p.second;
            root[i]=i;
            num++;
            
            for (int k=0; k<4; k++) {
                int nr=p.first+delta[k][0];
                int nc=p.second+delta[k][1];
                int ni=nr*n+nc;
                if (nr>=0 && nr<m && nc>=0 && nc<n && root[ni]!=-1) {
                    int nroot=find(root, ni);
                    if (nroot!=i) {
                        root[i]=nroot;
                        i=nroot;
                        num--;
                    }
                }
            }
            
            res.push_back(num);
        }
        
        return res;
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

