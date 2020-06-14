5456. Kth Ancestor of a Tree Node
Hard

84

36

Add to List

Share
You are given a tree with n nodes numbered from 0 to n-1 in the form of a parent array where parent[i] is the parent of node i. The root of the tree is node 0.

Implement the function getKthAncestor(int node, int k) to return the k-th ancestor of the given node. If there is no such ancestor, return -1.

The k-th ancestor of a tree node is the k-th node in the path from that node to the root.

 

Example:



Input:
["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]

Output:
[null,1,0,-1]

Explanation:
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);

treeAncestor.getKthAncestor(3, 1);  // returns 1 which is the parent of 3
treeAncestor.getKthAncestor(5, 2);  // returns 0 which is the grandparent of 5
treeAncestor.getKthAncestor(6, 3);  // returns -1 because there is no such ancestor
 

Constraints:

1 <= k <= n <= 5*10^4
parent[0] == -1 indicating that 0 is the root node.
0 <= parent[i] < n for all 0 < i < n
0 <= node < n
There will be at most 5*10^4 queries.

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        unordered_map<int, int> mp;
        for (int i=0; i<n; ++i) mp[i]=parent[i];
        ancestors.push_back(mp);
        for (int i=0; i<maxSteps; ++i) {
            auto &curr=ancestors.back();
            unordered_map<int, int> next;
            for (auto& iter:curr) {
                if (curr.find(iter.second)!=curr.end()) {
                    next[iter.first]=curr[iter.second];
                }
            }
            ancestors.push_back(next);
        }
    }
    
    int getKthAncestor(int node, int k) {
        int step=maxSteps;
        while (k>0 && node!=-1) {
            if (k>=(1<<step)) {
                if (ancestors[step].find(node)!=ancestors[step].end()) {
                    node=ancestors[step][node];
                } else {
                    node=-1;
                }
                k-=(1<<step);
            } else {
                step--;
            }
        }
        return node;
    }
private:
    int maxSteps=16;
    vector<unordered_map<int, int>> ancestors;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
