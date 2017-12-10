1.给一堆源代码文件, 每个文件有dependency on 其他源代码文件, 就像java里面, 会import其他的源文件. 写个函数检测这堆源代码文件里面有没有circular dependency.

1. DFS
class Solution {
public:
	bool hasCycle(int vertex, map<int, unordered_set<int> >& graph, unordered_set<int>& visited, unordered_set<int>& inPath) {
		visited.insert(vertex);
		inPath.insert(vertex);

		for (auto neighbor:graph[vertex]) {
			if (visited.find(neighbor)==visited.end()) {
				if (hasCycle(neighbor, graph, visited, inPath)) return true;
			} else if (inPath.find(neighbor)!=inPath.end()) {
				return true;
			}
		}

		inPath.erase(vertex);
		return false;
	}

	bool hasCycle(vector<pair<int,int> >& edges) {
		map<int, unordered_set<int> > graph;
		unordered_set<int> visited;
		unordered_set<int> inPath;
		for (auto e:edges) {
			graph[e.first].insert(e.second);
		}

		for (auto iter:graph) {
			if (visited.find(iter.first)==visited.end()) {
				if (hasCycle(iter.first, graph, visited, inPath)) return true;
			}
		}
		return false;
	}
};

2. Topological sort
class Solution {
public:
	bool hasCycle(vector<pair<int,int> >& edges) {
		unordered_map<int, unordered_set<int> > graph;
		unordered_map<int,int> incomingCnt;
		for (auto e:edges) {
			incomingCnt[e.first];
			if (graph[e.first].find(e.second)==graph[e.first].end()) {
				graph[e.first].insert(e.second);
				incomingCnt[e.second]++;
			}
		}
		unordered_set<int> st;
		for (auto iter:incomingCnt) {
			if (iter.second==0) st.insert(iter.first);
		}

		while (!st.empty()) {
			int v=*st.begin();
			st.erase(st.begin());

			for (auto neighbor:graph[v]) {
				incomingCnt[neighbor]--;
				if (incomingCnt[neighbor]==0) st.insert(neighbor);
			}
		}

		for (auto iter:incomingCnt) {
			if (iter.second>0) return true;
		}
		return false;
	}
};


int main(int argc, char** argv) {
	Solution s;
	vector<pair<int,int> > edges={{1,2},{2,3},{3,4},{4,2}};
	cout << s.hasCycle(edges) << endl;

	vector<pair<int,int> > edges2={{1,2},{2,3},{3,4},{4,5}};
	cout << s.hasCycle(edges2) << endl;

	vector<pair<int,int> > edges3={{1,2},{2,3},{3,1},{4,5}};
	cout << s.hasCycle(edges3) << endl;

	vector<pair<int,int> > edges4={{1,2},{2,3},{3,4},{5,6},{6,7},{7,5}};
	cout << s.hasCycle(edges4) << endl;

	return 0;
}

