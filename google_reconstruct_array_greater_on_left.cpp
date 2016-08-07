第一题, 给一个array比如[4,2,1,3,5],根据这个array现在我们能有了一个新的array => 每数是在原array里, 在它左边的所有比它大的number的个数,就是[0,1,2,1,0]. 题目是现在给了这个[0,1,2,1,0]要求原array, 原来array的range是1~n

一群人在排队，然后每个人知道自己前面有多少人比自己高，然后给你每个人的高度，要求reconstruct 这个序列。

class Solution {
public:
	vector<int> reconstruct(vector<pair<int,int>> data) {
		int n=data.size();
		vector<int> res(n, 0);
		vector<bool> visited(n, false);
		auto comp=[](pair<int,int> a, pair<int,int> b) { return a.first>b.first; };
		priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
		for (int i=0; i<n; i++) {
			pq.push(data[i]);
		}

		while (!pq.empty()) {
			pair<int,int> t=pq.top();
			pq.pop();
			int count=0;
			int i;
			for (i=0; i<n; i++) {
				if (visited[i]==false) count++;
				if (count==t.second+1) break;
			}
			res[i]=t.first;
			visited[i]=true;
		}

		return res;
	}
};

int main() {
	Solution s;
	vector<pair<int,int>> data={{4,0},{2,1},{1,2},{3,1},{5,0}};
	vector<int> res=s.reconstruct(data);
	return 0;
}

2.

class Solution {
public:
	vector<int> reconstruct(vector<pair<int,int>> data) {
		int n=data.size();
		vector<int> res;
		auto comp=[](pair<int,int> a, pair<int,int> b) { return a.first<b.first; };
		priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
		for (int i=0; i<n; i++) {
			pq.push(data[i]);
		}

		while (!pq.empty()) {
			pair<int,int> t=pq.top();
			pq.pop();
			res.insert(res.begin()+t.second, t.first);
		}

		return res;
	}
};

int main() {
	Solution s;
	vector<pair<int,int>> data={{4,0},{2,1},{1,2},{3,1},{5,0}};
	vector<int> res=s.reconstruct(data);
	return 0;
}

