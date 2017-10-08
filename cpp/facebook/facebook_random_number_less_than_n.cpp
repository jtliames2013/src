最后的coding是给一个数组和一个数N， 随机返回该数组中任意一个不大于N的数。

class Solution {
public:
	int getRandom(vector<int> nums, int n) {
		int res;
		int count=0;
		bool first=true;
		for (int i=0; i<nums.size(); i++) {
			if (nums[i]<n) {
				if (first) {
					res=nums[i];
					first=false;
                    count=1;
				} else {
                    count++;
					int j=rand()%count;
					if (j==0) res=nums[i];
				}
			}
		}
		return res;
	}
};

