1.给一堆源代码文件, 每个文件有dependency on 其他源代码文件, 就像java里面, 会import其他的源文件. 写个函数检测这堆源代码文件里面有没有circular dependency.

class Solution {
public:
	bool hasCycle(int vertex, map<int, bool>& visited, map<int, bool>& inPath) {
		visited[vertex]=true;
		inPath[vertex]=true;

		for (auto neighbor:graph[vertex]) {
			if (visited[neighbor]==false) {
				if (hasCycle(neighbor, visited, inPath)) return true;
			} else if (inPath[neighbor]==true) {
				return true;
			}
		}

		inPath[vertex]=false;
		return false;
	}

	bool hasCycle(vector<pair<int,int> >& edges) {
		map<int, bool> visited;
		map<int, bool> inPath;
		for (auto e:edges) {
			graph[e.first].insert(e.second);
			visited[e.first]=visited[e.second]=false;
			inPath[e.first]=inPath[e.second]=false;
		}

		for (auto vertex:graph) {
			if (visited[vertex.first]==false) {
				if (hasCycle(vertex.first, visited, inPath)) return true;
			}
		}
		return false;
	}
private:
	map<int, set<int> > graph;
};

int main(int argc, char** argv) {
	Solution s;
	//vector<pair<int,int> > edges={{1,2},{2,3},{3,4},{4,2}};
	//vector<pair<int,int> > edges={{1,2},{2,3},{3,4},{4,5}};
	//vector<pair<int,int> > edges={{1,2},{2,3},{3,1},{4,5}};
	vector<pair<int,int> > edges={{1,2},{2,3},{3,4},{5,6},{6,7},{7,5}};
	bool res=s.hasCycle(edges);
	cout << res << endl;
	return 0;
}

