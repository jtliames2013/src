valid IP in string format and return the uint32 format，注意corner case

class Solution {
public:
	bool validIpAddress(string IP, unsigned int& addr) {
		istringstream iss(IP);
		string val;
		int parts=0;
		while (getline(iss, val, '.')) {
			parts++;
			if (parts>4 || val.empty() || val.size()>3) return false;
			int num=0;
			for (int i=0; i<val.size(); i++) {
				num=num*10+val[i]-'0';
			}
			if (num>255 || (val.size()>1 && val[0]=='0')) return false;
			addr<<=8;
			addr|=num;
		}

		return parts==4;
	}
};

