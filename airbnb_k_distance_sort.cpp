Airbnb: K-distance sort
Sort a list of numbers in which each number is at a distance k from its actual position.

class Solution {
	  void sort(vector<int> nums, int  k) {
		  int n=nums.size();
		  priority_queue<int, std::vector<int>, std::greater<int>> pq;
		  int i;
		  for (i=0; i<k+1; i++) {
			  pq.push(nums[i]);
		  }

		  int index=0;
		  while (i<n) {
			  nums[index]=pq.top();
			  pq.pop();
			  pq.push(nums[i]);
			  i++;
			  index++;
		  }

		  while (index<n) {
			  nums[index]=pq.top();
			  pq.pop();
			  index++;
		  }
	  }
  };

