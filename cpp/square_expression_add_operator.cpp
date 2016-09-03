B）给定一个长度为n的int array，要求使用每一个element进行加或者减，答案求得target。
比如<1,2,3,4,5>, target是15，那么答案就是1+2+3+4+5= 15
                          target是5，  答案可能是   1-2-3+4 +5 = 5
                                                     或者    1+2+3+4-5 = 5
要求求出所有可能的答案，且每个element必须用且只能用1次。
在面试的时候我想出了两种方法：
       解法1：只有n个数字，只能是正负，等同于求n个符号permutation，那么总有结果和target match。
       解法2：和maze solver相似，假设我们已经知道前n-1个element的结果，那么我们可以轻松的知道如何使用最后一个element可以得到target或者根本不可能得到target。
                     因此用Recursion写DFS。
       解法3：我大开脑洞想如果先求了整个array的和，用和减去target，得到相差的差值。那么证明1~n个element需要变成负数，0.5*difference = k个element的和，转化为n-sum问题。

我用了解法2，因为担心解法1太暴力。。。结果因为只有40分钟时间所以不知道在什么地方出了bug，过不了testcase。于是被淘汰

class Solution {
public:
	void getExpr(vector<string>& res, string& expr, vector<int>& nums, int target, int start) {
		if (start==nums.size() && target==0) {
			res.push_back(expr);
			return;
		}
		if (start>=nums.size()) return;
		if (expr.empty()) {
			expr+=to_string(nums[start]);
			getExpr(res, expr, nums, target-nums[start], start+1);
			expr.clear();
		} else {
			int pos=expr.size();
			expr+="+"+to_string(nums[start]);
			getExpr(res, expr, nums, target-nums[start], start+1);
			expr.erase(pos);
			expr+="-"+to_string(nums[start]);
			getExpr(res, expr, nums, target+nums[start], start+1);
			expr.erase(pos);
		}
	}
	vector<string> addOperators(vector<int> nums, int target) {
		vector<string> res;
		string expr;
		getExpr(res, expr, nums, target, 0);

		return res;
	}
};

int main(int argc, char** argv) {
	Solution s;
	vector<int> nums={1,2,3,4,5};
	vector<string> res=s.addOperators(nums, 5);
	return 0;
}

