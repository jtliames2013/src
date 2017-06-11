164. Maximum Gap  QuestionEditorial Solution  My Submissions
Total Accepted: 37540 Total Submissions: 134540 Difficulty: Hard
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Credits:
Special thanks to @porker2008 for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Sort

class Solution {
public:
    int maximumGap(vector<int>& nums) {
    	 int n=nums.size();
    	 if (n<2) return 0;
    	 int maxGap;

    	 int minVal=nums[0], maxVal=nums[0];
    	 for (int i=1; i<n; i++) {
    		 minVal=min(minVal, nums[i]);
    		 maxVal=max(maxVal, nums[i]);
    	 }

    	 int bucketRange=(maxVal-minVal-1)/(n-1)+1;
    	 int bucketLen=(maxVal-minVal)/bucketRange+1;
    	 vector<int> bucketMin(bucketLen, INT_MAX);
    	 vector<int> bucketMax(bucketLen, 0);
    	 for (int i=0; i<nums.size(); i++) {
    		 int idx=(nums[i]-minVal)/bucketRange;
    		 bucketMin[idx]=min(bucketMin[idx], nums[i]);
    		 bucketMax[idx]=max(bucketMax[idx], nums[i]);
    	 }

    	 maxGap = bucketMax[0]-bucketMin[0];
    	 int prev=0;
    	 for (int i=1; i<bucketLen; i++) {
    		 if (bucketMin[i]<INT_MAX) {
				 maxGap=max(maxGap, bucketMin[i]-bucketMax[prev]);
				 prev=i;
    		 }
    	 }

    	 return maxGap;
    }
};

