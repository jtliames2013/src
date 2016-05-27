Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]

Follow up:
Could you solve it in O(n2) runtime? 

NOTE: when sum is less than the target, all pair between start and end are less than target.

  class Solution {
  public:
      int threeSumSmaller(vector<int>& nums, int target) {
    	  int res=0;
    	  int size=nums.size();
    	  sort(nums.begin(), nums.end());

    	  for (int i=0; i<size-1; i++) {
    		  int start=i+1;
    		  int end=size-1;

    		  while (start<end) {
    			  if (nums[i]+nums[start]+nums[end]<target) {
    				  res += end-start;
    				  start++;
    			  } else {
    				  end--;
    			  }
    		  }
    	  }

    	  return res;
      }
  };

