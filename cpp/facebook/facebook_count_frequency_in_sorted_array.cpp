给定一个数组, 已经sort好, 里面有大量重复的数, 输出每个数和这个数出现的次数. 先说扫一遍, 用hashmap计数, 问time complexity说是O(n), 不够好, 怎么快点儿, 答binary search. 这个题没写完, 什么时候更新left什么时候更新right挺复杂, 一个while loop好像很难搞定的样子.
//   input [1 (X200), 2(X50), 3(X10)] 200个1, 50个2, 10个3
//   count the occurrence of the elements.1point3acres缃�
//   output {
//     1: 200, 
//     2: 50,
//     3: 10,
//   }

class Solution {
public:
	vector<pair<int,int>> countFrequency(vector<int> nums) {
		int n=nums.size();
		if (n==0) return vector<pair<int,int>>();
		vector<pair<int,int>> res;
		for (int i=0; i<n; ) {
			int val=nums[i];
			int l=i, r=n-1, mid;
			while (l<r) {
				mid=l+(r-l)/2+1;
				if (nums[mid]>val) r=mid-1;
				else l=mid;
			}
			res.push_back({nums[i], l-i+1});
			i=l+1;
		}

		return res;
	}
};

int main()
{
	Solution s;
	vector<int> nums={1,1,1,2,3,3,3,3,4,4,5};
	vector<pair<int,int>> res=s.countFrequency(nums);
	for (auto v:res) {
		cout << v.first <<  " " << v.second << endl;
	}

	return 0;
}

