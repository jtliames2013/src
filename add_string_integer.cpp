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
};
