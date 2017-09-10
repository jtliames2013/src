给一个二叉树的先序遍历结果，返回中序遍历结果

class Solution {
public:
	vector<int> toInorder(vector<int> preorder) {
		int n=preorder.size();
		if (n==0) return vector<int>();
		vector<int> res;
		stack<int> stk;
		for (int i=0; i<n; i++) {
			while (!stk.empty() && stk.top()<preorder[i]) {
				res.push_back(stk.top());
				stk.pop();
			}
			stk.push(preorder[i]);
		}

		while (!stk.empty()) {
			res.push_back(stk.top());
			stk.pop();
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> nums={4, 2, 1, 3, 6, 5, 7};
	vector<int> res=s.toInorder(nums);
	for (auto v:res) cout << v << " ";
	cout << endl;
	return 0;
}

