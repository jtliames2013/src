1. detect an array is monotonic or not. 
1,2,3,4 -> T
1,1,1,4 -> T
4,3,2,1 -> T
1，1 ->T

class Solution {
public:
	bool isMonotonic(vector<int> nums) {
		bool inc=false, dec=false;
		for (int i=1; i<nums.size(); i++) {
			if (nums[i]>nums[i-1]) inc=true;
			if (nums[i]<nums[i-1]) dec=true;
			if (inc && dec) return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	vector<int> n1={1, 1, 3, 4};
	cout << s.isMonotonic(n1) << endl;
	vector<int> n2={1, 2, 1, 4};
	cout << s.isMonotonic(n2) << endl;
	vector<int> n3={1, 1, 1, 1};
	cout << s.isMonotonic(n3) << endl;
	vector<int> n4={1, 2, 2, 2};
	cout << s.isMonotonic(n4) << endl;
	vector<int> n5={4, 3, 3, 2};
	cout << s.isMonotonic(n5) << endl;
	vector<int> n6={4, 3, 2, 3};
	cout << s.isMonotonic(n6) << endl;

	return 0;
}

