5297. Jump Game III
Medium

21

0

Add to List

Share
Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
Example 2:

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3
Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
 

Constraints:

1 <= arr.length <= 5 * 10^4
0 <= arr[i] < arr.length
0 <= start < arr.length

Microsoft
|
LeetCode

1. DFS
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> visited(n);
        return dfs(arr, visited, start);
    }
private:
    bool dfs(vector<int>& arr, vector<bool>& visited, int start) {
        if (start<0 || start>=arr.size() || visited[start]) return false;
        if (arr[start]==0) return true;
        visited[start]=true;
                
        if (dfs(arr, visited, start+arr[start])) return true;             
        if (dfs(arr, visited, start-arr[start])) return true;
        
        return false;
    }
};

2. BFS
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int> q;
        vector<bool> visited(n);
        q.push(start);
        visited[start]=true;
        
        while (!q.empty()) {
            auto f=q.front();
            q.pop();
            if (arr[f]==0) return true;
            
            for (auto next:{f+arr[f], f-arr[f]}) {                
                if (next>=0 && next<arr.size() && visited[next]==false) {
                    q.push(next);
                    visited[next]=true;
                }
            }
        }
        return false;
    }
};

