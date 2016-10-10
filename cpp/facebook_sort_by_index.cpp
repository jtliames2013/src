Given two integer arrays of same size, “arr[]” and “index[]”, reorder elements in “arr[]” according to given index array. It is not allowed to given array arr’s length.

class Solution {
public:
	void reorder(vector<int>& nums, vector<int>& index) {
		for (int i=0; i<nums.size(); i++) {
			while (i!=index[i]) {
				int tmpVal=nums[index[i]];
				int tmpIdx=index[index[i]];

				nums[index[i]]=nums[i];
				index[index[i]]=index[i];

				nums[i]=tmpVal;
				index[i]=tmpIdx;
			}
		}
	}
 };

int main()
{
	Solution s;
	vector<int> nums={50, 40, 70, 60, 90};
	vector<int> index={1,  0,  3,  2,  4};
	s.reorder(nums, index);
	for (int i=0; i<nums.size(); i++) {
		cout << nums[i] <<  " ";
	}
	cout << endl;
	return 0;
}

