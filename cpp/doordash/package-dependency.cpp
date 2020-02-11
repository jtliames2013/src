拓扑排序，package dependency 问题， 给定一个package x，需要以怎样的顺序安装 x 需要的dependency libs，需要注意的是，这个问题需要先正向 dfs/bfs 找到dependecy graph 中的 connected component，再reverse graph 用 topological sort 找顺序，这里要注意有环的情况要单独判断

class Installer {
public:
    Installer(int n) {
        numNodes = n;        
        outgoingGraph.resize(numNodes);
        incomingGraph.resize(numNodes);
        incomingCount.resize(numNodes);
    }

    void buildGraph(vector<vector<int>> dependency) {
        // 0 <-- 1, 0 depends on 1, 1 is prerequisite of 0
        for (auto& d:dependency) {
            if (outgoingGraph[d[1]].find(d[0])==outgoingGraph[d[1]].end()) {
                outgoingGraph[d[1]].insert(d[0]);
                incomingCount[d[0]]++;
            }
            incomingGraph[d[0]].insert(d[1]);            
        }
    }

    vector<int> install(int package) {
        vector<int> res;
        vector<bool> visited(numNodes);
        dfs(visited, package);

        unordered_set<int> st;
        for (int i=0; i<numNodes; ++i) {
            if (visited[i] && incomingCount[i]==0) st.insert(i);
        }

        while (!st.empty()) {
            int b=*st.begin();
            st.erase(st.begin());
            res.push_back(b);

            for (auto& neighbor:outgoingGraph[b]) {
                if (visited[neighbor]) {
                    incomingCount[neighbor]--;
                    if (incomingCount[neighbor]==0) st.insert(neighbor);
                }
            }
        }

        for (int i=0; i<numNodes; ++i) {
            if (visited[i] && incomingCount[i]>0) return vector<int>();
        }
        return res;
    }
private:
    void dfs(vector<bool>& visited, int node) {
        visited[node]=true;
        for (auto neighbor:incomingGraph[node]) {
            if (visited[neighbor]==false) {
                dfs(visited, neighbor);
                visited[neighbor]=true;
            }
        }
    }

    vector<unordered_set<int>> outgoingGraph;
    vector<unordered_set<int>> incomingGraph;
    vector<int> incomingCount;
    int numNodes;
};

int main(int argc, char** argv) {
    Installer installer(20);
    //vector<vector<int>> d={{0, 1}, {0, 2}, {1, 3}, {4, 5}, {2, 5}, {4, 6}, {7, 8}};
    vector<vector<int>> d={{0, 1}, {0, 2}, {1, 3}, {4, 5}, {2, 5}, {4, 6}, {7, 8}, {9, 0}, {5, 9}};
    installer.buildGraph(d);
    auto res=installer.install(0);
    for (auto i:res) cout << i << " ";
    cout << endl;
    return 0;
}

