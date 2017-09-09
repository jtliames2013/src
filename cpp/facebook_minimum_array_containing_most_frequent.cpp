给一个数组，返回带有最高频重复数字的最短sub array

class Solution {
public:
	int findMinimumLength(vector<int> nums) {
		unordered_map<int, vector<int>> mp;
		for (int i=0; i<nums.size(); i++) {
			if (mp.find(nums[i])==mp.end()) {
				mp[nums[i]]={1, i, i};
			} else {
				mp[nums[i]][0]++;
				mp[nums[i]][2]=i;
			}
		}
		int minLen=INT_MAX, maxCnt=0;
		for (auto iter:mp) {
			if (iter.second[0]>maxCnt) {
				maxCnt=iter.second[0];
				minLen=iter.second[2]-iter.second[1]+1;
			} else if (iter.second[0]==maxCnt) {
				minLen=min(minLen, iter.second[2]-iter.second[1]+1);
			}
		}
		return minLen;
	}
};

int main()
{
	Solution s;
	vector<int> nums={1, 2, 3, 2, 2, 1, 4, 1};
	int res=s.findMinimumLength(nums);
	cout << res << endl;
	return 0;
}

