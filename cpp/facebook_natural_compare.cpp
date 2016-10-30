第一题是narutal sort，也就是aaa2应该排在aaa11前。follow up是如果可以存在不同进制的数，怎么处理。比如aaaA1x15, aaa6x13怎么比较，string中的一般字母全是小写的，不同进制里用英文代替的数字都是大写的。

class Solution {
public:
	int compareNumber(string s1, string s2) {
		int n1=s1.size(), n2=s2.size();
		int i1=0, i2=0;
		while (i1<n1 && s1[i1]=='0') i1++;
		while (i2<n2 && s2[i2]=='0') i2++;

		if (n1-i1!=n2-i2) return n1-i1>n2-i2?1:-1;

		for (; i1<n1 && i2<n2; i1++, i2++) {
			if (s1[i1]!=s2[i2]) {
				return s1[i1]<s2[i2]?-1:1;
			}
		}
		return 0;
	}
	int naturalCompare(string s1, string s2) {
		int n1=s1.size(), n2=s2.size();
		int n=min(n1,n2);
		for (int i=0; i<n; i++) {
			if (isalpha(s1[i])&&isalpha(s1[i])) {
				if (s1[i]!=s2[i]) {
					return s1[i]<s2[i]?-1:1;
				}
			} else if (isalpha(s1[i])&&isdigit(s2[i])) {
				return 1;
			} else if (isdigit(s1[i])&&isalpha(s2[i])) {
				return -1;
			} else {
				return compareNumber(s1.substr(i), s2.substr(i));
			}
		}

		return 0;
	}
};

int main()
{
	Solution s;
	string s1="aaa111";
	string s2="aaa900";
	int res=s.naturalCompare(s1, s2);
	cout << res << endl;
	return 0;
}

