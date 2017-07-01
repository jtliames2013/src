527. Word Abbreviation
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given an array of n distinct non-empty strings, you need to generate minimal possible abbreviations for every word following rules below.

Begin with the first character and then the number of characters abbreviated, which followed by the last character.
If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
If the abbreviation doesn't make the word shorter, then keep it as original.
Example:
Input: ["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"]
Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
Note:
Both n and the length of each word will not exceed 400.
The length of each word is greater than 1.
The words consist of lowercase English letters only.
The return answers should be in the same order as the original array.

1.
class Solution {
public:    
    string getAbbr(string& s, int p) {
        int n=s.size();
        if (n-p<=2) return s;
        return s.substr(0,p)+to_string(n-p-1)+s.substr(n-1);        
    }
    
    vector<string> wordsAbbreviation(vector<string>& dict) {
        vector<string> res;
        int n=dict.size();
        if (n==0) return res;
        res.resize(n);
        vector<int> prefix(n);
        for (int i=0; i<n; i++) {
            prefix[i]=1;
            res[i]=getAbbr(dict[i], 1);
        }

        for (int i=0; i<n; i++) {
            while (1) {
                unordered_set<int> st;
                for (int j=i+1; j<n; j++) {
                    if (res[i]==res[j]) st.insert(j);
                }
                if (st.empty()) break;
                st.insert(i);
                for (auto k:st) {
                    res[k]=getAbbr(dict[k], prefix[k]);
                    prefix[k]++;
                }
            }
        }
        return res;
    }
};

2. Trie - MLE
class Solution {
public:
    struct TrieNode {
        int cnt;
        unordered_map<char,TrieNode*> children;
        TrieNode():cnt(0) {}
    };
    
    class Trie {
    public:
        Trie() {
            root=new TrieNode();
        }
        
        void insert(string& word) {
            TrieNode* n=root;
            for (int i=0; i<word.size(); i++) {
                if (n->children.find(word[i])==n->children.end()) {
                    TrieNode *c=new TrieNode();
                    n->children[word[i]]=c;
                }
                n->cnt++;
                n=n->children[word[i]];
            }
        }
        
        TrieNode *root;        
    };
    
    string getAbbr(string& s) {
        int n=s.size();
        if (n<=3) return s;
        return s.substr(0,1)+to_string(n-2)+s.substr(n-1);        
    }
    
    vector<string> wordsAbbreviation(vector<string>& dict) {
        vector<string> res;
        if (dict.empty()) return res;
        res.resize(dict.size());
        unordered_map<string, vector<int>> mp;
        for (int i=0; i<dict.size(); i++) {
            string abbr=getAbbr(dict[i]);
            mp[abbr].push_back(i);
        }
        
        for (auto& iter:mp) {
            if (iter.second.size()==1) {
                res[iter.second[0]]=iter.first;
            } else {
                Trie trie;
                for (auto i:iter.second) trie.insert(dict[i]);
                
                for (auto i:iter.second) {
                    TrieNode *n=trie.root;
                    int j=0, len=dict[i].size();
                    while (j<len && n->cnt>1) {
                        n=n->children[dict[i][j]];
                        j++;
                    }
                    if (len-j+1<=3) res[i]=dict[i];
                    else {
                        res[i]=dict[i].substr(0, j)+to_string(len-j-1)+dict[i].substr(len-1);
                    }
                }
            }
        }
        
        return res;
    }
};

