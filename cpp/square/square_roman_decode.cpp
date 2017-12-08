input：String .
output: 加密，转换成罗马文
比如输入是"cat"
输出是"IIIIXX"
给了一个数组，元素是1到26的罗马数字.

follow up是解密
比如输入是"IIII"
输出可以是"aaaa", 也可以是别的，valid就行

class Solution {
public:
	string getRoman(char ch) {
		int num=ch-'a'+1;
		string res;
		char symbol[3]={'X', 'V', 'I'};
		int scale=10;

		for (int i=0; i<3; i+=2) {
			int digit=num/scale;
			if (digit>0) {
				if (digit<=3) {
					res.append(digit, symbol[i]);
				} else if (digit==4) {
					res.append(1, symbol[i]);
					res.append(1, symbol[i-1]);
				} else if (digit==5) {
					res.append(1, symbol[i-1]);
				} else if (digit<=8) {
					res.append(1, symbol[i-1]);
					res.append(digit-5, symbol[i]);
				} else if (digit==9) {
					res.append(1, symbol[i]);
					res.append(1, symbol[i-2]);
				}
			}
			num%=scale;
			scale/=10;
		}
		return res;
	}
	string encodeRoman(string str) {
		string res;
		for (int i=0; i<str.size(); i++) {
			res+=getRoman(str[i]);
		}

		return res;
	}

	int getNum(string roman) {
		int res=0;
		bool hasI=false;
		bool hasV=false;
		int iCnt=0;
		for (int i=0; i<roman.size();) {
			if (roman[i]=='X') {
				if (hasI||hasV) return 0;
				res+=10;
				i++;
			} else if (roman[i]=='V') {
				if (hasI) return 0;
				res+=5;
				i++;
				hasV=true;
			} else if (roman[i]=='I') {
				if (i+1<roman.size() && roman[i+1]=='V') {
					if (hasI) return 0;
					res+=4;
					i+=2;
				} else if (i+1<roman.size() && roman[i+1]=='X') {
					if (hasI||hasV) return 0;
					res+=9;
					i+=2;
				} else {
					if (iCnt==3) return 0;
					res+=1;
					i++;
					iCnt++;
				}

				hasI=true;
			} else {
				return 0;
			}
		}
		return res;
	}

	void decode(vector<string>& res, string& num, string& roman, int start) {
		if (start==roman.size()) {
			res.push_back(num);
			return;
		}

		for (int i=start; i<roman.size() && i<start+4; i++) {
			int n=getNum(roman.substr(start, i-start+1));
			if (n<=26 && n>0) {
				num.push_back('a'+n-1);
				decode(res, num, roman, i+1);
				num.erase(num.size()-1);
			}
		}
	}

	vector<string> decode(string roman) {
		vector<string> res;
		string num;
		decode(res, num, roman, 0);
		return res;
	}
};

int main() {
	Solution s;
	string res=s.encodeRoman("cat");
	cout << res << endl;
	vector<string> nums=s.decode("IIIIXX");
	for (int i=0; i<nums.size(); i++) cout << nums[i] << endl;
	return 0;
}

