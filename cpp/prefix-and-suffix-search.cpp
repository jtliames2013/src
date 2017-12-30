745. Prefix and Suffix Search
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given many words, words[i] has weight i.

Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix). It will return the word with given prefix and suffix with maximum weight. If no word exists, return -1.

Examples:
Input:
WordFilter(["apple"])
WordFilter.f("a", "e") // returns 0
WordFilter.f("b", "") // returns -1
Note:
words has length in range [1, 15000].
For each test case, up to words.length queries WordFilter.f may be made.
words[i] has length in range [1, 10].
prefix, suffix have lengths in range [0, 10].
words[i] and prefix, suffix queries consist of lowercase letters only.

1. map
class WordFilter {
public:
    WordFilter(vector<string> words) {
        for (int i=0; i<words.size(); i++) {
            for (int j=0; j<=10 && j<=words[i].size(); j++) {
                for (int k=0; k<=10 && k<=words[i].size(); k++) {
                    mp[words[i].substr(0,j)+"#"+words[i].substr(words[i].size()-k)]=i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string str=prefix+"#"+suffix;
        if (mp.find(str)!=mp.end()) return mp[str];
        return -1;
    }
private:
    unordered_map<string,int> mp;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 *
**/

2. Trie
struct TrieNode {
    vector<int> words;
    unordered_map<char,TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root=new TrieNode();
    }

    void add(string word, int idx) {
        TrieNode *n=root;
        n->words.push_back(idx);
        for (int i=0; i<word.size(); i++) {
            if (n->children.find(word[i])==n->children.end()) {
                n->children[word[i]]=new TrieNode();
            }                
            n=n->children[word[i]];
            n->words.push_back(idx);
        }
    }

    vector<int> find(string prefix) {
        TrieNode *n=root;
        for (int i=0; i<prefix.size(); i++) {
            if (n->children.find(prefix[i])==n->children.end()) return vector<int>();
            n=n->children[prefix[i]];
        }
        return n->words;
    }

    TrieNode *root;
};

class WordFilter {
public:    
    WordFilter(vector<string> words) {
        for (int i=words.size()-1; i>=0; i--) {
            string w=words[i];
            prefixTrie.add(w, i);
            reverse(w.begin(), w.end());
            suffixTrie.add(w, i);
        }        
    }
    
    int f(string prefix, string suffix) {
        vector<int> pw=prefixTrie.find(prefix);
        reverse(suffix.begin(), suffix.end());
        vector<int> sw=suffixTrie.find(suffix);
        int i=0, j=0;
        while (i<pw.size() && j<sw.size()) {
            if (pw[i]==sw[j]) return pw[i];
            else if (pw[i]>sw[j]) i++;
            else j++;
        }
        return -1;
    }
private:
    Trie prefixTrie, suffixTrie;
};

