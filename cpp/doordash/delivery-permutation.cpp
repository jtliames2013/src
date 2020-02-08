# For each delivery, we expect a Dasher to first pickup the order # from a merchant and then drop off the order to a customer.
# However, a Dasher can be batched during the delivery process, # meaning that they could have multiple routes for N = i + 1?
# N = 1 -> [p1, d1]
# N = 2 -> [p1, d1, p2, d2], [p1, p2, d1, d2], [p1, p2, d2, d1], [p2, d2, p1, d1], [p2, p1, d1, d2], [p2, p1, d2, d1]

class Solution {
public:
    vector<vector<string>> getPermutation(int N) {
        vector<vector<string>> res={{"p1", "d1"}};
        for (int i=2; i<=N; ++i) {
            vector<vector<string>> next;
            for (int j=0; j<res.size(); ++j) {
                int n=res[j].size();
                for (int k=0; k<=n; ++k) {
                    vector<string> p=res[j];
                    p.insert(p.begin()+k, "p"+to_string(i));
                    for (int l=k+1; l<=n+1; ++l) {
                        vector<string> d=p;
                        d.insert(d.begin()+l, "d"+to_string(i));
                        next.push_back(d);
                    }
                }
            }
            res=next;
        }
        return res;
    }

    vector<vector<string>> getPermutationGraph(int N) {
        unordered_map<string, unordered_set<string>> graph;
        unordered_map<string, int> incomingCount;
        unordered_set<string> visited;
        for (int i=1; i<=N; ++i) {
            string u="p"+to_string(i);
            string v="d"+to_string(i);
            graph[u].insert(v);
            incomingCount[u]=0;
            incomingCount[v]=1;
        }

        vector<vector<string>> res;
        vector<string> output;
        dfs(res, output, graph, incomingCount, visited, N);
        return res;
    }

    void dfs(vector<vector<string>>& res, vector<string>& output, unordered_map<string, unordered_set<string>>& graph,  unordered_map<string, int>& incomingCount, unordered_set<string>& visited, int n) {
        if (visited.size()==2*n) {
            res.push_back(output);
            return;
        }

        for (int i=1; i<=n; ++i) {
            for (int j=0; j<2; ++j) {
                string str=(j==0?"p":"d")+to_string(i);
                if (visited.find(str)==visited.end() && incomingCount[str]==0) {
                    visited.insert(str);
                    for (auto& neighbor:graph[str]) {
                        incomingCount[neighbor]--;
                    }
                    output.push_back(str);
                    dfs(res, output, graph, incomingCount, visited, n);
                    output.pop_back();
                    for (auto& neighbor:graph[str]) {
                        incomingCount[neighbor]++;
                    }
                    visited.erase(str);
                }
            }
        }
    }

    int getNumOfPermutation(int N) {
        int a=1;
        for (int i=2; i<=N; ++i) {
            // 1+2+3+...+(2*(i-1)+1)
            a=a*(2*i-1)*i;
        }
        return a;
    }

    void print(vector<vector<string>>& res) {
        for (int j=0; j<res.size(); ++j) {
            auto v=res[j];
            if (j>0) cout << ", ";
            cout << "{";
            for (int k=0; k<v.size(); ++k) {
                if (k>0) cout << ", ";
                cout << v[k];
            }
            cout << "}";
        }
        cout << endl << endl;
    }
};

int main(int argc, char** argv) {
    Solution s;
    for (int i=1; i<4; ++i) {
        auto res=s.getPermutation(i);
        s.print(res);
    }

    for (int i=1; i<4; ++i) {
        auto res=s.getPermutationGraph(i);
        s.print(res);
    }

    for (int i=1; i<10; ++i) {
        cout << s.getNumOfPermutation(i) << endl;
    }
    return 0;
}

