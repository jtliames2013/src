 Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 

  class Solution {
  public:
      vector<string> summaryRanges(vector<int>& nums) {
    	  vector<string> res;
    	  if (nums.size()==0) return res;
    	  int start=0, end;

    	  for (int i=1; i<nums.size(); i++) {
    		  if ((long long)nums[i]-(long long)nums[i-1]>1) {
    			  end=i-1;
    			  res.push_back(end==start ? to_string(nums[start]) : to_string(nums[start]) + "->" + to_string(nums[end]));

    			  start=i;
    		  }
    	  }

    	  res.push_back(nums.size()-1==start ? to_string(nums[start]) : to_string(nums[start]) + "->" + to_string(nums[nums.size()-1]));

    	  return res;
      }
  };

