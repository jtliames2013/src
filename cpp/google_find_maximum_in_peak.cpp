第一个问题就是存在这样一个结构的array，先上升再下降。然后找最大值。。直接二分找吧。
然后问最小值

class Solution {
public:
	int getMaximum(vector<int> data) {
		int l=0, r=data.size()-1;
		int mid;
		if (l==r) return data[l];
		else if (l+1==r) {
			if (data[l]>data[r]) return data[l];
			else return data[r];
		}

		while (l<=r) {
			mid=l+(r-l)/2;
			if (data[mid]>data[mid-1] && data[mid]>data[mid+1]) return data[mid];
			else if (data[mid]>data[mid-1] && data[mid+1]>data[mid]) l=mid+1;
			else r=mid-1;
		}
	}
};

// 存在这样一个结构的array，先上升再下降。然后找最大值
int main() {
	Solution s;
	vector<int> data={1, 2, 3, 4, 5, 6, 7, 4, 2, 1};
	int res=s.getMaximum(data);
	cout << res << endl;

	return 0;
}

