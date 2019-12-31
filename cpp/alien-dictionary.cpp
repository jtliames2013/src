269. Alien Dictionary
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, wherewords are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
For example,
Given the following words in dictionary,
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".
Note:
1. You may assume all letters are in lowercase.
2. If the order is invalid, return an empty string.
3. There may be multiple valid order of letters, return any one of them is fine.
Hide Company Tags
 Google Airbnb Facebook Twitter Snapchat Pocket Gems
Hide Tags
 Graph Topological Sort
Hide Similar Problems
 (M) Course Schedule II

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> outgoingGraph;
        unordered_map<char, int> incomingCnt;
        set<char> st;
        string res;
        
        for (auto& w:words) {
            for (auto& l:w) {
                outgoingGraph[l];
                incomingCnt[l];
            }
        }
        
        for (int i=1; i<words.size(); i++) {
            for (int j=0; j<words[i].size() && j<words[i-1].size(); j++) {
                if (words[i][j]!=words[i-1][j]) {
                    if (outgoingGraph[words[i-1][j]].find(words[i][j])==outgoingGraph[words[i-1][j]].end()) {
                        outgoingGraph[words[i-1][j]].insert(words[i][j]);
                        incomingCnt[words[i][j]]++;
                    }
                    break;
                }
            }
        }
        
        for (auto& iter:incomingCnt) {
            if (iter.second==0) st.insert(iter.first);
        }
        
        while (!st.empty()) {
            char b=*st.begin();
            res.push_back(b);
            st.erase(st.begin());
            
            for (auto neighbor:outgoingGraph[b]) {
                incomingCnt[neighbor]--;
                if (incomingCnt[neighbor]==0) st.insert(neighbor);
            }
        }
        
        for (auto& iter:incomingCnt) {
            if (iter.second>0) return "";
        }
        
        return res;
    }
};

