427. Construct Quad Tree
Medium

160

333

Favorite

Share
We want to use quad trees to store an N x N boolean grid. Each cell in the grid can only be true or false. The root node represents the whole grid. For each node, it will be subdivided into four children nodes until the values in the region it represents are all the same.

Each node has another two boolean attributes : isLeaf and val. isLeaf is true if and only if the node is a leaf node. The val attribute for a leaf node contains the value of the region it represents.

Your task is to use a quad tree to represent a given grid. The following example may help you understand the problem better:

Given the 8 x 8 grid below, we want to construct the corresponding quad tree:



It can be divided according to the definition above:



 

The corresponding quad tree should be as following, where each node is represented as a (isLeaf, val) pair.

For the non-leaf nodes, val can be arbitrary, so it is represented as *.



Note:

N is less than 1000 and guaranteened to be a power of 2.
If you want to know more about the quad tree, you can refer to its wiki.

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        if (n==0) return NULL;
        return dfs(grid, 0, n-1, 0, n-1);
    }
    
private:
    Node* dfs(vector<vector<int>>& grid, int r1, int r2, int c1, int c2) {
        if (r1==r2) {
            return new Node(grid[r1][c1]==1, true, NULL, NULL, NULL, NULL);
        }
        int mr=r1+(r2-r1)/2, mc=c1+(c2-c1)/2;
        Node *tl=dfs(grid, r1, mr, c1, mc);
        Node *tr=dfs(grid, r1, mr, mc+1, c2);
        Node *bl=dfs(grid, mr+1, r2, c1, mc);
        Node *br=dfs(grid, mr+1, r2, mc+1, c2);
        if (tl->val==tr->val && tl->val==bl->val && tl->val==br->val &&
            tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf) {
            return new Node(tl->val==true, true, NULL, NULL, NULL, NULL);
        } else {
            return new Node(false, false, tl, tr, bl, br);
        }
    }
};
