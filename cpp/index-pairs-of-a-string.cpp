1065. Index Pairs of a String
Easy

41

32

Favorite

Share
Given a text string and words (a list of strings), return all index pairs [i, j] so that the substring text[i]...text[j] is in the list of words.

 

Example 1:

Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
Output: [[3,7],[9,13],[10,17]]
Example 2:

Input: text = "ababa", words = ["aba","ab"]
Output: [[0,1],[0,2],[2,3],[2,4]]
Explanation: 
Notice that matches can overlap, see "aba" is found in [0,2] and [2,4].
 

Note:

All strings contains only lowercase English letters.
It's guaranteed that all strings in words are different.
1 <= text.length <= 100
1 <= words.length <= 20
1 <= words[i].length <= 50
Return the pairs [i,j] in sorted order (i.e. sort them by their first coordinate in case of ties sort them by their second coordinate).

Amazon
|
LeetCode

struct TrieNode {
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode():isWord(false) {}
};

class Trie {
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* n=root;
        for (int i=0; i<word.size(); ++i) {
            if (n->children.find(word[i])==n->children.end()) n->children[word[i]]=new TrieNode();
            n=n->children[word[i]];
        }
        n->isWord=true;
    }
    
    void search(vector<vector<int>>& res, string& s, int start, int end) {
        TrieNode* n=root;
        for (int i=start; i<=end; ++i) {
            if (n->children.find(s[i])==n->children.end()) break;
            n=n->children[s[i]];
            if (n->isWord) res.push_back({start, i});
        }
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> res;
        int maxLen=0, n=text.size();
        Trie trie;
        for (auto& w:words) {
            maxLen=max(maxLen, (int)w.size());
            trie.insert(w);
        }
        
        for (int i=0; i<n; ++i) {
            trie.search(res, text, i, i+maxLen-1);
        }
        
        return res;
    }
};

