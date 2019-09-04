207. Course Schedule Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 75724
Total Submissions: 242621
Difficulty: Medium
Contributor: LeetCode
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
Subscribe to see which companies asked this question.

Hide Tags Depth-first Search Breadth-first Search Graph Topological Sort
Hide Similar Problems (M) Course Schedule II (M) Graph Valid Tree (M) Minimum Height Trees

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // [0, 1] 1 is prerequisite of 0 so 1-->0
        if (numCourses==0) return true;
        vector<unordered_set<int>> outgoingGraph(numCourses);
        vector<int> incomingCount(numCourses);

        for (auto& p:prerequisites) {
            if (outgoingGraph[p[1]].find(p[0])==outgoingGraph[p[1]].end()) {
                // NOTE: pair could be duplicate so check here to avoid incorectly increment count
                outgoingGraph[p[1]].insert(p[0]);
                incomingCount[p[0]]++;
            }
        }
        
        unordered_set<int> st;
        for (int i=0; i<incomingCount.size(); ++i) {
            if (incomingCount[i]==0) st.insert(i);
        }

        while (!st.empty()) {
            int v=*st.begin();
            st.erase(st.begin());
            
            for (auto neighbor:outgoingGraph[v]) {
                incomingCount[neighbor]--;
                if (incomingCount[neighbor]==0) st.insert(neighbor);
            }
        }
        
        for (auto c:incomingCount) {
            if (c>0) return false;
        }
        return true;
    }
};
