1032. Stream of Characters
Hard

170

42

Favorite

Share
Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist
 

Note:

1 <= words.length <= 2000
1 <= words[i].length <= 2000
Words will only consist of lowercase English letters.
Queries will only consist of lowercase English letters.
The number of queries is at most 40000.

struct TrieNode {
    vector<TrieNode*> children;
    bool isWord;
    TrieNode():isWord(false) { children.resize(26); }
};

class Trie {
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *n=root;
        for (int i=word.size()-1; i>=0; --i) {
            if (n->children[word[i]-'a']==NULL) n->children[word[i]-'a']=new TrieNode();
            n=n->children[word[i]-'a'];
        }
        n->isWord=true;
    }
    
    bool search(string word) {
        TrieNode *n=root;
        for (auto& c:word) {
            if (n->children[c-'a']==NULL) return false;            
            n=n->children[c-'a'];
            if (n->isWord) return true;
        }
        return false;
    }    
private:
    TrieNode *root;
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        len=0;
        for (auto& w:words) {            
            trie.insert(w);
            len=max(len, (int)w.size());
        }
    }
    
    bool query(char letter) {
        if (str.size()==len) str.pop_back();
        str=letter+str;
        return trie.search(str);
    }
private:
    Trie trie;
    int len;
    string str;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

