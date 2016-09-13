给一个N位数字，让你拿出K个数字，保证得到数字最大，每一位的相对顺序不能变。比如12443，K=3，则结果是123，K=2, 则结果是12. 因为没见过这题，当时没想到贪心法，给了个耐心排序的次优解，要差一些。实际上就是从N位数字中删除N-K个数字，Google删数问题就行了。

算法的原理应该是说从最高位开始，一次向低位搜索，一旦遇到前一位（高位）的数大于当前位，则删去前一位，直到删除k个数，如果到达末尾还没有删除k个，则说明现在这个数已经是从小到大排序了，则从最低位开始删除要求的位数。

class Solution {
public:
	string deleteNumber(string num, int k) {
		int i;
		while (k>0) {
			int len=num.size();
			for (i=0; i<len-1; i++) {
				if (num[i]>num[i+1]) {
					num.erase(num.begin()+i);
					k--;
					break;
				}
			}
			if (i==len-1) break;
		}

		while (!num.empty() && k>0) {
			num.erase(num.size()-1);
			k--;
		}
		return num;
	}
};

int main() {
	Solution s;
	string num="12443";
	string res=s.deleteNumber(num, 2);
	cout << res << endl;
	return 0;
}

