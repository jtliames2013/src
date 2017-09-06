一道题，  输入为一个大小为4的整型数组，每个整数范围1-9。判断能不能通过+，-，*， /, () 五种操作使的操作完结果是二十四。只需判断可不可行 true/false比如，输入是 4，1，8，7 ， 返回真，因为  (8-4)*(7-1) 等于二十四。 这里数组里元素的顺序可以随意变换。又比如，输入是1，1，1，1 返回假，因为不能生成二十四。

class Solution {
public:
	void dfs(vector<vector<int>>& res, vector<int>& output, vector<int>& nums, vector<bool>& selected) {
		if (output.size()==nums.size()) {
			res.push_back(output);
			return;
		}

		for (int i=0; i<nums.size(); i++) {
			if (selected[i]==false && (i==0 || nums[i]!=nums[i-1] || selected[i-1]==true)) {
				selected[i]=true;
				output.push_back(nums[i]);
				dfs(res, output, nums, selected);
				output.pop_back();
				selected[i]=false;
			}
		}
	}

	vector<vector<int>> getPerm(vector<int> nums) {
		vector<vector<int>> res;
		vector<int> output;
		sort(nums.begin(), nums.end());
		vector<bool> selected(nums.size());
		dfs(res, output, nums, selected);
		return res;
	}

	int calc(int l, int r, char op) {
		switch (op) {
		case '+': return l+r;
		case '-': return l-r;
		case '*': return l*r;
		case '/': return r!=0?l/r:0;
		default: return 0;
		}
	}

	unordered_set<int> gen(unordered_map<string, unordered_set<int>>& results, vector<int>& nums, int start, int end) {
		unordered_set<int> res;
		if (start==end) {
			res.insert(nums[start]);
			return;
		}

		string str;
		for (int i=start; i<=end; i++) str+=nums[i]+'0';
		if (results.find(str)!=results.end()) return results[str];

		for (int i=start; i<end; i++) {
			unordered_set<int> left=gen(results, nums, start, i);
			unordered_set<int> right=gen(results, nums, i+1, end);
			for (auto l:left) {
				for (auto r:right) {
					for (int k=0; k<4; k++) {
						if (r==0 && op[k]=='/') continue;
						int n=calc(l, r, op[k]);
						res.insert(n);
					}
				}
			}
		}

		results[str]=res;
	}

	bool calc(unordered_map<string, unordered_set<int>>& results, vector<int> nums) {
		unordered_set<int> res=gen(res, nums, 0, nums.size()-1);
		for (auto i:res) if (i==24) return true;
		return false;
	}

	bool calculate(vector<int> nums) {
		unordered_map<string, unordered_set<int>> results;
		vector<vector<int>> perms=getPerm(nums);
		for (auto& perm:perms) {
			if (calc(results, perm)) return true;
		}
		return false;
	}

private:
	const char op[4]={'+', '-', '*', '/'};
};

