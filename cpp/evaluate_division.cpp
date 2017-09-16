399. Evaluate Division   QuestionEditorial Solution  My Submissions
Total Accepted: 5823 Total Submissions: 15270 Difficulty: Medium Contributors: Admin
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

Subscribe to see which companies asked this question

Hide Tags Graph

1. DFS
class Solution {
public:
    double dfs(unordered_map<string, unordered_map<string,double>>& graph, set<string>& visited, string start, string end) {
        if (graph[start].find(end)!=graph[start].end()) return graph[start][end];
        visited.insert(start);
        for (auto& neighbor:graph[start]) {
            if (visited.find(neighbor.first)==visited.end()) {                
                double res=dfs(graph, visited, neighbor.first, end);                
                if (res!=-1) return res*neighbor.second;
            }
        }
        return -1;
    }
    
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res;
        unordered_map<string, unordered_map<string,double>> graph;
        for (int i=0; i<equations.size(); i++) {
            graph[equations[i].second][equations[i].second]=1;
            graph[equations[i].first][equations[i].second]=values[i];
            if (values[i]!=0) {
                graph[equations[i].first][equations[i].first]=1;
                graph[equations[i].second][equations[i].first]=1/values[i];
            }
        }
        
        for (auto& q:queries) {
            set<string> visited;            
            res.push_back(dfs(graph, visited, q.first, q.second));
        }
        
        return res;
    }
};

2. Union-Find
class Solution {
public:
    struct Node {
        Node* parent;
        double val;
        Node():parent(this), val(1) {}
    };
    
    void Union(string& s1, string& s2, unordered_map<string, Node*>& mp, double val) {
        Node *p1=Find(mp[s1]);
        Node *p2=Find(mp[s2]);
        double ratio=mp[s2]->val*val/mp[s1]->val;
        if (p1!=p2) {
            for (auto iter:mp) {
                if (Find(iter.second)==p1) iter.second->val*=ratio;
            }
            p1->parent=p2;
        }
    }
    
    Node* Find(Node *n) {
        if (n->parent==n) return n;
        return Find(n->parent);
    }
    
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res;
        unordered_map<string, Node*> mp;
        for (int i=0; i<equations.size(); i++) {
            string s1=equations[i].first;
            string s2=equations[i].second;
            auto iter1=mp.find(s1);
            auto iter2=mp.find(s2);
            // a/b == 2, a->val=2, b->val=1, a->parent=b
            if (iter1==mp.end() && iter2==mp.end()) {
                Node *n1=new Node(), *n2=new Node();
                n1->parent=n2;
                n1->val=values[i];
                mp[s1]=n1;
                mp[s2]=n2;
            } else if (iter1==mp.end()) {
                Node *n1=new Node();
                n1->parent=iter2->second;
                n1->val=iter2->second->val*values[i];
                mp[s1]=n1;
            } else if (iter2==mp.end()) {
                Node *n2=new Node();
                n2->parent=iter1->second;
                n2->val=iter1->second->val/values[i];
                mp[s2]=n2;
            } else {
                Union(s1, s2, mp, values[i]);
            }
        }
        
        for (auto q:queries) {
            if (mp.find(q.first)==mp.end() || mp.find(q.second)==mp.end() ||
                Find(mp[q.first])!=Find(mp[q.second])) {
                    res.push_back(-1);
                } else {
                    res.push_back(mp[q.first]->val/mp[q.second]->val);
                }
        }
        return res;
    }
};

