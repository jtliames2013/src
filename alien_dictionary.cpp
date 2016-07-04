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

﻿// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        string res;
        // a --> b
        map<char, set<char>> outgoingGraph;
        // b <-- a
        map<char, set<char>> incomingGraph;
        set<char> noIncoming;

        // build graph
        for (auto w:words) {
            for (auto l:w) {
                outgoingGraph[l];
                incomingGraph[l];
            }
        }
        for (int i=1; i<words.size(); i++) {
            for (int j=0; j<words[i].size(); j++) {
                if (j<words[i-1].size() && words[i-1][j]!=words[i][j]) {
                    if (outgoingGraph[words[i-1][j]].find(words[i][j])==outgoingGraph[words[i-1][j]].end()) {
                        outgoingGraph[words[i-1][j]].insert(words[i][j]);
                        incomingGraph[words[i][j]].insert(words[i-1][j]);
                    }
                    break;
                }
            }
        }

        // topological sort
        for (auto v:outgoingGraph) {
            if (incomingGraph[v.first].empty()) {
                noIncoming.insert(v.first);
            }
        }

        while (!noIncoming.empty()) {
            char letter=*noIncoming.begin();
            res.push_back(letter);
            noIncoming.erase(noIncoming.begin());
            
            for (auto neighbor:outgoingGraph[letter]) {
                incomingGraph[neighbor].erase(letter);
                if (incomingGraph[neighbor].empty()) {
                    noIncoming.insert(neighbor);
                }
            }
            outgoingGraph[letter].clear();
        }

        for (auto v:outgoingGraph) {
            if (!v.second.empty()) return "";
        }

        return res;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
