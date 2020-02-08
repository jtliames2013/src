1.给一堆源代码文件, 每个文件有dependency on 其他源代码文件, 就像java里面, 会import其他的源文件. 写个函数检测这堆源代码文件里面有没有circular dependency.

1. DFS
class Solution {
public:
	vector<int> dfs(vector<unordered_set<int>>& graph, vector<int>& visited, vector<int>& parent, int vertex) {
        visited[vertex]=1;

        for (auto neighbor:graph[vertex]) {
            if (visited[neighbor]==1) {
                return getPath(parent, vertex);
            }
            if (visited[neighbor]==0) {
                parent[neighbor]=vertex;
                auto res=dfs(graph, visited, parent, neighbor);
                parent[neighbor]=-1;
                if (!res.empty()) return res;
            }
        }

        visited[vertex]=2;
        return vector<int>();
	}

    vector<int> getPath(vector<int>& parent, int vertex) {
        vector<int> res;
        do {
            res.push_back(vertex);
            vertex=parent[vertex];
        } while (vertex!=-1);

        return res;
    }

    bool hasCycle(int n, vector<pair<int,int> >& edges) {
        vector<int> visited(n); // 0 - white, 1 - grey, 2 - black
        vector<int> parent(n, -1);
        vector<unordered_set<int>> graph(n);				
        for (auto e:edges) {
            graph[e.first].insert(e.second);
        }

        for (int i=0; i<n; ++i) {
            if (visited[i]==0) {
                auto res=dfs(graph, visited, parent, i);
                if (!res.empty()) {
                    print(res);
                    return true;
                }
            }
        }
        return false;
    }

    void print(vector<int>& v) {
        for (int i=0; i<v.size(); ++i) {
            if (i>0) cout << "<-";
            cout << v[i];
        }
        cout << endl;
    }
};

int main(int argc, char** argv) {
    Solution s;
    int n;
    vector<pair<int,int> > edges;
    n=5;
    edges={{1,2},{2,3},{3,4},{4,2}};
    cout << s.hasCycle(n, edges) << endl << endl;

    n=6;
    edges={{1,2},{2,3},{3,4},{4,5}};
    cout << s.hasCycle(n, edges) << endl << endl;

    n=6;
    edges={{1,2},{2,3},{3,1},{4,5}};
    cout << s.hasCycle(n, edges) << endl << endl;

    n=8;
    edges={{1,2},{2,3},{3,4},{5,6},{6,7},{7,5}};
    cout << s.hasCycle(n, edges) << endl << endl;

    n=8;
    edges={{1,2},{3,7},{7,6},{6,5},{5,4}, {4,3}};
    cout << s.hasCycle(n, edges) << endl << endl;

    return 0;
}

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


