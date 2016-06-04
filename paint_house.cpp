 There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

  class Solution {
  public:
	  int minThree(int a, int b, int c) {
		  return (a<b ? (a<c ? a:c) : (b<c ? b:c));
	  }

      int minCost(vector<vector<int>>& costs) {
    	  int size=costs.size();
    	  vector<vector<int> > dp(size+1, vector<int>(3, 0));
    	  for (int i=1; i<=size; i++) {
    		  dp[i][0]=min(dp[i-1][1]+costs[i-1][0], dp[i-1][2]+costs[i-1][0]);
    		  dp[i][1]=min(dp[i-1][0]+costs[i-1][1], dp[i-1][2]+costs[i-1][1]);
    		  dp[i][2]=min(dp[i-1][0]+costs[i-1][2], dp[i-1][1]+costs[i-1][2]);
    	  }

    	  return minThree(dp[size][0], dp[size][1], dp[size][2]);
      }
  };

