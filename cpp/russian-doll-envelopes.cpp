354. Russian Doll Envelopes 
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Hide Company Tags Google
Hide Tags Binary Search Dynamic Programming
Hide Similar Problems (M) Longest Increasing Subsequence

1.
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        if (n==0) return 0;
        vector<int> dp(n, 1);
        int res=1;
        sort(envelopes.begin(), envelopes.end());
        
        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (envelopes[j][0]<envelopes[i][0] && envelopes[j][1]<envelopes[i][1]) {
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
            res=max(res, dp[i]);
        }
        return res;
    }
};

2. Binary search
Sort the array. Ascend on width and DESCEND on height if width are same.
Find the longest increasing subsequence based on height.

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n=envelopes.size();
        if (n==0) return 0;
        auto comp=[](pair<int,int> a, pair<int,int> b) { return a.first<b.first || (a.first==b.first && a.second>b.second); };
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int> sorted;
        for (int i=0; i<n; i++) {
            auto iter=lower_bound(sorted.begin(), sorted.end(), envelopes[i].second);
            if (iter==sorted.end()) sorted.push_back(envelopes[i].second);
            else *iter=envelopes[i].second;
        }
        
        return sorted.size();
    }
};

