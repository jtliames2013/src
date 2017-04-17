210. Course Schedule II Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 56527
Total Submissions: 211487
Difficulty: Medium
Contributor: LeetCode
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
click to show more hints.

Hints:
This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
Subscribe to see which companies asked this question.

Hide Tags Depth-first Search Breadth-first Search Graph Topological Sort
Hide Similar Problems (M) Course Schedule (H) Alien Dictionary (M) Minimum Height Trees (M) Sequence Reconstruction

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        // [0, 1] 1 is prerequisite of 0 so 1-->0
        if (numCourses==0) return res;
        vector<unordered_set<int>> outgoingGraph(numCourses);
        vector<int> incomingCount(numCourses, 0);

        for (auto p:prerequisites) {
            if (outgoingGraph[p.second].find(p.first)==outgoingGraph[p.second].end()) {
                // NOTE: pair could be duplicate so check here to avoid incorectly increment count
                outgoingGraph[p.second].insert(p.first);
                incomingCount[p.first]++;
            }
        }
        
        unordered_set<int> st;
        for (int i=0; i<incomingCount.size(); i++) {
            if (incomingCount[i]==0) st.insert(i);
        }
        
        while (!st.empty()) {
            int v=*st.begin();
            st.erase(st.begin());
            res.push_back(v);
            
            for (auto neighbor:outgoingGraph[v]) {
                incomingCount[neighbor]--;
                if (incomingCount[neighbor]==0) st.insert(neighbor);
            }
        }
        
        for (auto c:incomingCount) {
            if (c>0) return vector<int>();
        }
        return res;
        
    }
};

