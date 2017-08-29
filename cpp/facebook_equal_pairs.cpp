find all equivalent pairs
Given an array A of integers, find the index of values that satisfy A + B =C + D, where A,B,C & D are integers values in the array. Find all combinations of quadruples.

class Solution {
public:
	struct Index{
		vector<pair<int,int>> pairs;
		unordered_set<int> st;
	};
	struct quad {
		int a;
		int b;
		int c;
		int d;
	};
	vector<vector<quad>> findEqualPair(vector<int> nums) {
		vector<vector<quad>> res;
		unordered_map<int, Index> mp;
		for (int i=0; i<nums.size(); i++) {
			for (int j=0; j<i; j++) {
				int sum=nums[i]+nums[j];
				if (mp[sum].st.find(i)==mp[sum].st.end() &&
					mp[sum].st.find(j)==mp[sum].st.end()) {
					mp[sum].pairs.push_back({i,j});
					mp[sum].st.insert(i);
					mp[sum].st.insert(j);
				}

			}
		}

		for (auto iter:mp) {
			auto p=iter.second.pairs;
			if (p.size()>1) {
				vector<quad> v;
				for (int i=0; i<p.size(); i++) {
					for (int j=0; j<i; j++) {
						quad q;
						q.a=p[i].first;
						q.b=p[i].second;
						q.c=p[j].first;
						q.d=p[j].second;
					}
				}
				res.push_back(v);
			}
		}
		return res;
	}
};

