1273. Delete Tree Nodes
Medium

38

19

Favorite

Share
A tree rooted at node 0 is given as follows:

The number of nodes is nodes;
The value of the i-th node is value[i];
The parent of the i-th node is parent[i].
Remove every subtree whose sum of values of nodes is zero.

After doing so, return the number of nodes remaining in the tree.

 

Example 1:



Input: nodes = 7, parent = [-1,0,0,1,2,2,2], value = [1,-2,4,0,-2,-1,-1]
Output: 2
 

Constraints:

1 <= nodes <= 10^4
-10^5 <= value[i] <= 10^5
parent.length == nodes
parent[0] == -1 which indicates that 0 is the root.

Microsoft
|
LeetCode

1. DFS
class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        unordered_map<int, unordered_set<int>> mp;
        for (int i=0; i<nodes; ++i) mp[parent[i]].insert(i);
        
        return dfs(mp, value, 0)[0];        
    }
private:
    vector<int> dfs(unordered_map<int, unordered_set<int>>& mp, vector<int>& value, int root) {
        int count=1, sum=value[root];
        for (auto child:mp[root]) {
            auto c=dfs(mp, value, child); // count, sum
            count+=c[0];
            sum+=c[1];
        }
        return { sum==0?0:count, sum };
    }
};

2. Assume parent[i]<i
class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<int> count(nodes, 1);
        for (int i=nodes-1; i>0; --i) {
            value[parent[i]]+=value[i];
            count[i]=value[i]==0?0:count[i];
            count[parent[i]]+=count[i];
        }
        return count[0];
    }
};
