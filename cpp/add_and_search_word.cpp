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
    
    TrieNode() {
        isWord=false;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int i;
        TrieNode* n=root;
        for (i=0; i<word.size(); i++) {
            auto iter=n->children.find(word[i]);
            if (iter==n->children.end()) break;
            n=iter->second;
        }
        
        for (; i<word.size(); i++) {
            TrieNode *c=new TrieNode();
            n->children[word[i]]=c;
            n=c;
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

