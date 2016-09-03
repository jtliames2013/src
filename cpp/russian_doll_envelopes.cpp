354. Russian Doll Envelopes 
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Hide Company Tags Google
Hide Tags Binary Search Dynamic Programming
Hide Similar Problems (M) Longest Increasing Subsequence

这道题给了我们一堆大小不一的信封，让我们像套俄罗斯娃娃那样把这些信封都给套起来，这道题实际上是之前那道Longest Increasing Subsequence的具体应用，而且难度增加了，从一维变成了两维，但是万变不离其宗，解法还是一样的，首先来看DP的解法，这是一种brute force的解法，首先要给所有的信封按从小到大排序，首先根据宽度从小到大排，如果宽度相同，那么高度小的再前面，这是STL里面sort的默认排法，所以我们不用写其他的comparator，直接排就可以了，然后我们开始遍历，对于每一个信封，我们都遍历其前面所有的信封，如果当前信封的长和宽都比前面那个信封的大，那么我们更新dp数组，通过dp[i] = max(dp[i], dp[j] + 1)。然后我们每遍历完一个信封，都更新一下结果res，参见代码如下；

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int res=0;
        int n=envelopes.size();
        if (n==0) return res;
        vector<int> dp(n, 1);
        sort(envelopes.begin(), envelopes.end());
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (envelopes[i].first>envelopes[j].first && envelopes[i].second>envelopes[j].second && dp[i]<dp[j]+1) {
                    dp[i]=dp[j]+1;
                }
            }
            
            res=max(res, dp[i]);
        }
        
        return res;
    }
};

