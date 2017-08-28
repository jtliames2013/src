#add operation

class Solution {
public:
	void dfs(vector<string>& res, string& output, string& num, int start) {
		if (start==num.size()) {
			if (!output.empty()) res.push_back(output);
		}
		for (int i=start; i<num.size(); i++) {
			if (i>start && num[start]=='0') break;
			if (output.empty()) {
				output+=num.substr(start, i-start+1);
				dfs(res, output, num, i+1);
				output.clear();
			} else {
				int len=output.size();
				output+="+"+num.substr(start, i-start+1);
				dfs(res, output, num, i+1);
				output.erase(len);
				output+="-"+num.substr(start, i-start+1);
				dfs(res, output, num, i+1);
				output.erase(len);
			}
		}
	}
	vector<string> addOperator(string num) {
		vector<string> res;
		string output;
		dfs(res, output, num, 0);
		return res;
	}
};

