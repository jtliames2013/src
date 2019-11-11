1203. Sort Items by Groups Respecting Dependencies
Hard

73

16

Favorite

Share
There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.

Return a sorted list of the items such that:

The items that belong to the same group are next to each other in the sorted list.
There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).
Return any solution if there is more than one solution and return an empty list if there is no solution.

 

Example 1:



Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
Output: [6,3,4,1,5,2,0,7]
Example 2:

Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
Output: []
Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.
 

Constraints:

1 <= m <= n <= 3*10^4
group.length == beforeItems.length == n
-1 <= group[i] <= m-1
0 <= beforeItems[i].length <= n-1
0 <= beforeItems[i][j] <= n-1
i != beforeItems[i][j]
beforeItems[i] does not contain duplicates elements.

class Graph {
public:
    Graph() {}
    
    void addEdge(int from, int to) {
        if (outgoing[from].find(to)==outgoing[from].end()) {
            outgoing[from].insert(to);
            incomingCount[to]++;
        }
    }
    
    void addVertex(int v) {
        outgoing[v];
        incomingCount[v];
    }
    
    vector<int> sort() {
        vector<int> res;
        unordered_set<int> st;
        for (auto iter:incomingCount) {
            if (iter.second==0) st.insert(iter.first);
        }
        
        while (!st.empty()) {
            int v=*st.begin();
            st.erase(st.begin());
            res.push_back(v);
            
            for (auto neighbor:outgoing[v]) {
                incomingCount[neighbor]--;
                if (incomingCount[neighbor]==0) st.insert(neighbor);
            }
        }
        
        return res;
    }
    
    int size() {
        return incomingCount.size();
    }
private:
    unordered_map<int, unordered_set<int>> outgoing;
    unordered_map<int, int> incomingCount;
};

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> res;
        Graph groups;
        vector<Graph> items(m);
        for (int i=0; i<n; ++i) {
            if (group[i]==-1) {
                group[i]=items.size();
                items.push_back(Graph());                
            }
            groups.addVertex(group[i]);
            items[group[i]].addVertex(i);
        }
        
        for (int i=0; i<n; ++i) {
            for (auto b:beforeItems[i]) {
                if (group[b]==group[i]) {
                    items[group[i]].addEdge(b, i);
                } else {
                    groups.addEdge(group[b], group[i]);
                }
            }
        }
        
        auto orderedGroups=groups.sort();
        if (orderedGroups.size()<groups.size()) return vector<int>();
        for (auto g:orderedGroups) {
            if (items[g].size()>0) {
                auto orderedItems=items[g].sort();
                if (orderedItems.size()<items[g].size()) return vector<int>();
                for (auto i:orderedItems) res.push_back(i);
            }
        }
        
        return res;
    }
};

