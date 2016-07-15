327. Count of Range Sum  
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Divide and Conquer Binary Search Tree
Hide Similar Problems (H) Count of Smaller Numbers After Self


这题也差不多，需要找满足条件 lower ≤ sum[j] – sum[i – 1] ≤ upper ，也就是lower + sum[i – 1] ≤ sum[j] ≤ upper + sum[i – 1]

我们同样的求出和，然后离散化，接着从右向左扫描，对每个i 查询满足在[ lower + sum[i – 1], upper + sum[i – 1] ]范围内的个数（用线段树或者Fenwick Tree）

typedef long long LL;
struct SegmentTreeNode {
	LL L, R;
	int cnt;
	SegmentTreeNode *left, *right;
	SegmentTreeNode(LL L, LL R) :L(L), R(R), cnt(0), left(NULL), right(NULL) {}
};
 
class SegmentTree {
	SegmentTreeNode * root;
	SegmentTreeNode * buildTree(vector<LL> &nums, int L, int R) {
		if (L > R) return NULL;
		SegmentTreeNode * root = new SegmentTreeNode(nums[L], nums[R]);
		if (L == R) return root;
		int mid = (L + R) >> 1;
		root->left = buildTree(nums, L, mid);
		root->right = buildTree(nums, mid + 1, R);
		return root;
	}
 
	void update(SegmentTreeNode * root, LL val) {
		if (root && root->L <= val &&  val <= root->R) {
			root->cnt++;
			update(root->left, val);
			update(root->right, val);
		}
	}
	int sum(SegmentTreeNode * root, LL L, LL R) {
		if (!root || root->R < L ||  R < root->L ) return 0;
		if (L <= root->L  && root->R <= R) return root->cnt;
		return sum(root->left, L, R) + sum(root->right, L, R);
	}
 
public:
	SegmentTree(vector<LL> &nums, int L, int R) { root = buildTree(nums, L, R); }
 
	int sum(LL L, LL R) {
		return sum(root, L, R);
	}
 
	void update(LL val) {
		update(root, val);
	}
};
 
class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		if (nums.size() == 0) return 0;
		vector<LL> sum_array (nums.size(),0);
		sum_array[0] = nums[0];
		for (int i = 1; i < sum_array.size(); i++) {
			sum_array[i] = nums[i] + sum_array[i - 1];
		}
		LL sum = sum_array[sum_array.size() - 1];
		sort(sum_array.begin(), sum_array.end());
		auto t = unique(sum_array.begin(), sum_array.end());
		SegmentTree tree(sum_array, 0, t - sum_array.begin() - 1);
		int ans = 0;
		for (int i = nums.size() - 1; i >= 0; i--) {
			tree.update(sum);
			sum -= nums[i];
			ans += tree.sum(lower + sum,upper + sum);
		}
		return ans;
	}
};	
