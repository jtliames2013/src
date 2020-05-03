1434. Number of Ways to Wear Different Hats to Each Other
Hard

91

1

Add to List

Share
There are n people and 40 types of hats labeled from 1 to 40.

Given a list of list of integers hats, where hats[i] is a list of all hats preferred by the i-th person.

Return the number of ways that the n people wear different hats to each other.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: hats = [[3,4],[4,5],[5]]
Output: 1
Explanation: There is only one way to choose hats given the conditions. 
First person choose hat 3, Second person choose hat 4 and last one hat 5.
Example 2:

Input: hats = [[3,5,1],[3,5]]
Output: 4
Explanation: There are 4 ways to choose hats
(3,5), (5,3), (1,3) and (1,5)
Example 3:

Input: hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
Output: 24
Explanation: Each person can choose hats labeled from 1 to 4.
Number of Permutations of (1,2,3,4) = 24.
Example 4:

Input: hats = [[1,2,3],[2,3,5,6],[1,3,7,9],[1,8,9],[2,5,7]]
Output: 111
 

Constraints:

n == hats.length
1 <= n <= 10
1 <= hats[i].length <= 40
1 <= hats[i][j] <= 40
hats[i] contains a list of unique integers.

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        vector<vector<int>> people(41);
        int n=hats.size();
        for (int i=0; i<n; ++i) {
            for (auto h:hats[i]) people[h].push_back(i);
        }
        unsigned int state=0, mask=(1<<n)-1;
        unordered_map<int, int> mp;
        return dfs(people, mp, state, mask, 0);
    }
private:
    int dfs(vector<vector<int>>& people, unordered_map<int, int>& mp, unsigned int state, unsigned int mask, int start) {
        if (start==people.size()) return state==mask?1:0;
        int key=(state << 16) | start;
        if (mp.find(key)!=mp.end()) return mp[key];
        int res=0;
        for (auto p:people[start]) {
            if ((state & (1<<p)) == 0) {
                res=(res+dfs(people, mp, state | (1<<p), mask, start+1))%mod;
            }
        }
        res=(res+dfs(people, mp, state, mask, start+1))%mod;
        mp[key]=res;
        return res;
    }
    const int mod=1e9+7;
};

