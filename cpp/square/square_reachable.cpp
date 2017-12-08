1. 给一组转移比如[1:2, 2:3, 3:4] 表示前面那个元素可以转移到后面那个元素里, 然后给你一组list[1,2,3,4,5], 让你求能不能从某个元素到达另一个元素.
    follow up是存不存在一个环之类的,记得不太清楚了,反正就是图和DFS().  一共俩个follow up, 因为时间问题, 我最后一个followup只是写了代码,没有验证, 最后面试官也让我过了.

class Solution {
public:
	bool canReach(vector<pair<int,int> >& edges, int begin, int end) {
		map<int, set<int> > graph;
		for (auto e:edges) {
			graph[e.first].insert(e.second);
		}
		stack<int> stk;
		set<int> visited;
		visited.insert(begin);
		stk.push(begin);

		while (!stk.empty()) {
			int t=stk.top();
			stk.pop();
			if (t==end) return true;

			for (auto neighbor:graph[t]) {
				if (visited.find(neighbor)==visited.end()) {
					stk.push(neighbor);
					visited.insert(neighbor);
				}
			}
		}

		return false;
	}
};

int main() {
	Solution s;
	//vector<pair<int,int> > edges={{1,2},{2,3},{3,4},{4,5}};
	vector<pair<int,int> > edges={{1,2},{2,3},{4,3},{5,1}};
	bool res=s.canReach(edges, 1, 5);
	cout << res << endl;
	return 0;
}

