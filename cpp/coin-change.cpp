322. Coin Change
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.

1. Dynamic Programming
贪心算法是不正确的，因为有可能会错过全局最优解。
[1, 4, 5] 12
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0]=0;
        for (int i=1; i<=amount; i++) {
            for (auto c:coins) {
                if (i>=c) dp[i]=min(dp[i], dp[i-c]+1);              
            }
        }
        
        return dp[amount]==amount+1?-1:dp[amount];
    }
};

2.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount<0) return -1;
        vector<int> dp(amount+1, -1);
        dp[0]=0;
        for (int i=0; i<=amount; i++) {
            if (dp[i]==-1) continue;
            for (int j=0; j<coins.size(); j++) {
                long next=i+(long)coins[j];
                if (next<=amount) {
                    if (dp[next]==-1 || dp[next]>dp[i]+1) dp[next]=dp[i]+1;                    
                }
            }
        }

        return dp[amount];
    }
};

3. BFS
将问题转化为求X轴0点到坐标点amount的最短距离（每次向前行进的合法距离为coin的面值）
https://leetcode.com/discuss/76432/fast-python-bfs-solution
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {        
        if (amount<=0) return 0;
        int res=0;
        queue<int> q;
        vector<bool> visited(amount+1);
        q.push(0);
        visited[0]=true;
        
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();
                
                for (auto c:coins) {
                    int next=f+c;
                    if (next<=amount && visited[next]==false) {
                        if (next==amount) return res+1;
                        q.push(next);
                        visited[next]=true;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};

