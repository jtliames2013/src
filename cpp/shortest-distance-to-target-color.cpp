1182. Shortest Distance to Target Color
Medium

66

2

Add to List

Share
You are given an array colors, in which there are three colors: 1, 2 and 3.

You are also given some queries. Each query consists of two integers i and c, return the shortest distance between the given index i and the target color c. If there is no solution return -1.

 

Example 1:

Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
Output: [3,0,3]
Explanation: 
The nearest 3 from index 1 is at index 4 (3 steps away).
The nearest 2 from index 2 is at index 2 itself (0 steps away).
The nearest 1 from index 6 is at index 3 (3 steps away).
Example 2:

Input: colors = [1,2], queries = [[0,3]]
Output: [-1]
Explanation: There is no 3 in the array.
 

Constraints:

1 <= colors.length <= 5*10^4
1 <= colors[i] <= 3
1 <= queries.length <= 5*10^4
queries[i].length == 2
0 <= queries[i][0] < colors.length
1 <= queries[i][1] <= 3

1. DP
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int m=colors.size(), n=queries.size();
        vector<int> res(n, -1);
        vector<vector<int>> dist(3, vector<int>(m, INT_MAX));
        
        for (int c=0; c<3; ++c) {            
            for (int i=0; i<m; ++i) {
                if (c==colors[i]-1) dist[c][i]=0;
                else if(i>0 && dist[c][i-1]!=INT_MAX) dist[c][i]=dist[c][i-1]+1;
            }
                        
            for (int i=m-1; i>=0; --i) {
                if (c==colors[i]-1) dist[c][i]=0;
                else if(i<m-1 && dist[c][i+1]!=INT_MAX) dist[c][i]=min(dist[c][i], dist[c][i+1]+1);               
            }
        }
        
        for (int i=0; i<n; ++i) {
            if (dist[queries[i][1]-1][queries[i][0]]!=INT_MAX) {
                res[i]=dist[queries[i][1]-1][queries[i][0]];
            }
        }
        return res;
    }
};

2. binary search
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int> res(n, INT_MAX);
        unordered_map<int, set<int>> mp;
        for (int i=0; i<colors.size(); ++i) mp[colors[i]].insert(i);
        
        for (int i=0; i<n; ++i) {
            int idx=queries[i][0], c=queries[i][1];            
            auto lower=mp[c].lower_bound(idx);
            if (lower!=mp[c].end()) res[i]=*lower-idx;            
            if (lower!=mp[c].begin()) res[i]=min(res[i], idx-*prev(lower));            
            if (res[i]==INT_MAX) res[i]=-1;
        }
        return res;
    }
};

