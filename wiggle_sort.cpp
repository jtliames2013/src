 Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4]. 

根据题目的定义，摇摆排序的方法将会很多种。我们可以先将数组排序，这时候从第3个元素开始，将第3个元素和第2个元素交换。然后再从第5个元素开始，将第5个元素和第4个元素交换，以此类推。就能满足题目要求。

  class Solution {
  public:
      void wiggleSort(vector<int>& nums) {
    	  sort(nums.begin(), nums.end());

    	  for (int i=2; i<nums.size(); i+=2) {
    		  int tmp=nums[i];
    		  nums[i]=nums[i-1];
    		  nums[i-1]=tmp;
    	  }
      }
  };

题目对摇摆排序的定义有两部分：

如果i是奇数，nums[i] >= nums[i - 1]
如果i是偶数，nums[i] <= nums[i - 1]
所以我们只要遍历一遍数组，把不符合的情况交换一下就行了。具体来说，如果nums[i] > nums[i - 1]， 则交换以后肯定有nums[i] <= nums[i - 1]。


  class Solution {
  public:
      void wiggleSort(vector<int>& nums) {
    	  for (int i=1; i<nums.size(); i++) {
    		  if ((i%2==1 && nums[i]<nums[i-1]) ||
    			  (i%2==0 && nums[i]>nums[i-1])) {
    			  int tmp=nums[i];
    			  nums[i]=nums[i-1];
    			  nums[i-1]=tmp;
    		  }
    	  }
      }
  };


