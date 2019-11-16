943. Find the Shortest Superstring
Hard

234

60

Favorite

Share
Given an array A of strings, find any smallest string that contains each string in A as a substring.

We may assume that no string in A is substring of another string in A.

 
Example 1:

Input: ["alex","loves","leetcode"]
Output: "alexlovesleetcode"
Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
Example 2:

Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc"
 

Note:

1 <= A.length <= 12
1 <= A[i].length <= 20

graph[i][j] means the length of string to append when A[i] followed by A[j]. eg. A[i] = abcd, A[j] = bcde, then graph[i][j] = 1
Then the problem becomes to: find the shortest path in this graph which visits every node exactly once. This is a Travelling Salesman Problem.
Apply TSP DP solution. Remember to record the path.

https://www.youtube.com/watch?v=-JjA4BLQyqE
https://github.com/mission-peace/interview/blob/master/src/com/interview/graph/TravelingSalesmanHeldKarp.java
https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/tutorial/

class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        string res;
        int n=A.size();
        vector<vector<int>> graph(n, vector<int>(n));        
        buildGraph(A, graph);
        
        vector<vector<int>> dp(1<<n, vector<int>(n, INT_MAX)), edge(1<<n, vector<int>(n));        
        int last, mn=INT_MAX;
        for (int i=1; i<(1<<n); ++i) {
            for (int j=0; j<n; ++j) {
                if ((i & (1<<j))>0) {
                    int prev=i-(1<<j);
                    if (prev==0) {
                        dp[i][j]=A[j].size();
                    } else {
                        for (int k=0; k<n; ++k) {
                            if (dp[prev][k]<INT_MAX && dp[prev][k]+graph[k][j]<dp[i][j]) {
                                dp[i][j]=dp[prev][k]+graph[k][j];
                                edge[i][j]=k;
                            }
                        }
                    }
                }
                if (i==(1<<n)-1 && dp[i][j]<mn) {
                    mn=dp[i][j];
                    last=j;
                }
            }
        }
        
        vector<int> path(n);
        int curr=(1<<n)-1, i=n-1;
        while (curr>0) {
            path[i--]=last;
            int tmp=curr;
            curr-=(1<<last);
            last=edge[tmp][last];
        }
        
        res=A[path[0]];
        for (int i=1; i<n; ++i) {
            res+=A[path[i]].substr(A[path[i]].size()-graph[path[i-1]][path[i]]);
        }
        return res;
    }
private:
    void buildGraph(vector<string>& A, vector<vector<int>>& graph) {
        for (int i=0; i<A.size(); ++i) {
            for (int j=0; j<A.size(); ++j) {
                graph[i][j]=cost(A[i], A[j]);
                graph[j][i]=cost(A[j], A[i]);                
            }
        }
    }

    int cost(string& a, string& b) {
        int m=a.size(), n=b.size(), i=m-min(m, n), j;
        // max suffix and prefix overlap
        for (; i<m; ++i) {            
            for (j=0; i+j<m && j<n; ++j) {
                if (a[i+j]!=b[j]) break;
            }
            if (i+j==m || j==n) return n-m+i;
        }
        return n;
    }
};


