首先建议如果第一轮能电面的话最好还是电面，本来想去参观一下office的，但第一轮需要在45分钟内完成2道coding，去掉互相介绍和提问的环节可能就只剩下半小时，白板上要写出2道bug free的code几乎不太可能，除非以前见过。。题目是给定一个list of sorted integer arrays，要求找所有的数的median
e.g. [1,3,6,7,9], [2,4], [5], return 5

class Solution {
public:
	double getMedian(vector<vector<int> > nums) {
		int count=0;
		for (auto n:nums) count+=n.size();
		bool odd=false;
		if (count%2==1) odd=true;
		int m, m1, m2;
		auto comp = [&nums](pair<int, int> a, pair<int, int> b) {
		            return nums[a.first][a.second] > nums[b.first][b.second];};
		priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
		for (int i=0; i<nums.size(); i++) {
			if (nums[i].size()>0) {
				pq.push({i, 0});
			}
		}

		int cnt=0;
		while (!pq.empty()) {
			cnt++;
			pair<int,int> t=pq.top();
			pq.pop();
			if (odd) {
				if (cnt==count/2+1) {
					m=nums[t.first][t.second];
					break;
				}
			} else {
				if (cnt==count/2) {
					m1=nums[t.first][t.second];
				} else if (cnt==count/2+1) {
					m2=nums[t.first][t.second];
					break;
				}
			}

			t.second++;
			if (t.second<nums[t.first].size()) {
				pq.push(t);
			}
		}

		if (odd) return m;
		else return ((double)(m1+m2))/2;
	}
};

int main()
{
	Solution s;
	vector<vector<int> > nums={{1,3,6,7,8,9},{2,4},{5}};
	//vector<vector<int> > nums={{1,3,6,7,9},{2,4},{5}};
	double res=s.getMedian(nums);
	cout << res << endl;
	return 0;
}

