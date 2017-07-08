class Solution {
public:
	int dfs(string str, unordered_set<string>& st, unordered_map<string,int>& mp) {
		int len=1;
		if (mp.find(str)==mp.end()) {
			for (int i=0; i<str.size(); i++) {
				string next=str;
				next.erase(i,1);
				if (st.find(next)!=st.end()) {
					len=max(len, dfs(next, st, mp)+1);
				}
			}
			mp[str]=len;
			return len;
		} else {
			return mp[str];
		}
	}

	int longestChain(vector<string>& strs) {
		unordered_set<string> st;
		for (auto& s:strs) st.insert(s);
		unordered_map<string,int> mp;
		int maxLen=INT_MIN;

		for (int i=0; i<strs.size(); i++) {
			int len=dfs(strs[i], st, mp);
			maxLen=max(len, maxLen);
		}
		return maxLen;
	}
};

