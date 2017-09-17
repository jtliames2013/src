亚裔小哥的一道JumpingNumbe的题，JumpingNumber定义是每个digit跟相邻digit的差只能是1. 
输入是n，输出是小于等于n的所有jumping number

class Solution {
public:
	void getNum(vector<int>& res, int target, int num) {
		if (num>target) return;
		res.push_back(num);

		int d=num%10;
		if (d>0) getNum(res, target, num*10+d-1);
		if (d<9) getNum(res, target, num*10+d+1);
	}
	vector<int> jumpingNumbers(int target) {
		vector<int> res;
		if (target<0) return res;
		res.push_back(0);
		for (int i=1; i<=9; i++) {
			getNum(res, target, i);
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> res=s.jumpingNumbers(40);
	for (auto i:res) cout << i << endl;
	return 0;
}

