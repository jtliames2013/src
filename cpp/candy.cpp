135. Candy  QuestionEditorial Solution  My Submissions
Total Accepted: 56304 Total Submissions: 243377 Difficulty: Hard
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Hide Tags Greedy

解题思路：
贪心算法（Greedy Algorithm）

评分同时低于左右两边的孩子只需分配一个糖果

评分相同的相邻孩子，分配的糖果可以不同

算法步骤如下：

1. 首先为每一个孩子分配1个糖果

记当前孩子序号为i，糖果数为candies[i]，评分为ratings[i]

2. 从左向右遍历，若ratings[i] > ratings[i - 1]，则令candies[i] = candies[i - 1] + 1

3. 从右向左遍历，若ratings[x] > ratings[x + 1]，则令candies[x] = max(candies[x], candies[x + 1] + 1)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if (n==0) return 0;
        int res=0;
        vector<int> candies(n, 1);
        for (int i=1; i<n; i++) {
            if (ratings[i]>ratings[i-1]) candies[i]=candies[i-1]+1;
        }
        for (int i=n-2; i>=0; i--) {
            if (ratings[i]>ratings[i+1]) candies[i]=max(candies[i], candies[i+1]+1);
        }
        
        for (int c:candies) res+=c;
        return res;
    }
};

