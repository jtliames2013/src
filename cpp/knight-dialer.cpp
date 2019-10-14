935. Knight Dialer
Medium

320

116

Favorite

Share
A chess knight can move as indicated in the chess diagram below:

 .           

 

This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.  Each hop must be from one key to another numbered key.

Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing N digits total.

How many distinct numbers can you dial in this manner?

Since the answer may be large, output the answer modulo 10^9 + 7.

 

Example 1:

Input: 1
Output: 10
Example 2:

Input: 2
Output: 20
Example 3:

Input: 3
Output: 46
 

Note:

1 <= N <= 5000

class Solution {
public:
    int knightDialer(int N) {
        unordered_map<int, unordered_set<int>> mp={
            {0, {4,6}},
            {1, {6,8}},
            {2, {7,9}},
            {3, {4,8}},
            {4, {0,3,9}},
            {5, {}},
            {6, {0,1,7}},
            {7, {2,6}},
            {8, {1,3}},
            {9, {2,4}},
        };
        vector<int> count(10, 1);
        for (int i=0; i<N-1; ++i) {
            vector<int> next(10);
            for (int j=0; j<10; ++j) {
                for (auto k:mp[j]) {
                    next[k]=(next[k]+count[j])%mod;
                }
            }
            count=next;
        }
        return accumulate(count.begin(), count.end(), 0, [&](int l, int r){ return (l+r)%mod; });
    }
private:
    const int mod=pow(10,9)+7;
};
