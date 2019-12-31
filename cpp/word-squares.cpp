425. Word Squares
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y
Note:
There are at least 1 and at most 1000 words.
All words will have the exact same length.
Word length is at least 1 and at most 5.
Each word contains only lowercase English alphabet a-z.
Example 1:

Input:
["area","lead","wall","lady","ball"]

Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
Example 2:

Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).

Oracle
|
4

Google
|
2

1. Trie
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<string> prefixes;
    TrieNode() {}
};

class Trie {
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* n=root;
        for (int i=0; i<word.size(); ++i) {
            if (n->children.find(word[i])==n->children.end()) {
                n->children[word[i]]=new TrieNode();
            }
            n->prefixes.push_back(word);
            n=n->children[word[i]];
        }
    }

    vector<string> findPrefix(string prefix) {
        TrieNode* n=root;
        for (int i=0; i<prefix.size(); ++i) {
            if (n->children.find(prefix[i])==n->children.end()) return vector<string>();
            n=n->children[prefix[i]];
        }
        return n->prefixes;
    }
    
private:
    TrieNode* root;
};

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;
        vector<string> output;
        int len=words[0].size();
        Trie trie;
        for (auto& w:words) trie.insert(w);

        dfs(res, output, trie, len);
        return res;
    }
private:
    void dfs(vector<vector<string>>& res, vector<string>& output, Trie& trie, int len) {
        if (output.size()==len) {
            res.push_back(output);
            return;
        }
        
        string prefix;
        int n=output.size();
        for (int i=0; i<n; ++i) prefix+=output[i][n];

        vector<string> prefixes=trie.findPrefix(prefix);
        for (auto& p:prefixes) {
            output.push_back(p);
            dfs(res, output, trie, len);
            output.pop_back();
        }
    }
};

2. Hashmap
class Solution {
public:
    void dfs(vector<vector<string>>& res, unordered_map<string, vector<string>>& mp, vector<string>& output, int len) {
        if (output.size()==len) {
            res.push_back(output);
            return;
        }
        
        string prefix;
        int n=output.size();
        for (int i=0; i<n; i++) prefix+=output[i][n];
        
        vector<string> prefixes=mp[prefix];
        for (auto& p:prefixes) {
            output.push_back(p);
            dfs(res, mp, output, len);
            output.pop_back();
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;
        if (words.empty()) return res;
        int len=words[0].size();
        unordered_map<string, vector<string>> mp;
        for (auto& w:words) {
            for (int i=0; i<w.size(); i++) {
                mp[w.substr(0,i)].push_back(w);
            }
        }
        vector<string> output;
        dfs(res, mp, output, len);    

        return res;
    }
};

