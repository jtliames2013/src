class Solution {
public:
	int plusOne(int num) {
		int i=0;
		while (i<32) {
			if ((num & (1<<i))==0) {
				num|=1<<i;
				return num;
			} else {
				num &= ~(1<<i);
			}
			i++;
		}
		return num;
	}
 };

int main()
{
	Solution s;
	for (int i=-1; i<20; i++) {
		cout << s.plusOne(i) << endl;
	}
	return 0;
}

