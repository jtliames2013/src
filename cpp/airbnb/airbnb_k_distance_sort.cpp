Airbnb: K-distance sort
Sort a list of numbers in which each number is at most distance k from its actual position.
Since each integer being at most n positions away from its final position:

1) for the smallest integer (aka. the 0th integer in the final sorted array), its current position must be in A[0...n] because the nth element is n positions away from the 0th position

2) for the second smallest integer (aka. the 1st integer in the final sorted array, zero based), its current position must be in A[0...n+1]

3) for the ith smallest integer, its current position must be in A[i-n...i+n]

We could use a (n+1)-size min heap, containing a rolling window to get the array sorted. And you could find more details here:

http://www.geeksforgeeks.org/nearly-sorted-algorithm/

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

