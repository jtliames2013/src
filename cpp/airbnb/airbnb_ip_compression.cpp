还有一个ip地址压缩的：用这个压缩一个ip地址区间
Classless Inter-Domain Routing (CIDR) Chart
CIDR表达是： ip地址/掩码位数 表示一个区间
比如 0.0.0.8 / 30 就是以0.0.0.8为准，前30位不能变--》0.0.0.(0000 10 00)--0.0.0.(0000 10 11) 
然后给你一个起始ip，和数量。用最少的cidr表示这个区间

class Solution {
public:
	string convertIntToIp(unsigned long ip) {
		string res;
		vector<int> nums;
		for (int i=0; i<4; i++) {
			int val=ip & 0xff;
			nums.insert(nums.begin(), val);
			ip>>=8;
		}
		for (int i=0; i<4; i++) {
			if (i>0) res+=".";
			res+=to_string(nums[i]);
		}
		return res;
	}
	vector<string> convertIpRangeToCidr(string ipStr, int num) {
		vector<string> res;
		unsigned long ipIntStart=0;
		unsigned long ipIntEnd;
		istringstream iss(ipStr);
		for (int i=0; i<4; i++) {
			string val;
			if (!getline(iss, val, '.')) {
				cout << "incorrect format" << endl;
				break;
			}
			if (i>0) ipIntStart<<=8;
			ipIntStart|=stoul(val);
		}
		ipIntEnd=ipIntStart+num-1;

		while (ipIntEnd>=ipIntStart) {
			int start=ipIntStart;
			int prefix=32;
			while ((start & 0x1) == 0) {
				start>>=1;
				prefix--;
			}
			int count=ipIntEnd-ipIntStart+1;
			int high=0;
			while (count>0) {
				high++;
				count>>=1;
			}
			int range=32-high+1;
			if (prefix<range) {
				prefix=range;
			}
			res.push_back(convertIntToIp(ipIntStart)+"/"+to_string(prefix));
			ipIntStart+=(1<<(32-prefix));
		}

		return res;
	}
};

int main() {
	Solution s;
	//string ipStr="1.1.1.111";
	//string ipStr="128.12.34.12";
	string ipStr="128.12.34.0";
	vector<string> res=s.convertIpRangeToCidr(ipStr, 533);
	return 0;
}

