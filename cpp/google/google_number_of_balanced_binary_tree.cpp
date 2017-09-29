类似LC 96, 但是只是BT，不是BST，输入是一个先序排列的nodes， 输出有能有多少颗树。 follow up: 能有多少颗平衡的树呢？  我说了对每个长度用log 来判断一下，他说log 有些conner case 覆盖不了。后来给了hint， 用 DP[节点个数][高度]， 但我始终还是想不到节点个数跟高度的联系，除了log。

Count Balanced Binary Trees of Height h
Given a height h, count and return the maximum number of balanced binary trees possible with height h. A balanced binary tree is one in which for every node, the difference between heights of left and right subtree is not more than 1.

#define mod 1000000007
  
long long int countBT(int h) {
      
    long long int dp[h + 1];
    //base cases
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= h; i++) {
        dp[i] = ((dp[i - 1] * ((2 * (dp [i - 2] + dp[i - 1])%mod)%mod)) % mod);
    }
    return dp[h];
}
