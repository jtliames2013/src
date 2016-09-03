 Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.

Hint:

    There is a simple O(n) solution to this problem.
    You may check the breaking results of n ranging from 7 to 10 to discover the regularities.


观察n为7到10的情形寻找规律：

7  -> 3 * 4     -> 12
8  -> 2 * 3 * 3 -> 18
9  -> 3 * 3 * 3 -> 27
10 -> 3 * 3 * 4 -> 36
可以发现得到的拆分结果中，各元素的差值均不超过1。

  class Solution {
  public:
	  int getSplitMultiple(int n, int m) {
		  int divide=n/m;
		  int mod=n%m;
		  return (int)(pow(divide+1, mod)*pow(divide, m-mod));
	  }

      int integerBreak(int n) {
    	  int maxVal=0;
    	  for (int i=2; i<=n; i++) {
    		  maxVal=max(maxVal, getSplitMultiple(n, i));
    	  }
    	  return maxVal;
      }
  };

