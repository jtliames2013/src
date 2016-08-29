A) 给出长度为n的int array和长度为n-1的char array（储存了一堆运算符），求运算结果
答案：loop+switch就行。

class Solution {
public:
	int eval(vector<int> nums, vector<char> ops) {
		int n=nums.size();
		vector<int> res;
		res.push_back(nums[0]);
		for (int i=1; i<n; i++) {
			if (ops[i-1]=='+') res.push_back(nums[i]);
			else if (ops[i-1]=='-') res.push_back(-nums[i]);
			else if (ops[i-1]=='*' || ops[i-1]=='/') {
				int b=res.back();
				res.pop_back();
				res.push_back(ops[i-1]=='*'?b*nums[i]:b/nums[i]);
			}
		}

		int sum=0;
		for (int i=0; i<res.size(); i++) sum+=res[i];
		return sum;
	}
};

int main(int argc, char** argv) {
	Solution s;
	vector<int> nums={1,2,3,4,5};
	vector<char> ops={'*','+','/','-'};
	int res=s.eval(nums, ops);
	cout << res << endl;
	return 0;
}

