1345. Jump Game IV
Hard

46

4

Add to List

Share
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
Example 2:

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You don't need to jump.
Example 3:

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
Example 4:

Input: arr = [6,1,9]
Output: 2
Example 5:

Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
Output: 3
 

Constraints:

1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8

1. BFS
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int res=0, n=arr.size();
        if (n==1) return 0;
        unordered_map<int, unordered_set<int>> mp;
        for (int i=0; i<n; ++i) mp[arr[i]].insert(i);
        queue<int> q;
        vector<bool> visited(n);
        q.push(0);
        visited[0]=true;
        
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();
                
                if (f-1==n-1 || f+1==n-1 || mp[arr[f]].find(n-1)!=mp[f].end()) return res+1;
                if (f-1>=0 && visited[f-1]==false) {
                    q.push(f-1);
                    visited[f-1]=true;;
                }
                if (f+1<n && visited[f+1]==false) {
                    q.push(f+1);
                    visited[f+1]=true;
                }
                for (auto& neighbor:mp[arr[f]]) {
                    if (neighbor!=f && visited[neighbor]==false) {
                        q.push(neighbor);
                        visited[neighbor]=true;
                    }
                }
            }
            res++;
        }
        
        return -1;
    }
};

2. DFS (TLE)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int, unordered_set<int>> mp;
        for (int i=0; i<n; ++i) mp[arr[i]].insert(i);
        res=INT_MAX;
        vector<int> visited(n, INT_MAX);    
        dfs(arr, mp, visited, 0, 0);    
        return res;
    }
private:
    void dfs(vector<int>& arr, unordered_map<int, unordered_set<int>>& mp, vector<int>& visited, int start, int steps) {
        int n=arr.size();
        if (start==n-1) {
            res=min(res, steps);
            return;
        }
        if (visited[start]<=steps) return;
        visited[start]=steps;

        for (auto neighbor:mp[arr[start]]) {
            if (neighbor!=start) dfs(arr, mp, visited, neighbor, steps+1);
        }        
        if (start>0) dfs(arr, mp, visited, start-1, steps+1);
        if (start<n-1) dfs(arr, mp, visited, start+1, steps+1);
    }
    int res;
};

