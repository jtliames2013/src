给一个字符串，如果是相邻字母是一样的话就称为一个桥，把桥之间的字符替换成加号。这个题看似简单，很多corner case，不好写，到最后也没写出一个bug free的版本 

class Solution {
public:
	void bridgeAdjacent(string& str) {
		int n=str.size();
		for (int i=0; i<n; ) {
			if (isalpha(str[i])) {
				int j=i+1;
				int last=-1;
				while (j<n && (!isalpha(str[j]) || str[j]==str[i])) {
					if (str[j]==str[i]) last=j;
					j++;
				}
				if (j<n) {
					if (last!=-1) {
						for (int k=i; k<=last; k++) str[k]='+';
					}
				}
				i=j;
			} else {
				i++;
			}
		}
	}
};

int main()
{
	Solution s;
	string str="--a-d---ddd--d--ad-b";
	s.bridgeAdjacent(str);
	cout << str << endl;
	return 0;
}

