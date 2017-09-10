676. Implement Magic Dictionary
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Implement a magic directory with buildDict, and search methods.

For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.

Example 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
Note:
You may assume that all the inputs are consist of lowercase letters a-z.
For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test cases. Please see here for more details.

class MagicDictionary {
public:
    struct TrieNode {
        vector<TrieNode*> children;
        bool isWord;
        TrieNode():isWord(false) { children.resize(26); }
    };
    
    /** Initialize your data structure here. */
    MagicDictionary() {
        root=new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto& w:dict) {
            TrieNode *n=root;
            for (int i=0; i<w.size(); i++) {
                int j=w[i]-'a';
                if (n->children[j]==NULL) n->children[j]=new TrieNode();
                n=n->children[j];
            }
            n->isWord=true;
        }
    }
    
    bool search(string& word, TrieNode* node, int start, int modify) {
        if (start==word.size()) return node->isWord && modify==0;
        int j=word[start]-'a';
        if (node->children[j]!=NULL) {
            if (search(word, node->children[j], start+1, modify)) return true;
        }    
        
        if (modify>0) {
            for (int i=0; i<26; i++) {
                if (node->children[i]!=NULL && i!=j) {
                    if (search(word, node->children[i], start+1, modify-1)) return true;
                }
            }
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return search(word, root, 0, 1);
    }
private:
    TrieNode *root;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
