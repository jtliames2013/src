1166. Design File System
Medium

50

4

Favorite

Share
You are asked to design a file system which provides two functions:

createPath(path, value): Creates a new path and associates a value to it if possible and returns True. Returns False if the path already exists or its parent path doesn't exist.
get(path): Returns the value associated with a path or returns -1 if the path doesn't exist.
The format of a path is one or more concatenated strings of the form: / followed by one or more lowercase English letters. For example, /leetcode and /leetcode/problems are valid paths while an empty string and / are not.

Implement the two functions.

Please refer to the examples for clarifications.

 

Example 1:

Input: 
["FileSystem","createPath","get"]
[[],["/a",1],["/a"]]
Output: 
[null,true,1]
Explanation: 
FileSystem fileSystem = new FileSystem();

fileSystem.createPath("/a", 1); // return true
fileSystem.get("/a"); // return 1
Example 2:

Input: 
["FileSystem","createPath","createPath","get","createPath","get"]
[[],["/leet",1],["/leet/code",2],["/leet/code"],["/c/d",1],["/c"]]
Output: 
[null,true,true,2,false,-1]
Explanation: 
FileSystem fileSystem = new FileSystem();

fileSystem.createPath("/leet", 1); // return true
fileSystem.createPath("/leet/code", 2); // return true
fileSystem.get("/leet/code"); // return 2
fileSystem.createPath("/c/d", 1); // return false because the parent path "/c" doesn't exist.
fileSystem.get("/c"); // return -1 because this path doesn't exist.
 

Constraints:

The number of calls to the two functions is less than or equal to 10^4 in total.
2 <= path.length <= 100
1 <= value <= 10^9
NOTE: create method has been changed on August 29, 2019 to createPath. Please reset to default code definition to get new method signature.

Airbnb
|
8

1. hashmap
class FileSystem {
public:
    FileSystem() {
        mp[""]=0;
    }
    
    bool createPath(string path, int value) {
        int idx=path.find_last_of('/');
        if (idx==string::npos) return false;
        string parent=path.substr(0, idx);
        if (mp.find(parent)==mp.end() || mp.find(path)!=mp.end()) return false;
        mp[path]=value;
        return true;
    }
    
    int get(string path) {
        if (mp.find(path)==mp.end()) return -1;
        return mp[path];
    }
private:
    unordered_map<string, int> mp;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */

2. trie
struct TrieNode {
    unordered_map<string, TrieNode*> children;
    bool isPath;
    int val;
    TrieNode(int v):val(v), isPath(false) {}
};

class Trie {
public:
    Trie() {
        root=new TrieNode(0);
    }
    
    bool insert(vector<string>& path, int value) {
        TrieNode* n=root;
        int size=path.size();
        for (int i=0; i<size; ++i) {
            if (n->children.find(path[i])==n->children.end()) {
                if (i<size-1) return false;
                n->children[path[i]]=new TrieNode(0);
            } else {
                if (i==size-1) return false;
            }
            n=n->children[path[i]];
        }        
        n->isPath=true;
        n->val=value;
        return true;
    }
    
    int search(vector<string>& path) {
        TrieNode* n=root;
        for (int i=0; i<path.size(); ++i) {
            if (n->children.find(path[i])==n->children.end()) return -1;
            n=n->children[path[i]];
        }
        if (n->isPath==false) return -1;
        return n->val;
    }    
private:    
    TrieNode* root;
};

class FileSystem {
public:
    FileSystem() {

    }
    
    bool createPath(string path, int value) {
        vector<string> v=split(path);
        return trie.insert(v, value);
    }
    
    int get(string path) {
        vector<string> v=split(path);
        return trie.search(v);
    }
private:
    vector<string> split(string path) {
        vector<string> res;
        int n=path.size();
        for (int i=0; i<n; ) {
            if (path[i]=='/') i++;
            else {
                int j=i;
                while (j<n && path[j]!='/') j++;
                res.push_back(path.substr(i, j-i));
                i=j;
            }
        }
        return res;
    }
    
    Trie trie;
};

