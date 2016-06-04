Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,

add(1); add(3); add(5);
find(4) -> true
find(7) -> false


  class TwoSum {
  public:
	  unordered_map<int, int> nums;

      // Add the number to an internal data structure.
  	void add(int number) {
  		nums[number]++;
  	}

      // Find if there exists any pair of numbers which sum is equal to the value.
  	bool find(int value) {
  		for (auto n:nums) {
  			int m=value-n.first;
  			if ((m==n.first && nums[m]>1) || (m!=n.first && nums.count(m)>0)) return true;
  		}

  		return false;
  	}
  };


  // Your TwoSum object will be instantiated and called as such:
  // TwoSum twoSum;
  // twoSum.add(number);
  // twoSum.find(value);

