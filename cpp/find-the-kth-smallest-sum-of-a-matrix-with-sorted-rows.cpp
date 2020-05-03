1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows
Hard

4

0

Add to List

Share
You are given an m * n matrix, mat, and an integer k, which has its rows sorted in non-decreasing order.

You are allowed to choose exactly 1 element from each row to form an array. Return the Kth smallest array sum among all possible arrays.

 

Example 1:

Input: mat = [[1,3,11],[2,4,6]], k = 5
Output: 7
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.  
Example 2:

Input: mat = [[1,3,11],[2,4,6]], k = 9
Output: 17
Example 3:

Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
Output: 9
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th sum is 9.  
Example 4:

Input: mat = [[1,1,10],[2,2,9]], k = 7
Output: 12
 

Constraints:

m == mat.length
n == mat.length[i]
1 <= m, n <= 40
1 <= k <= min(200, n ^ m)
1 <= mat[i][j] <= 5000
mat[i] is a non decreasing array.

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m=mat.size(), n=mat[0].size();
        int sum=0;
        for (int i=0; i<m; ++i) sum+=mat[i][0];
        vector<int> v(m);
        auto comp=[](pair<int, vector<int>>& a, pair<int, vector<int>>& b){ return a.first>b.first; };
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(comp)> pq(comp);
        set<vector<int>> st;
        pq.push({sum, v});
        st.insert(v);

        while (!pq.empty()) {
           auto t=pq.top();
            pq.pop();
            k--;
            if (k==0) return t.first;
            for (int i=0; i<m; ++i) {
                vector<int> v=t.second;
                if (v[i]<n-1) {
                    v[i]++;
                    if (st.find(v)==st.end()) {
                        pq.push({t.first+mat[i][v[i]]-mat[i][v[i]-1], v});
                        st.insert(v);
                    }
                }
            }
        }
        return 0;
    }
};

