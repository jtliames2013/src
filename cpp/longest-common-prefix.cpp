14. Longest Common Prefix  QuestionEditorial Solution  My Submissions
Total Accepted: 114633 Total Submissions: 391271 Difficulty: Easy
Write a function to find the longest common prefix string amongst an array of strings.

Hide Company Tags Yelp
Hide Tags String

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int end=0, i;
        while (end<strs[0].size()) {
            for (i=1; i<strs.size(); ++i) {
                if (strs[i][end]!=strs[0][end]) break;
            }
            if (i<strs.size()) break;
            end++;
        }
        
        return strs[0].substr(0, end);
    }
};

2. Trie
class Solution {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isWord;
        TrieNode():isWord(false) {}
    };
    
    class Trie {
    public:
        Trie() {
            root=new TrieNode();
        }
        void insert(string word) {
            TrieNode* n=root;
            for (int i=0; i<word.size(); i++) {
                if (n->children.find(word[i])==n->children.end()) {
                    n->children[word[i]]=new TrieNode();
                }
                n=n->children[word[i]];
            }
            n->isWord=true;
        }
        
        string getPrefix() {
            string res;
            TrieNode *n=root;
            while (1) {
                if (n->isWord || n->children.size()!=1) break;
                res+=n->children.begin()->first;
                n=n->children.begin()->second;
            }
            
            return res;
        }
        
        TrieNode *root;
    };
    
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for (auto& s:strs) trie.insert(s);
        return trie.getPrefix();
    }
};

