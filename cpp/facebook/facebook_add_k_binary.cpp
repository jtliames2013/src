class Solution {
public:
	string addKBinary(vector<string> nums) {
		int k=nums.size();
		int i=0;
		int sum=0;
		string res;
		while (1) {
			bool done=true;
			for (int j=0; j<k; j++) {
				if (nums[j].size()-1-i>=0) {
					done=false;
					sum+=nums[j][nums[j].size()-1-i]-'0';
				}
			}
			if (done) break;
			res.push_back(sum%2+'0');
			sum/=2;
			i++;
		}

		while (sum!=0) {
			res.push_back(sum%2+'0');
			sum/2;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

