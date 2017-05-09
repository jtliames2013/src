547. Friend Circles Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 5497
Total Submissions: 11161
Difficulty: Medium
Contributors:
lkpunisher
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.
Subscribe to see which companies asked this question.

Hide Tags Depth-first Search Union Find
Hide Similar Problems (M) Number of Connected Components in an Undirected Graph

1. DFS
class Solution {
public:
    void dfs(vector<vector<int>>& M, vector<bool>& visited, int i, int n) {
        visited[i]=true;
        for (int j=0; j<n; j++) {
            if (M[i][j]==1 && visited[j]==false) {
                dfs(M, visited, j, n);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        if (n==0) return 0;
        vector<bool> visited(n);
        int count=0;
        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                dfs(M, visited, i, n);
                count++;
            }
        }
        return count;
    }
};

2. Union Find
class Solution {
public:
    int find(vector<int>& parent, int i) {
        while (parent[i]!=i) i=parent[i];
        return i;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        if (n==0) return 0;
        vector<int> parent(n);
        for (int i=0; i<n; i++) parent[i]=i;
        
        int count=n;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (M[i][j]==1) {
                    int p1=find(parent, i);
                    int p2=find(parent, j);
                    if (p1!=p2) {
                        parent[p2]=p1;
                        count--;
                    }
                }
            }
        }
        
        return count;
    }
};

