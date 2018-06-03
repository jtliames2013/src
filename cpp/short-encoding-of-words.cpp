820. Short Encoding of Words
DescriptionHintsSubmissionsDiscussSolution
Given a list of words, we may encode it by writing a reference string S and a list of indexes A.

For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5].

Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.

What is the length of the shortest reference string S possible that encodes the given words?

Example:

Input: words = ["time", "me", "bell"]
Output: 10
Explanation: S = "time#bell#" and indexes = [0, 2, 5].
Note:

1 <= words.length <= 2000.
1 <= words[i].length <= 7.
Each word has only lowercase letters.

1.
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int res=0;
        unordered_set<string> st(words.begin(), words.end());
        for (auto& w:words) {
            for (int i=1; i<w.size(); ++i) {
                st.erase(w.substr(i));
            }
        }
        for (auto& s:st) res+=s.size()+1;
        return res;
    }
};

2.
struct TrieNode {
    unordered_map<char, TrieNode*> children;    
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int res=0;
        unordered_map<TrieNode*, int> mp;
        TrieNode* root=new TrieNode();
        for (auto& w:words) {
            TrieNode *n=root;
            for (int i=w.size()-1; i>=0; --i) {
                if (n->children.find(w[i])==n->children.end()) {
                    n->children[w[i]]=new TrieNode();
                }
                n=n->children[w[i]];
            }
            mp[n]=w.size();
        }
        for (auto& p:mp) {
            if (p.first->children.size()==0) res+=p.second+1;
        }
        return res;
    }
};
