336. Palindrome Pairs  
Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Company Tags Google Airbnb
Hide Tags Hash Table String Trie
Hide Similar Problems (M) Longest Palindromic Substring (H) Shortest Palindrome

use set to avoid the case where two words are revert of each other.

1. map
class Solution {
public:
    bool isPalin(string& s) {
        int l=0, r=(int)s.size()-1;    
        while (l<r) {
            if (s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string,int> mp;
        for (int i=0; i<words.size(); i++) mp[words[i]]=i;
        
        for (int i=0; i<words.size(); i++) {
            // skip empty string            
            if (words[i].empty()) continue;

            // abcd
            // left from "" to "abc"
            // right from "abcd" to "d"
            for (int j=0; j<words[i].size(); j++) {
                string left=words[i].substr(0, j);
                string right=words[i].substr(j);
                
                if (isPalin(left)) {
                    string rev=right;
                    reverse(rev.begin(), rev.end());
                    auto iter=mp.find(rev);
                    // note order of index.
                    // if left is empty and if word is palindrome, it'll find the word itself
                    // and we don't want to include it
                    if (iter!=mp.end() && iter->second!=i) res.push_back({iter->second, i});
                }
                
                if (isPalin(right)) {
                    string rev=left;
                    reverse(rev.begin(), rev.end());
                    auto iter=mp.find(rev);
                    // note order of index                    
                    if (iter!=mp.end()) {
                        res.push_back({i, iter->second});
                        // if word is palindrome, "" can be both before or after it                        
                        if (left.empty()) res.push_back({iter->second, i});
                    }
                }
            }
        }
        return res;
    }
};

2. trie
struct TrieNode {
    int index;
    vector<int> idx;
    unordered_map<char, TrieNode*> children;
    TrieNode(): index(-1) {}
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        int n=words.size();
        TrieNode* root=new TrieNode();

        for (int i=0; i<n; ++i) {
            add(root, words[i], i);
        }

        for (int i=0; i<n; ++i) {
            search(res, root, words[i], i);
        }

        return res;
    }
private:
    void add(TrieNode* node, string& word, int index) {
        for (int i=word.size()-1; i>=0; --i) {
            if (node->children.find(word[i])==node->children.end()) node->children[word[i]]=new TrieNode();
            // word index can be a candidate pair if another word
            // reversely match word index suffix
            if (isPalin(word, 0, i)) node->idx.push_back(index);
            node=node->children[word[i]];
        }
        node->idx.push_back(index);
        node->index=index;
    }

    void search(vector<vector<int>>& res, TrieNode* node, string& word, int index) {
        for (int i=0; i<word.size(); ++i) {
            if (node->index>=0 && node->index!=index && isPalin(word, i, word.size()-1)) {
                // word node->index reversely match word index prefix
                res.push_back({index, node->index});
            }
            if (node->children.find(word[i])==node->children.end()) return;
            node=node->children[word[i]];
        }

        for (auto i:node->idx) {
            // word index reversely match word i suffix
            if (i!=index) res.push_back({index, i});
        }
    }

    bool isPalin(string& s, int l, int r) {
        while (l<r) {
            if (s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};

