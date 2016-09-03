依旧贪心去推，贪心的规则就是在能够到达的范围之内，选择一个能够到达最远距离的点，更新步数，和更新最远到达的范围。

 class Solution {
 public:
     int jump(vector<int>& nums) {
    	 int size=nums.size();
    	 if (size==0) return 0;
    	 int minSteps=0;
    	 int maxRange=0, currRange=0;
    	 for (int i=0; i<size; ) {
    		 if (currRange>=size-1) break;

    		 for (int j=i; j<=currRange; j++) {
    			 maxRange=max(maxRange, nums[j]+j);
    		 }
    		 minSteps++;
    		 i=currRange+1;
    		 currRange=maxRange;
    	 }

    	 return minSteps;
     }
 };

