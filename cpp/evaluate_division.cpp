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

class Solution {
public:
    struct Node {
        Node* parent;
        double val;
        Node():parent(this),val(1) {}
    };
    void Union(string& s1, string& s2, unordered_map<string, Node*>& table, double val) {
        Node *parent1=Find(table[s1]);
        Node *parent2=Find(table[s2]);
        double ratio=table[s2]->val*val/table[s1]->val;
        if (parent1!=parent2) {
            for (auto iter:table) {
                if (Find(iter.second)==parent1) {
                    iter.second->val*=ratio;
                }
            }
            parent1->parent=parent2;
        }
    }
    Node* Find(Node* n) {
        if (n->parent==n) return n;
        else return Find(n->parent);
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, Node*> table;
        for (int i=0; i<equations.size(); i++) {
            string s1=equations[i].first;
            string s2=equations[i].second;
            auto iter1=table.find(s1);
            auto iter2=table.find(s2);
            if (iter1==table.end() && iter2==table.end()) {
                Node *n1=new Node(), *n2=new Node();
                table[s1]=n1;
                table[s2]=n2;
                table[s1]->parent=table[s2];
                table[s1]->val=values[i];
            } else if (iter1==table.end()) {
                Node *n1=new Node();
                table[s1]=n1;
                table[s1]->parent=table[s2];
                table[s1]->val=table[s2]->val*values[i];
            } else if (iter2==table.end()) {
                Node *n2=new Node();
                table[s2]=n2;
                table[s2]->parent=table[s1];
                table[s2]->val=table[s1]->val/values[i];
            } else {
                Union(s1, s2, table, values[i]);
            }
        }

        vector<double> res;
        for (int i=0; i<queries.size(); i++) {
            if (table.find(queries[i].first)==table.end() ||
                table.find(queries[i].second)==table.end() ||
                Find(table[queries[i].first])!=Find(table[queries[i].second])) {
                    res.push_back(-1);
                } else {
                    res.push_back(table[queries[i].first]->val/table[queries[i].second]->val);
                }
        }
        return res;
    }
};

