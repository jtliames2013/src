677. Map Sum Pairs
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5

class MapSum {
public:
    struct TrieNode {
        int count;
        unordered_map<char,TrieNode*> children;
        TrieNode(int c):count(c) {}
    };
    
    /** Initialize your data structure here. */
    MapSum() {
        root=new TrieNode(0);
    }
    
    void insert(string key, int val) {
        TrieNode *n=root;
        int delta=val-mp[key];
        for (int i=0; i<key.size(); i++) {
            n->count+=delta;
            if (n->children.find(key[i])==n->children.end()) {
                n->children[key[i]]=new TrieNode(0);
            }
            n=n->children[key[i]];
        }
        n->count+=delta;
        mp[key]=val;
    }
    
    int sum(string prefix) {
        TrieNode *n=root;
        for (int i=0; i<prefix.size(); i++) {
            if (n->children.find(prefix[i])==n->children.end()) return 0;
            n=n->children[prefix[i]];
        }
        return n->count;
    }
private:
    TrieNode *root;
    unordered_map<string, int> mp;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
