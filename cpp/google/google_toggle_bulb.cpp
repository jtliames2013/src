第三轮：对N个小灯泡，实现两个method：1.isOn(int i)：判断第i个灯泡ON/OFF， 2.toggle(int start, int end)：turn on/off 从第start开始到end结束的灯泡

class Solution {
public:
	Solution(int size) {
		n=size;
		nums.resize(n);
		tree.resize(n+1);
	}

	void update(int i, int val) {
		int diff=val-nums[i];
		nums[i]=val;
		i++;
		while (i<=n) {
			tree[i]+=diff;
			i+=(i&-i);
		}
	}

	int read(int i) {
		int sum=0;
		while (i>0) {
			sum+=tree[i];
			i-=(i&-i);
		}
		return sum;
	}

	bool isOn(int i) {
		return read(i+1)%2==1;
	}

	void toggle(int start, int end) {
		update(start, nums[start]+1);
		if (end<n) {
			update(end+1, nums[end+1]-1);
		}
 	}

private:
	vector<int> tree;
	vector<int> nums;
	int n;
};


int main()
{
	Solution s(10);
	s.toggle(2, 8);
	s.toggle(3, 5);
	cout << s.isOn(4) << endl;
	cout << s.isOn(6) << endl;
	return 0;
}

