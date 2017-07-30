648. Replace Words
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000

class Solution {
public:
    struct TrieNode {
        unordered_map<char,TrieNode*> children;
        bool isWord;
        TrieNode():isWord(false) {}
    };
    
    class Trie {
    public:
        Trie() {
            root=new TrieNode();
        }
        
        void insert(string word) {
            TrieNode *n=root;
            for (int i=0; i<word.size(); i++) {
                if (n->children.find(word[i])==n->children.end()) {
                    n->children[word[i]]=new TrieNode();
                }
                n=n->children[word[i]];
            }
            n->isWord=true;
        }
        
        string search(string word) {
            string res;
            TrieNode *n=root;
            for (int i=0; i<word.size(); i++) {
                if (n->children.find(word[i])==n->children.end()) return "";
                n=n->children[word[i]];
                res+=word[i];
                if (n->isWord) return res;                
            }
            
            return "";
        }
        
        TrieNode *root;
    };
    
    string replaceWords(vector<string>& dict, string sentence) {
        Trie trie;
        for (auto& w:dict) trie.insert(w);
        
        string res;
        istringstream iss(sentence);
        string val;
        while (getline(iss, val, ' ')) {
            string r=trie.search(val);
            if (!res.empty()) res+=" ";
            if (r!="") res+=r;
            else res+=val;
        }
        return res;
    }
};

