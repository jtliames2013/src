和Search in Rotated Sorted Array II这题换汤不换药。同样当A[mid] = A[end]时，无法判断min究竟在左边还是右边。

3 1 2 3 3 3 3 
3 3 3 3 1 2 3

但可以肯定的是可以排除A[end]：因为即使min = A[end]，由于A[end] = A[mid]，排除A[end]并没有让min丢失。所以增加的条件是：

A[mid] = A[end]：搜索A[start : end-1]

 class Solution {
 public:
     int findMin(vector<int>& nums) {
    	 int l=0;
    	 int r=nums.size()-1;
    	 int mid;

    	 while (l<=r) {
    		 mid=(l+r)/2;
    		 if (nums[mid]<nums[r]) {
    			 r=mid;
    		 } else if (nums[mid]>nums[r]) {
    			 l=mid+1;
    		 } else {
    			 r--;
    		 }
    	 }
    	 return nums[l];
     }
 };

