给一组数 [4,6,7,8,9,10], 然后给一个range 比如是 [1,5], 求出这个数组中所有的在这个range中的数.
这题和 leetcode里 search range 很类似. 主要是 binary search.
follow up 是如果数组中存在重复的数怎么处理, 反正search range的解法可以handle这个.
这一轮面试面试官迟到了10分钟,然后聊的也比较开心和谐. 很快就写完了,算上面试官迟到的10分钟一共就30分钟, 面试官就说他OK了, 然后问他问题. 

电面，类似于range search，实现两个接口，add 添加value，search(lower, upper)，找到所有在这个区间内的元素，并且按照顺序返回一个list

1. Use array
class Solution {
public:
	void add(int val) {
		size_t l=0, r=nums.size(), mid;
		while (l<r) {
			mid=l+(r-l)/2;
			if (nums[mid]<val) l=mid+1;
			else r=mid;
		}
		nums.insert(nums.begin()+r, val);
	}

	vector<int> search(int lower, int upper) {
		size_t l=0, r=nums.size(), mid;
		while (l<r) {
			mid=l+(r-l)/2;
			if (nums[mid]<lower) l=mid+1;
			else r=mid;
		}
		int start=r;
		l=r; r=nums.size();
		while (l<r) {
			mid=l+(r-l)/2;
			if (nums[mid]<=upper) l=mid+1;
			else r=mid;
		}
		int end=r;

		return vector<int>(nums.begin()+start, nums.begin()+end);
	}
private:
	vector<int> nums;
};

2. Use multiset
class Solution {
public:
	void add(int val) {
		data.insert(val);
	}

	vector<int> search(int lower, int upper) {
		auto left=lower_bound(data.begin(), data.end(), lower);
		if (left==data.end()) return vector<int> ();
		auto right=upper_bound(data.begin(), data.end(), upper);

		return vector<int>(left, right);
	}
private:
	multiset<int> data;
};


int main() {
	Solution s;
	for (int i=0; i<10; i++) {
		s.add(i);
		s.add(i);
	}

	vector<int> res=s.search(3, 8);
	for (auto i:res) cout << i << " ";
	cout << endl;

	vector<int> res2=s.search(20, 30);
	for (auto i:res2) cout << i << " ";
	cout << endl;

	vector<int> res3=s.search(3, 20);
	for (auto i:res3) cout << i << " ";
	cout << endl;

	vector<int> res4=s.search(-10, -1);
	for (auto i:res4) cout << i << " ";
	cout << endl;

	return 0;
}

