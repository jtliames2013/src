269. Alien Dictionary
Hard

1255

243

Add to List

Share
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"
Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"
Example 3:

Input:
[
  "z",
  "x",
  "z"
] 

Output: "" 

Explanation: The order is invalid, so return "".
Note:

You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.

Facebook
|
21

Airbnb
|
15

Amazon
|
8

Microsoft
|
4

Google
|
3

Pinterest
|
2

Uber
|
2

Bloomberg
|
2

Oracle
|
2

Square
|
2

Cohesity
|
2

Twitter
|
LeetCode

Snapchat
|
LeetCode

Pocket Gems
|
LeetCode

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> outgoingGraph;
        unordered_map<char, int> incomingCnt;
        set<char> st;
        string res;
        
        for (auto& w:words) {
            for (auto& l:w) {
                // makes sure to count vertex that does not have edge
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

