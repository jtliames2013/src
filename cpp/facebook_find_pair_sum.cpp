24. You're given an array of integers(eg [3,4,7,1,2,9,8]) Find the index of values that satisfy A+B = C + D, where A,B,C & D are integers values in the array.

Eg: Given [3,4,7,1,2,9,8] array
The following
3+7 = 1+ 9 satisfies A+B=C+D. 
so print (0,2,3,5)

class Solution {
public:
	vector<int> findPairs(vector<int> nums) {
		map<int, pair<int,int> > table;
		for (int i=0; i<nums.size(); i++) {
			for (int j=i+1; j<nums.size(); j++) {
				int sum=nums[i]+nums[j];
				if (table.find(sum)==table.end()) {
					table[sum]={i,j};
				} else {
					return {table[sum].first, table[sum].second, i, j};
				}
			}
		}
		return {-1,-1,-1,-1};
	}
};

int main()
{
	Solution s;
	vector<int> nums={3,4,7,1,2,9,8};
	vector<int> res=s.findPairs(nums);
	for (int i=0; i<res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}

