 Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

    Return true if there exists i, j, k
    such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false. 

Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false. 

维护变量a, b，用来记录数组中大小递增的前2个元素。

更确切的说：a是当前的最小元素；b是位于a之后，大于a并且距离a最近的元素。

初始令a = b = None

遍历数组nums，记当前元素为n

  若a为空或者a >= n，则令a = n；

  否则，若b为空或者b >= n，则令b = n；

  否则，返回true

遍历结束时，返回false。

  class Solution {
  public:
      bool increasingTriplet(vector<int>& nums) {
    	  bool min1Found=false, min2Found=false;
    	  int min1, min2;

    	  for (int i=0; i<nums.size(); i++) {
    		  if (min1Found==false) {
    			  min1=nums[i];
    			  min1Found=true;
    		  } else if (nums[i]<=min1) {
    			  min1=nums[i];
    		  } else if (min2Found==false) {
    			  min2=nums[i];
    			  min2Found=true;
    		  } else if (nums[i]<=min2) {
    			  min2=nums[i];
    		  } else {
    			  return true;
    		  }
    	  }

    	  return false;
      }
  };

