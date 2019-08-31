208. Implement Trie (Prefix Tree) 
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

Hide Company Tags Google Uber Facebook Twitter Microsoft Bloomberg
Hide Tags Design Trie
Hide Similar Problems (M) Add and Search Word - Data structure design

1. unordered_map
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;
    TrieNode() {
        isWord=false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* n=root;
        for (int i=0; i<word.size(); ++i) {
            if (n->children.find(word[i])==n->children.end()) n->children[word[i]]=new TrieNode();
            n=n->children[word[i]];
        }
        n->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* n=root;
        for (int i=0; i<word.size(); ++i) {
            if (n->children.find(word[i])==n->children.end()) return false;
            n=n->children[word[i]];
        }
        return n->isWord==true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* n=root;
        for (int i=0; i<prefix.size(); ++i) {
            if (n->children.find(prefix[i])==n->children.end()) return false;
            n=n->children[prefix[i]];
        }
        return true;        
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

2. vector
class TrieNode {
public:    
    vector<TrieNode*> children;
    bool isWord;
    TrieNode() {        
        isWord=false;
        children.resize(26);
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* n=root;
        for (int i=0; i<word.size(); ++i) {
            if (n->children[word[i]-'a']==NULL) n->children[word[i]-'a']=new TrieNode();
            n=n->children[word[i]-'a'];
        }
        n->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* n=root;
        for (int i=0; i<word.size(); ++i) {
            if (n->children[word[i]-'a']==NULL) return false;
            n=n->children[word[i]-'a'];
        }
        return n->isWord==true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* n=root;
        for (int i=0; i<prefix.size(); ++i) {
            if (n->children[prefix[i]-'a']==NULL) return false;
            n=n->children[prefix[i]-'a'];
        }
        return true;        
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
