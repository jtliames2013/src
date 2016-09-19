第二轮，老外面试官，给一个String, 如AABACCDCD, 插入'_'使同一个字母间隔为k: 如果k=3: A___AB__AC___CD__CD, 一开始理解有误，认为是要先shuffle字母顺序然后插入'_'，花了不少时间，然后面试官提示字母顺序不变，写出来，然后直接run出来有bug，在coderpad上调了一会才通过

class Solution {
public:
	string insertUnderscore(string s, int interval) {
		string res;
		map<char, int> lastPos;

		for (int i=0; i<s.size(); i++) {
			int index=res.size();
			if (lastPos.find(s[i])!=lastPos.end() && index-lastPos[s[i]]-1<interval) {
				res.append(interval-(index-lastPos[s[i]]-1), '_');
			}
			res.append(1, s[i]);
			lastPos[s[i]]=res.size()-1;
		}

		return res;
	}
};

int main()
{
	Solution s;
	string data="AABACCDCD";
	string res=s.insertUnderscore(data, 3);
	cout << res << endl;
	return 0;
}

