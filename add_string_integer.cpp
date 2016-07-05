class Solution {
	string add(string num1, string num2) {
		string res;
		bool carry=false;
		int size1=num1.size();
		int size2=num2.size();
		int i=size1-1, j=size2-1;
		int num;
		while (i>=0||j>=0) {
			if (i>=0&&j>=0) {
				num=num1[i]-'0'+num2[j]-'0';
				i--; 
				j--;
			} else if (i>=0) {
				num=num1[i]-'0';
				i--;
			} else if (j>=0) {
				num=num2[j]-'0';
				j--;
			}

			if (carry) { num++; carry=false; }
			if (num>9) { num%=10; carry=true; }
			res.insert(res.begin(), num+'0');
		}

		if (carry) {
			res.insert(res.begin(), '1');
		}

		return res;		
	}

	// 1 if num1 is greater, -1 if num1 is less, 0 if equal
	int compare(string num1, string num2) {
		int size1=num1.size();
		int size2=num2.size();
		if (size1>size2) return 1;
		else if (size1<size2) return -1;
		else {
			for (int i=0; i<size1; i++) {
				if (num1[i]>num2[i]) return 1;
				else if (num1[i]<num2[i]) return -1;
			}
		}
		return 0;
	}
	string substract(string num1, string num2) {
		string res;
		int size1=num1.size();
		int size2=num2.size();
		bool borrow=false;
		int num;

		string str1, str2;
		int comp=compare(num1, num2);
		if (comp>0) {
			str1=num1;
			str2=num2;
		} else if (comp<0) {
			str1=num2;
			str2=num1;
		} else {
			return "0";
		}

		int i=str1.size()-1, j=str2.size()-1;
		while (i>=0||j>=0) {
			if (i>=0&&j>=0) {
				num=str1[i]-'0'-(str2[j]-'0');
				i--;
				j--;
			} else if (i>=0) {
				num=str1[i]-'0';
				i--;
			} else if (j>=0) {
				num=-(str2[j]-'0');
				j--;
			}

			if (borrow) {
				num--;
				borrow=false;
			}
			if (num<0) {
				num+=10;
				borrow=true;
			}

			res.insert(res.begin(), num+'0');
		}

		while (res.size()>1 && *res.begin()=='0') res.erase(res.begin());
		return res;
	}
};
