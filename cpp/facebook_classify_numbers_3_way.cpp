刚刚面完。。一个女面试官，应该是个美国白人（没有3哥的口音），45分钟先扯了将近10分钟的自我介绍和项目介绍，然后开始做题。
完整题目如下：
Given a input of integers: {10, 555, 100000, 100, 9}

Given a categorizer function: enum cat(int input) = S, M, L

Output: {10, 9, 555, 100, 100000}

example of cat: < 100 S; else < 1000 M; else L

给1个数组，并根据给出的cat function将数组按小中大的范围重新排序后输出（S , M , L）， 不要求相对范围内的顺序。

实际上就是sort color的变种，不过输出要原数组，并且要time O(n), space O(1)。lz上来就开了3个map去存数组直接被pass - -.
最后在面试官交流和提醒下用了类似quick-selected的方法写完（估计一堆bug），完后就木有然后了

第一题是sort 3 colors变形，就是给一堆tasks，有一个API getPriority可以获得每一个task ID的优先级(low, medium, high),
要求对所有task进行排序，使得low tasks在最左边，medium的在中间，high的在最右边。

class Solution {
public:
	void classifyNumbers(vector<int>& nums) {
		int S=100, M=1000;
		if (nums.size()==0) return;
		int start=0, end=nums.size()-1;
		for (int i=0; i<=end; ) {
			if (nums[i]<S) {
				swap(nums[i], nums[start]);
				start++;
				i++;
			} else if (nums[i]>=M) {
				swap(nums[i], nums[end]);
				end--;
			} else {
				i++;
			}
		}
	}
};

int main()
{
	Solution s;
	vector<int> nums={2000, 400, 10, 555, 3000, 100000, 4000, 100, 9, 200, 300, 1001};
	s.classifyNumbers(nums);
	for (int i=0; i<nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}

