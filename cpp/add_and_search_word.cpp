211. Add and Search Word - Data structure design  QuestionEditorial Solution  My Submissions
Total Accepted: 32714 Total Submissions: 162152 Difficulty: Medium
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

click to show hint.

You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
Subscribe to see which companies asked this question

Hide Tags Backtracking Trie Design
Hide Similar Problems (M) Implement Trie (Prefix Tree)

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;
    
    TrieNode():isWord(false) { }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {        
        TrieNode* n=root;
        for (int i=0; i<word.size(); i++) {
            if (n->children.find(word[i])==n->children.end()) n->children[word[i]]=new TrieNode();
            n=n->children[word[i]];
        }
        n->isWord=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word,  0, root);
    }
private:
    bool search(string& word, int start, TrieNode *n) {
        if (start==word.size()) return n->isWord;
        if (word[start]=='.') {
            for (auto iter:n->children) {
                if (search(word, start+1, iter.second)) return true;
            }
            return false;
        } else {
            auto iter=n->children.find(word[start]);
            if (iter==n->children.end()) return false;
            return search(word, start+1, iter->second);
        }
    }

    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

2.
class WordDictionary {
public:
    struct TrieNode {
        vector<TrieNode*> children;
        bool isWord;
        TrieNode():isWord(false) { children.resize(26); }
    };
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *n=root;
        for (int i=0; i<word.size(); i++) {
            int j=word[i]-'a';
            if (n->children[j]==NULL) n->children[j]=new TrieNode();
            n=n->children[j];
        }
        n->isWord=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root, 0);
    }
    
private:
    bool search(string& word, TrieNode* node, int start) {
        if (start==word.size()) return node->isWord;
        if (word[start]=='.') {
            for (auto c:node->children) {
                if (c!=NULL && search(word, c, start+1)) return true;                
            }
            return false;
        } else {
            int j=word[start]-'a';            
            if (node->children[j]==NULL) return false;
            return search(word, node->children[j], start+1);            
        }
    }
    
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
