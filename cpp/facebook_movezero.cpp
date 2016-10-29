Move non-zeros to the left side in array, return the count of non-zero integers, don't care about the rest of the array which are not used, require minimum number of writes. Order of integers does not matter.

e.g.[1,0,2,0,4,0,5,7] -> [1,7,2,5,4,x,x,x] and return 5. # writes is 2

class Solution {
public:
	int movezero(vector<int>& nums) {
		int n=nums.size();
		int l=0, r=n-1;
		while (l<=r) {
			if (nums[r]==0) r--;
			else if (nums[l]!=0) l++;
			else {
				swap(nums[l], nums[r]);
				l++;
				r--;
			}
		}
		return r+1;
	}
};

int main()
{
	//vector<int> nums={1,0,2,0,4,0,5,7};
	//vector<int> nums={0};
	vector<int> nums={1};
	Solution s;
	int res=s.movezero(nums);
	cout << res << endl;
	for (int i=0; i<nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}

