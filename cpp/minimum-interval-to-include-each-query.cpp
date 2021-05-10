1851. Minimum Interval to Include Each Query
Hard

179

1

Add to List

Share
You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval starting at lefti and ending at righti (inclusive). The size of an interval is defined as the number of integers it contains, or more formally righti - lefti + 1.

You are also given an integer array queries. The answer to the jth query is the size of the smallest interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.

Return an array containing the answers to the queries.

 

Example 1:

Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
Output: [3,3,1,4]
Explanation: The queries are processed as follows:
- Query = 2: The interval [2,4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
- Query = 3: The interval [2,4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
- Query = 4: The interval [4,4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
- Query = 5: The interval [3,6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.
Example 2:

Input: intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
Output: [2,-1,4,6]
Explanation: The queries are processed as follows:
- Query = 2: The interval [2,3] is the smallest interval containing 2. The answer is 3 - 2 + 1 = 2.
- Query = 19: None of the intervals contain 19. The answer is -1.
- Query = 5: The interval [2,5] is the smallest interval containing 5. The answer is 5 - 2 + 1 = 4.
- Query = 22: The interval [20,25] is the smallest interval containing 22. The answer is 25 - 20 + 1 = 6.
 

Constraints:

1 <= intervals.length <= 105
1 <= queries.length <= 105
intervals[i].length == 2
1 <= lefti <= righti <= 107
1 <= queries[j] <= 107

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int m=intervals.size(), n=queries.size(), i=0;
        vector<int> res(n);
        unordered_map<int, int> mp;
        sort(intervals.begin(), intervals.end());
        vector<int> sortedQueries=queries;
        sort(sortedQueries.begin(), sortedQueries.end());
        auto cmp=[](vector<int>& a, vector<int>& b){ return a[0]>b[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (auto& q:sortedQueries) {
            while (i<m && intervals[i][0]<=q) {
                int l=intervals[i][0], r=intervals[i][1];
                pq.push({r-l+1, r});
                i++;
            }
            while (!pq.empty() && pq.top()[1]<q) {
                pq.pop();
            }
            
            mp[q]=pq.empty()?-1:pq.top()[0];
        }
        
        for (int i=0; i<n; ++i) res[i]=mp[queries[i]];
        return res;
    }
};

