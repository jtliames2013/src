818. Race Car
DescriptionHintsSubmissionsDiscussSolution
Your car starts at position 0 and speed +1 on an infinite number line.  (Your car can go into negative positions.)

Your car drives automatically according to a sequence of instructions A (accelerate) and R (reverse).

When you get an instruction "A", your car does the following: position += speed, speed *= 2.

When you get an instruction "R", your car does the following: if your speed is positive then speed = -1 , otherwise speed = 1.  (Your position stays the same.)

For example, after commands "AAR", your car goes to positions 0->1->3->3, and your speed goes to 1->2->4->-1.

Now for some target position, say the length of the shortest sequence of instructions to get there.

Example 1:
Input: 
target = 3
Output: 2
Explanation: 
The shortest instruction sequence is "AA".
Your position goes from 0->1->3.
Example 2:
Input: 
target = 6
Output: 5
Explanation: 
The shortest instruction sequence is "AAARA".
Your position goes from 0->1->3->7->7->6.
 

Note:

1 <= target <= 10000.

class Solution {
public:
    int dfs(vector<int>& dp, int dist) {
        if (dp[dist]>0) return dp[dist];
        
        int d=dist, n=0;
        while (d) { d>>=1; n++; }
        if ((1<<n)==dist+1) dp[dist]=n;
        else {
            dp[dist]=dfs(dp, (1<<n)-1-dist)+n+1;
            for (int i=0; i<n-1; ++i) {
                dp[dist]=min(dp[dist], dfs(dp, dist-(1<<(n-1))+(1<<i))+n+i+1);
            }
        }
        return dp[dist];
    }
    
    int racecar(int target) {
        if (target<0) return 0;
        vector<int> dp(target+1);
        return dfs(dp, target);
    }
};
